#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace sf;

#include "MYCONST.h"
#include "BUTTON.h"

void startscreen() {
    RenderWindow start_window(VideoMode(SROW, SCOL), "My Window");

    Texture StartBg, Button_Start;
    StartBg.loadFromFile("IMAGE/STARTBG.jpg");
    Button_Start.loadFromFile("IMAGE/MINESWEEPER.jpg");

    Sprite StartBg_Sprite, MineButton_Sprite;
    StartBg_Sprite.setTexture(StartBg);
    //MineButton_Sprite.setTexture(MineButton);
    // Make START BUTTON
    ButtonClass StartButton;
    StartButton = ButtonClass(Vector2f(200, 80), Vector2f(300, 200), Button_Start);

    while(start_window.isOpen()) {
        Event event;

        while(start_window.pollEvent(event)) {
            if(event.type == Event::Closed) {
                start_window.close();
            }
        }

        start_window.clear(Color::Black);

        // Draw here
        //Make_StartBG();
        start_window.draw(StartBg_Sprite);


        start_window.draw(StartButton.Rect);

        bool isPress = false;
        while(Mouse::isButtonPressed(Mouse::Left)) isPress = true;

        if(isPress == true)
        {
            StartButton.Rect.setFillColor(Color::Red);
        }
        // MAKE SCORE
        // MAKE INSTRUCTION

        // Display
        start_window.display();
    }
}
