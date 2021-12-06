#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace sf;

#include "MYCONST.h"
#include "BUTTON.h"
#include "MOUSE.h"

void Startscreen() {
    // Make the window
    RenderWindow start_window(VideoMode(SROW, SCOL), "My Window");

    // Create background
    Texture StartBg;
    StartBg.loadFromFile("IMAGE/STARTBG.jpg");
    Sprite StartBg_Sprite;
    StartBg_Sprite.setTexture(StartBg);

    // NewGame Image
    Texture NewGame;
    NewGame.loadFromFile("IMAGE/MINESWEEPER.jpg");
    ButtonClass NewGame_Button;
    NewGame_Button = ButtonClass(Vector2f(200, 60), Vector2f(300, 200), NewGame);

    // LoadGame Image
    Texture LoadGame;
    LoadGame.loadFromFile("IMAGE/MINESWEEPER.jpg");
    ButtonClass LoadGame_Button(Vector2f(200, 60), Vector2f(300, 280), LoadGame);

    // LeaderBoard
    Texture LeaderBoard;
    LeaderBoard.loadFromFile("IMAGE/MINESWEEPER.jpg");
    ButtonClass LeaderBoard_Button(Vector2f(200, 60), Vector2f(300, 360), LeaderBoard);

    // Instruction
    Texture Instruction;
    Instruction.loadFromFile("IMAGE/MINESWEEPER.jpg");
    ButtonClass Instruction_Button(Vector2f(200, 60), Vector2f(300, 440), Instruction);

    // Author
    Texture Author;
    Author.loadFromFile("IMAGE/MINESWEEPER.jpg");
    ButtonClass Author_Button(Vector2f(200, 60), Vector2f(300, 520), Author);

    while(start_window.isOpen()) {
        Event event;

        // Close the window
        while(start_window.pollEvent(event)) {
            if(event.type == Event::Closed) {
                start_window.close();
            }
        }

        start_window.clear(Color::Black);

        // Draw here

        //Make_Background;
        start_window.draw(StartBg_Sprite);

        // Make NewGame button
        start_window.draw(NewGame_Button.Rect);

        // Make LoadGame button
        start_window.draw(LoadGame_Button.Rect);

        // MAKE LeaderBoard
        start_window.draw(LeaderBoard_Button.Rect);

        // MAKE INSTRUCTION
        start_window.draw(Instruction_Button.Rect);

        // Make Author
        start_window.draw(Author_Button.Rect);

        // Into NewGame Button

        // Display
        start_window.display();
    }
}
