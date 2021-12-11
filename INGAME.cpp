#include "INGAME.h"

const int N = 105;
int State[N][N], Board[N][N];
bool vs[N][N];
bool isLose;

bool checkWin() {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			if(isLose) return false;
			if(State[i][j] == 9) continue;

			if(Board[i][j] == 10) return false;
		}
	}

	return true;
}

void dfs(int i, int j) {
	vs[i][j] = true;
	Board[i][j] = State[i][j];
	if(State[i][j] != 0) return;

	for(int u = -1; u <= 1; u++) for(int v = -1; v <= 1; v++) {
		int ni = i + u, nj = j + v;
		if(ni < 0 || ni >= 9 || nj < 0 || nj >= 9) continue;

		if(vs[ni][nj]) continue;

		dfs(ni, nj);
	}
}

void NewGame_Screen(int type) {
    // Make Newgame_Screen
    RenderWindow Ingame_Window(VideoMode(Ingame_Col, Ingame_Row), "MINESWEEPER");

    // Background Texture
    Texture Background;
    Background.loadFromFile("IMAGE/INGAME_BG.jpg");
    Sprite Background_Sprite;
    Background_Sprite.setTexture(Background);

    // Make state for Board
    int numMine = 0, numBomb = 0;
    if(type == 1) numMine = Num_Mine_Beginner, numBomb = 10;
    if(type == 2) numMine = Num_Mine_Intermediate, numBomb = 20;
    if(type == 3) numMine = Num_Mine_Expert, numBomb = 30;

    Build_Game(numMine, numBomb, State, Board);
    memset(vs, false, sizeof(vs));
    isLose = false;

    Texture Cell_Text[12];

    for(int i = 0; i <= 11; i++) {
        string Image = "IMAGE/CELL_" + to_string(i) + ".png";
        Cell_Text[i].loadFromFile(Image);
    }

    while(Ingame_Window.isOpen()) {
        Event event;

        // Close the window
        while(Ingame_Window.pollEvent(event)) {
            if(event.type == Event::Closed)
                Ingame_Window.close();
        }

        Ingame_Window.clear(Color::Black);

        //draw here
        Ingame_Window.draw(Background_Sprite);

        // Draw Board
        if(checkWin()) {
            cout << "Win\n";
            exit(0);
        }

        if(isLose) {
            cout << "Lose\n";
            exit(0);
        }

        Vector2f Position = Ingame_Window.mapPixelToCoords(Mouse::getPosition(Ingame_Window));

        for(int i = 0; i < numMine; i++) {
            for(int j = 0; j < numMine; j++) {
                Cell_Class Cell_Button(Vector2f(Cell_Col, Cell_Row), Vector2f(i * Cell_Col, j * Cell_Row), Cell_Text[Board[i][j]]);

                if(isLose) {
                    Board[i][j] = State[i][j];
                    Cell_Class Cell_Button(Vector2f(Cell_Col, Cell_Row), Vector2f(i * Cell_Col, j * Cell_Row), Cell_Text[Board[i][j]]);

                    Ingame_Window.draw(Cell_Button.Rect);
                    continue;
                }

                int val = Cell_Button.is_Clicked(Position);

                if(val == 1 && Board[i][j] == 10) {
                    Board[i][j] = State[i][j];

                    if(Board[i][j] == 9) {
                        isLose = true;
                    }
                    if(Board[i][j] != 10) {
                        dfs(i, j);
                    }
                }

                if(val == 2) {
                    if(Board[i][j] == 10) Board[i][j] = 11;
                    else Board[i][j] = 10;
                }

                Ingame_Window.draw(Cell_Button.Rect);
            }
        }

        Ingame_Window.display();
    }
}
