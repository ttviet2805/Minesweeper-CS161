#include "INGAME_INSTRUCTION.h"

void Ingame_Instruction_Screen() {
    // create the window
    RenderWindow window(sf::VideoMode(800, 600), "INSTRUCTION");

    Texture Ins;
    Ins.loadFromFile("IMAGE/INSTRUCTION_INGAME.png");
    Sprite InsSprite;
    InsSprite.setTexture(Ins);

    // Make back Button
    Texture Back_Texture;
    Back_Texture.loadFromFile("IMAGE/BACK_BUTTON.png");
    ButtonClass Back_Button(Vector2f(50, 50), Vector2f(10, 10), Back_Texture);

     // Make next Button
    Texture Next_texture;
    Next_texture.loadFromFile("IMAGE/NEXT.png");
    ButtonClass Next_Button(Vector2f(50, 50), Vector2f(740, 540), Next_texture);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(InsSprite);

        Vector2f Position = window.mapPixelToCoords(Mouse::getPosition(window));

        window.draw(Back_Button.Rect);
        int Back_val = Back_Button.is_Clicked(Position);
        if(Back_val == 1) {
            window.close();
            NewGame_Screen();
        }
        else {
            if(Back_val == 2) Back_Button.Rect.setFillColor(Color::Red);
            if(Back_val == 0) Back_Button.Rect.setFillColor(Color::White);
        }

        window.draw(Next_Button.Rect);
        int Next_val = Next_Button.is_Clicked(Position);
        if(Next_val == 1) {
            window.close();
            Extra_Ingame_Instruction_Screen();
        }
        else {
            if(Next_val == 2) Next_Button.Rect.setFillColor(Color::Green);
            if(Next_val == 0) Next_Button.Rect.setFillColor(Color::White);
        }

        // end the current frame
        window.display();
    }
}
