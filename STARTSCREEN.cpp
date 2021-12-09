#include "STARTSCREEN.h"

void Startscreen() {
    // Make the window
    RenderWindow start_window(VideoMode(Startscreen_Col, Startscreen_Row), "My Window");

    // Create background
    Texture StartBg;
    StartBg.loadFromFile("IMAGE/STARTBG.jpg");
    Sprite StartBg_Sprite;
    StartBg_Sprite.setTexture(StartBg);

    // NewGame Image
    Texture NewGame;
    NewGame.loadFromFile("IMAGE/NEWGAME.png");
    ButtonClass NewGame_Button;
    NewGame_Button = ButtonClass(Vector2f(Button_Col, Button_Row), Vector2f(300, 200), NewGame);

    // LoadGame Image
    Texture LoadGame;
    LoadGame.loadFromFile("IMAGE/LOADGAME.png");
    ButtonClass LoadGame_Button(Vector2f(Button_Col, Button_Row), Vector2f(300, 280), LoadGame);

    // LeaderBoard
    Texture LeaderBoard;
    LeaderBoard.loadFromFile("IMAGE/LEADERBOARD.png");
    ButtonClass LeaderBoard_Button(Vector2f(Button_Col, Button_Row), Vector2f(300, 360), LeaderBoard);

    // Instruction
    Texture Instruction;
    Instruction.loadFromFile("IMAGE/INSTRUCTION.png");
    ButtonClass Instruction_Button(Vector2f(Button_Col, Button_Row), Vector2f(300, 440), Instruction);

    // Author
    Texture Author;
    Author.loadFromFile("IMAGE/AUTHOR.png");
    ButtonClass Author_Button(Vector2f(Button_Col, Button_Row), Vector2f(300, 520), Author);

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
        bool isPress = false;

        while(Mouse::isButtonPressed(Mouse::Left)) isPress = true;

        Vector2f Position = start_window.mapPixelToCoords(Mouse::getPosition(start_window));

        if(isPress) {
            if(NewGame_Button.Rect.getGlobalBounds().contains(Position)) {
                // Go into Select Difficulty Screen
                //NewGame_Screen();
                Select_Difficulty_Screen();
                start_window.close();
            }
        }

        // Into LoadGame Button

        // Display
        start_window.display();
    }
}
