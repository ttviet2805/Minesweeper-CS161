#include "AUTHOR_SCREEN.h"

void Author_Screen() {
    // create the window
    RenderWindow window(sf::VideoMode(800, 600), "AUTHOR");

    Texture Author;
    Author.loadFromFile("IMAGE/AUTHOR_INGAME.png");
    Sprite AuthorSprite;
    AuthorSprite.setTexture(Author);;

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
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(AuthorSprite);

        Vector2f Position = window.mapPixelToCoords(Mouse::getPosition(window));

        window.draw(Back_Button.Rect);
        int Back_val = Back_Button.is_Clicked(Position);
        if(Back_val == 1) {
            window.close();
            Startscreen();
        }
        else {
            if(Back_val == 2) Back_Button.Rect.setFillColor(Color::Red);
            if(Back_val == 0) Back_Button.Rect.setFillColor(Color::White);
        }

        // end the current frame
        window.display();
    }
}

