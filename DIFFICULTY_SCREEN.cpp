#include "DIFFICULTY_SCREEN.h"

void Select_Difficulty_Screen() {
    // Make Background
    Texture Background;
    Background.loadFromFile("IMAGE/DIFFICULTY_BG.jpg");
    Sprite Background_Sprite;
    Background_Sprite.setTexture(Background);

    // Make Select Difficulty
    Texture Select;
    Select.loadFromFile("IMAGE/SELECT_DIFFICULTY.png");
    ButtonClass Select_Button(Vector2f(400, 60), Vector2f(200, 60), Select);

    // Make beginner Button
    Texture Beginner_Text;
    Beginner_Text.loadFromFile("IMAGE/BEGINNER.png");
    ButtonClass Beginner_Button(Vector2f(Difficulty_Col, Difficulty_Row), Vector2f(300, 120), Beginner_Text);

    // Make Intermediate Button
    Texture Intermediate_Text;
    Intermediate_Text.loadFromFile("IMAGE/Intermediate.png");
    ButtonClass Intermediate_Button(Vector2f(Difficulty_Col, Difficulty_Row), Vector2f(300, 220), Intermediate_Text);

    // Make Expert Button
    Texture Expert_Text;
    Expert_Text.loadFromFile("IMAGE/EXPERT.png");
    ButtonClass Expert_Button(Vector2f(Difficulty_Col, Difficulty_Row), Vector2f(300, 360), Expert_Text);

    // Make the window
    RenderWindow Difficulty_Window(VideoMode(Startscreen_Col, Startscreen_Row), "MINESWEEPER");

    while(Difficulty_Window.isOpen()) {
        Event event;
        while(Difficulty_Window.pollEvent(event)) {
            if(event.type == Event::Closed)
                Difficulty_Window.close();
        }

        Difficulty_Window.clear(Color::Black);

        //draw here

        // draw Background
        Difficulty_Window.draw(Background_Sprite);

        //draw Select Difficulty
        Difficulty_Window.draw(Select_Button.Rect);


        Vector2f Position = Difficulty_Window.mapPixelToCoords(Mouse::getPosition(Difficulty_Window));
        // draw beginner button
        int val = Beginner_Button.is_Clicked(Position);

        if(val == 2) Beginner_Button.Rect.setFillColor(Color::Red);
        if(val == 0) Beginner_Button.Rect.setFillColor(Color::White);
        if(val == 1) {
            NewGame_Screen(1);
            Difficulty_Window.close();
        }

        Difficulty_Window.draw(Beginner_Button.Rect);

        // draw Intermediate button
        val = Intermediate_Button.is_Clicked(Position);

        if(val == 2) Intermediate_Button.Rect.setFillColor(Color::Red);
        if(val == 0) Intermediate_Button.Rect.setFillColor(Color::White);
        if(val == 1) {
            NewGame_Screen(2);
            Difficulty_Window.close();
        }

        Difficulty_Window.draw(Intermediate_Button.Rect);

        // draw Expert button
        val = Expert_Button.is_Clicked(Position);

        if(val == 2) Expert_Button.Rect.setFillColor(Color::Green);
        if(val == 0) Expert_Button.Rect.setFillColor(Color::White);
        if(val == 1) {
            NewGame_Screen(3);
            Difficulty_Window.close();
        }

        Difficulty_Window.draw(Expert_Button.Rect);

        Difficulty_Window.display();
    }
}
