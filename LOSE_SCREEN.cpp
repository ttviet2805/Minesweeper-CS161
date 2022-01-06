#include "WIN_SCREEN.h"

void Lose_Screen() {
    RenderWindow window(sf::VideoMode(800, 600), "My window");

    Texture Background;
    Background.loadFromFile("IMAGE/LOSE.jpg");
    Sprite Background_Sprite;
    Background_Sprite.setTexture(Background);

    // NewGame Button
    Texture NewGame;
    NewGame.loadFromFile("IMAGE/NEWGAME_WIN.png");
    ButtonClass NewGame_Button(Vector2f(300, 100), Vector2f(50, 450), NewGame);

    //Menu Button
    Texture Menu;
    Menu.loadFromFile("IMAGE/MENU.png");
    ButtonClass Menu_Button(Vector2f(300, 100), Vector2f(450, 450), Menu);

    ifstream fin;
    fin.open("GAME_STATE.txt");
    int type, Row, Col, numMine;
    fin >> type;
    fin >> Row >> Col >> numMine;
    fin.close();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(Background_Sprite);

        window.draw(NewGame_Button.Rect);
        window.draw(Menu_Button.Rect);

        Vector2f Position = window.mapPixelToCoords(Mouse::getPosition(window));

        int Menu_val = Menu_Button.is_Clicked(Position);
        if(Menu_val == 1) {
            Delete_Data();
            window.close();
            Startscreen();
        }
        else {
            if(Menu_val == 2) Menu_Button.Rect.setFillColor(Color::Green);
            if(Menu_val == 0) Menu_Button.Rect.setFillColor(Color::White);
        }

        int NewGame_val = NewGame_Button.is_Clicked(Position);
        if(NewGame_val == 1) {
            window.close();

            if(type == 4) Put_Custom(Row, Col, numMine);
            else Put_txtFile(type);
            NewGame_Screen();
        }
        else {
            if(NewGame_val == 2) NewGame_Button.Rect.setFillColor(Color::Green);
            if(NewGame_val == 0) NewGame_Button.Rect.setFillColor(Color::White);
        }

        // end the current frame
        window.display();
    }

}

