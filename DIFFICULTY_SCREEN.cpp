#include "DIFFICULTY_SCREEN.h"

void Select_Difficulty_Screen() {
    // Make beginner Button
    Texture Beginner_Text;
    Beginner_Text.loadFromFile("IMAGE/CELL_1.png");
    ButtonClass Beginner_Button(Vector2f(Difficulty_Col, Difficulty_Row), Vector2f(300, 80), Beginner_Text);

    // Make Medium Button
    Texture Medium_Text;
    Medium_Text.loadFromFile("IMAGE/CELL_2.png");
    ButtonClass Medium_Button(Vector2f(Difficulty_Col, Difficulty_Row), Vector2f(300, 220), Medium_Text);

    // Make Expert Button
    Texture Expert_Text;
    Expert_Text.loadFromFile("IMAGE/CELL_3.png");
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

        Vector2f Position = Difficulty_Window.mapPixelToCoords(Mouse::getPosition(Difficulty_Window));
        // draw beginner button
        int val = Beginner_Button.is_Clicked(Position);

        if(val == 2) Beginner_Button.Rect.setFillColor(Color::Black);
        if(val == 0) Beginner_Button.Rect.setFillColor(Color::White);
        if(val == 1) {
            NewGame_Screen(1);
            Difficulty_Window.close();
        }

        Difficulty_Window.draw(Beginner_Button.Rect);

        // draw medium button
        Difficulty_Window.draw(Medium_Button.Rect);

        // draw Expert button
        Difficulty_Window.draw(Expert_Button.Rect);

        Difficulty_Window.display();
    }
}
