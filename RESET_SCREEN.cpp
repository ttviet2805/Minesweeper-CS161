#include "RESET_SCREEN.h"

void Reset_Screen() {
    RenderWindow window(sf::VideoMode(600, 400), "MINESWEEPER");

    Texture Background;
    Background.loadFromFile("IMAGE/RESET_BG.jpg");
    Sprite Bg_Sprite;
    Bg_Sprite.setTexture(Background);

    Reset_LeaderBoard();

    // Make back Button
    Texture Back_Texture;
    Back_Texture.loadFromFile("IMAGE/BACK_BUTTON.png");
    ButtonClass Back_Button(Vector2f(50, 50), Vector2f(10, 10), Back_Texture);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed) {
                window.close();
                LeaderBoard_Screen();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(Bg_Sprite);

        Vector2f Position = window.mapPixelToCoords(Mouse::getPosition(window));

        window.draw(Back_Button.Rect);

        int Back_val = Back_Button.is_Clicked(Position);
        if(Back_val == 1) {
            window.close();
            LeaderBoard_Screen();
        }
        else {
            if(Back_val == 2) Back_Button.Rect.setFillColor(Color::Red);
            if(Back_val == 0) Back_Button.Rect.setFillColor(Color::White);
        }

        window.display();
    }
}
