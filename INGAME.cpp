#include "INGAME.h"

bool checkWin(int Row, int Col, bool &isLose, int Board[41][41], int State[41][41])
{
    for(int i = 0; i < Row; i++)
    {
        for(int j = 0; j < Col; j++)
        {
            if(isLose) return false;
            if(State[i][j] == 9) continue;

            if(Board[i][j] == 10) return false;
            if(Board[i][j] == 11 && State[i][j] != 9) return false;
        }
    }

    return true;
}

int check_Open(int Row, int Col, int u, int v, int Board[41][41], int State[41][41])
{
    int numFlag = 0;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int nu = u + i, nv = v + j;
            if(nu < 0 || nu >= Row || nv < 0 || nv >= Col) continue;

            if(Board[nu][nv] == 11) numFlag++;
        }
    }

    if(numFlag != State[u][v]) return 0;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int nu = u + i, nv = v + j;
            if(nu < 0 || nu >= Row || nv < 0 || nv >= Col) continue;

            if(State[nu][nv] == 9 && Board[nu][nv] != 11) return -1;
            if(State[nu][nv] != 9 && Board[nu][nv] == 11) return -1;
        }
    }

    return 1;
}

void dfs(int i, int j, int Row, int Col, bool vs[41][41], int Board[41][41], int State[41][41])
{
    vs[i][j] = true;
    Board[i][j] = State[i][j];
    if(State[i][j] != 0) return;

    for(int u = -1; u <= 1; u++) for(int v = -1; v <= 1; v++)
        {
            int ni = i + u, nj = j + v;
            if(ni < 0 || ni >= Row || nj < 0 || nj >= Col) continue;

            if(vs[ni][nj]) continue;

            dfs(ni, nj, Row, Col, vs, Board, State);
        }
}


