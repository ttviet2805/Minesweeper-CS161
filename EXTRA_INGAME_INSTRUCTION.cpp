#include "EXTRA_INSTRUCTION.h"

void Extra_Ingame_Instruction_Screen() {
    // create the window
    RenderWindow window(sf::VideoMode(800, 600), "INSTRUCTION");

    Texture Ins;
    Ins.loadFromFile("IMAGE/EXTRA_INSTRUCTION.png");
    Sprite InsSprite;
    InsSprite.setTexture(Ins);

    // Make back Button
    Texture Back_Texture;
    Back_Texture.loadFromFile("IMAGE/BACK_BUTTON.png");
    ButtonClass Back_Button(Vector2f(50, 50), Vector2f(10, 10), Back_Texture);

     // Make next Button
    Texture Prev_texture;
    Prev_texture.loadFromFile("IMAGE/PREVIOUS.png");
    ButtonClass Prev_Button(Vector2f(50, 50), Vector2f(10, 540), Prev_texture);

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

        window.draw(Prev_Button.Rect);
        int Prev_val = Prev_Button.is_Clicked(Position);
        if(Prev_val == 1) {
            window.close();
            Ingame_Instruction_Screen();
        }
        else {
            if(Prev_val == 2) Prev_Button.Rect.setFillColor(Color::Green);
            if(Prev_val == 0) Prev_Button.Rect.setFillColor(Color::White);
        }

        // end the current frame
        window.display();
    }
}


