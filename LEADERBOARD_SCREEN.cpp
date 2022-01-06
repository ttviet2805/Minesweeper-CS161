#include "LEADERBOARD_SCREEN.h"

void LeaderBoard_Screen() {
    // create the window
    RenderWindow LeaderBoard_window(VideoMode(800, 600), "LEADERBOARD");

    Texture Background;
    Background.loadFromFile("IMAGE/LEADERBOARD_BG.jpg");
    Sprite Background_Sprite;
    Background_Sprite.setTexture(Background);

    Texture LeaderBoard;
    LeaderBoard.loadFromFile("IMAGE/LEADERBOARD_TEXT.png");
    ButtonClass LeaderBoard_Button(Vector2f(300, 80), Vector2f(250, 40), LeaderBoard);

    // Beginner Text
    Texture Beginner_Text;
    Beginner_Text.loadFromFile("IMAGE/BEGINNER.png");
    ButtonClass Beginner_Button(Vector2f(200, 60), Vector2f(50, 150), Beginner_Text);

    // Make Intermediate Button
    Texture Intermediate_Text;
    Intermediate_Text.loadFromFile("IMAGE/Intermediate.png");
    ButtonClass Intermediate_Button(Vector2f(200, 60), Vector2f(300, 150), Intermediate_Text);

    // Make Expert Button
    Texture Expert_Text;
    Expert_Text.loadFromFile("IMAGE/EXPERT.png");
    ButtonClass Expert_Button(Vector2f(200, 60), Vector2f(550, 150), Expert_Text);

    Texture Score;
    Score.loadFromFile("IMAGE/GREY.png");
    ButtonClass Score_Button[5][5];

    Texture Reset_Text;
    Reset_Text.loadFromFile("IMAGE/RESET.png");
    ButtonClass Reset_Button(Vector2f(120, 45), Vector2f(340, 555), Reset_Text);

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            Score_Button[i][j] = ButtonClass(Vector2f(160, 50), Vector2f(PosX[i], PosY[j]), Score);
        }
    }

    // get the Score in LEADERBOARD.txt
    int a[5][5];
    memset(a, 0, sizeof(a));

    ifstream fin;
    fin.open("GAME_LEADERBOARD.txt");

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            fin >> a[i][j];
        }
    }

    fin.close();

    Text Score_Text[5][5];
    Font font;
    font.loadFromFile("Game_Font/kranky.ttf");

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            Score_Text[i][j].setFont(font);

            string tmp = to_string(a[j][i]);
            if(i == 1) tmp = "1st   " + tmp;
            if(i == 2) tmp = "2nd   " + tmp;
            if(i == 3) tmp = "3rd   " + tmp;

            tmp += "s";
            Score_Text[i][j].setString(tmp);

            // set the character size
            Score_Text[i][j].setCharacterSize(24); // in pixels, not points!

            // set the color
            Score_Text[i][j].setFillColor(Color::White);

            // set the text style

            Score_Text[i][j].setStyle(Text::Bold);

            Score_Text[i][j].setPosition(Vector2f(PosX[j] + 10, PosY[i] + 10));
        }
    }

    // Make back Button
    Texture Back_Texture;
    Back_Texture.loadFromFile("IMAGE/BACK_BUTTON.png");
    ButtonClass Back_Button(Vector2f(50, 50), Vector2f(10, 10), Back_Texture);

    // run the program as long as the window is open
    while (LeaderBoard_window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (LeaderBoard_window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                LeaderBoard_window.close();
        }

        // clear the window with black color
        LeaderBoard_window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        LeaderBoard_window.draw(Background_Sprite);
        LeaderBoard_window.draw(LeaderBoard_Button.Rect);
        LeaderBoard_window.draw(Beginner_Button.Rect);
        LeaderBoard_window.draw(Intermediate_Button.Rect);
        LeaderBoard_window.draw(Expert_Button.Rect);

        // draw Back Button
        Vector2f Position = LeaderBoard_window.mapPixelToCoords(Mouse::getPosition(LeaderBoard_window));

        LeaderBoard_window.draw(Back_Button.Rect);
        int Back_val = Back_Button.is_Clicked(Position);
        if(Back_val == 1) {
            LeaderBoard_window.close();
            Startscreen();
        }
        else {
            if(Back_val == 2) Back_Button.Rect.setFillColor(Color::Red);
            if(Back_val == 0) Back_Button.Rect.setFillColor(Color::White);
        }

        for(int i = 1; i <= 3; i++) {
            for(int j = 1; j <= 3; j++) {
                LeaderBoard_window.draw(Score_Button[i][j].Rect);
            }
        }

        for(int i = 1; i <= 3; i++) {
            for(int j = 1; j <= 3; j++) {
                if(a[j][i] == 0) continue;
                LeaderBoard_window.draw(Score_Text[i][j]);
            }
        }

        LeaderBoard_window.draw(Reset_Button.Rect);

        int Reset_val = Reset_Button.is_Clicked(Position);
        if(Reset_val == 1) {
            LeaderBoard_window.close();
            Reset_Screen();
        }
        else {
            if(Reset_val == 2) Reset_Button.Rect.setFillColor(Color::Green);
            if(Reset_val == 0) Reset_Button.Rect.setFillColor(Color::White);
        }

        // end the current frame
        LeaderBoard_window.display();
    }
}