void NewGame_Screen()
{
    // Make Newgame_Screen
    RenderWindow Ingame_Window(VideoMode(Ingame_Col, Ingame_Row), "MINESWEEPER");

    // Make back Button
    Texture Back_Texture;
    Back_Texture.loadFromFile("IMAGE/BACK_BUTTON.png");
    ButtonClass Back_Button(Vector2f(50, 50), Vector2f(10, 10), Back_Texture);

    // Background Texture
    Texture Background;
    Background.loadFromFile("IMAGE/INGAME_BG.jpg");
    Sprite Background_Sprite;
    Background_Sprite.setTexture(Background);

    // Make SaveGame button
    Texture Instruction_Texture;
    Instruction_Texture.loadFromFile("IMAGE/INSTRUCTION.png");
    ButtonClass Instruction_Button(Vector2f(150, 70), Vector2f(425, 20), Instruction_Texture);

    int State[41][41], Board[41][41];
    bool vs[41][41];

    // Get from TXT file
    ifstream fin;
    fin.open("GAME_STATE.txt");

    int type, numMine, current_Time, Row, Col;
    fin >> type >> Row >> Col >> numMine >> current_Time;

    //cout << numMine << ' ' << Row << ' ' << Col << ' ' << current_Time << '\n';

    for(int i = 0; i < Row; i++)
    {
        for(int j = 0; j < Col; j++)
        {
            fin >> Board[i][j];
            //cout << Board[i][j] << ' ';
        }

        //cout << '\n';
    }

    fin.get();

    for(int i = 0; i < Row; i++)
    {
        for(int j = 0; j < Col; j++)
            fin >> State[i][j];
    }

    fin.close();

    memset(vs, false, sizeof(vs));
    bool isLose = false;

    Texture Cell_Text[12];

    for(int i = 0; i <= 11; i++)
    {
        string Image = "IMAGE/CELL_" + to_string(i) + ".png";
        Cell_Text[i].loadFromFile(Image);
    }

    // Time
    Clock clock, Break_Time;

    clock.restart();
    Text Clock_Text;
    Font font;
    font.loadFromFile("Game_Font/AppleII.ttf");

    Clock_Text.setFont(font); // font is a sf::Font

    // set the string to display
    Clock_Text.setString("Hello world");

    // set the character size
    Clock_Text.setCharacterSize(35); // in pixels, not points!

    // set the color
    Clock_Text.setFillColor(Color::Green);

    // set the text style
    Clock_Text.setStyle(Text::Bold);

    Clock_Text.setPosition(Vector2f(750, 20));

    while(Ingame_Window.isOpen())
    {
        Time elapse = clock.getElapsedTime();

        int cur_Time = current_Time + elapse.asSeconds();

        //cout << cur_Time << endl;
        // To string
        string clock_string = "Time: " + to_string(cur_Time);

        Clock_Text.setString(clock_string);

        Event event;
        //Ingame_Window.draw(text);

        // Close the window
        while(Ingame_Window.pollEvent(event))
        {
            if(event.type == Event::Closed) {
                Save_txtFile(type, Row, Col, numMine, cur_Time, Board, State);
                Ingame_Window.close();
            }
        }

        Ingame_Window.clear(Color::Black);

        //draw here
        Ingame_Window.draw(Background_Sprite);
        Ingame_Window.draw(Clock_Text);

        // draw Back Button
        Vector2f Position = Ingame_Window.mapPixelToCoords(Mouse::getPosition(Ingame_Window));

        Ingame_Window.draw(Back_Button.Rect);
        int Back_val = Back_Button.is_Clicked(Position);
        if(Back_val == 1)
        {
            Save_txtFile(type, Row, Col, numMine, cur_Time, Board, State);
            Ingame_Window.close();
            Startscreen();
        }
        else
        {
            if(Back_val == 2) Back_Button.Rect.setFillColor(Color::Red);
            if(Back_val == 0) Back_Button.Rect.setFillColor(Color::White);
        }

        // Draw Board
        if(checkWin(Row, Col, isLose, Board, State))
        {
            if(type != 4) Change_LeaderBoard(type, cur_Time);
            Ingame_Window.close();
            Win_Screen();
            cout << "Win\n";
            exit(0);
        }

        if(isLose)
        {
            Ingame_Window.close();
            Lose_Screen();
            cout << "Lose\n";
            exit(0);
        }

        // Solve Instruction
        Ingame_Window.draw(Instruction_Button.Rect);
        int Instruction_val = Instruction_Button.is_Clicked(Position);
        if(Instruction_val == 1)
        {
            Save_txtFile(type, Row, Col, numMine, cur_Time, Board, State);
            Ingame_Window.close();
            Ingame_Instruction_Screen();
        }
        else
        {
            if(Instruction_val == 2) Instruction_Button.Rect.setFillColor(Color::Red);
            else Instruction_Button.Rect.setFillColor(Color::White);
        }

        // Solve Game
        for(int i = 0; i < Row; i++)
        {
            for(int j = 0; j < Col; j++)
            {
                int Pos_Col = Ingame_Col / 2 - Col * 16, Pos_Row = Ingame_Row / 2 - Row * 16;
                Cell_Class Cell_Button(Vector2f(Cell_Col, Cell_Row), Vector2f(j * Cell_Col + Pos_Col, i * Cell_Row + Pos_Row), Cell_Text[Board[i][j]]);

                if(isLose)
                {
                    continue;
                }

                int val = Cell_Button.is_Clicked(Position);

                if(val == 1 && Board[i][j] == 10)
                {
                    Board[i][j] = State[i][j];

                    if(Board[i][j] == 9)
                    {
                        isLose = true;
                    }
                    if(Board[i][j] != 10)
                    {
                        dfs(i, j, Row, Col, vs, Board, State);
                    }
                }
                else
                {
                    if(val == 1 && 1 <= Board[i][j] && Board[i][j] <= 8)
                    {
                        int isOpen = check_Open(Row, Col, i, j, Board, State);

                        if(isOpen == -1) isLose = true;
                        else
                        {
                            if(isOpen == 1) {
                                for(int u = -1; u <= 1; u++) for(int v = -1; v <= 1; v++)
                                {
                                    int ni = i + u, nj = j + v;
                                    if(ni < 0 || ni >= Row || nj < 0 || nj >= Col) continue;

                                    if(vs[ni][nj]) continue;
                                    if(State[ni][nj] == 9) continue;

                                    dfs(ni, nj, Row, Col, vs, Board, State);
                                }
                            }
                        }
                    }
                }

                if(val == 2)
                {
                    if(Board[i][j] == 10) Board[i][j] = 11;
                    else
                    {
                        if(Board[i][j] == 11) Board[i][j] = 10;
                    }
                }

                Ingame_Window.draw(Cell_Button.Rect);
            }
        }

        Ingame_Window.display();
    }
}
