/*
Vector2f Position = Ingame_Window.mapPixelToCoords(Mouse::getPosition(Ingame_Window));

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(isLose) {
                    Board[i][j] = State[i][j];
                }
                Texture Cell;
                string Image = "IMAGE/CELL_" + to_string(Board[i][j]) + ".png";
                Cell.loadFromFile(Image);
                Cell_Class Cell_Button(Vector2f(32, 32), Vector2f(i * 32, j * 32), Cell);

                Ingame_Window.draw(Cell_Button.Rect);
                if(isLose) continue;
                //cout << Position.x << ' ' << Position.y << endl;

                int Type = Cell_Button.is_Clicked(Position);

                if(Type == 1) {
                    if(Board[i][j] == 10) {
                        Board[i][j] = State[i][j];
                    }

                    if(Board[i][j] == 9) {
                        cout << "CONCHOHOANG\n";
                        isLose = true;
                    }
                }

                if(Type == 2) {
                    if(Board[i][j] == 11) {
                        Board[i][j] = 10;
                    }
                    else Board[i][j] = 11;
                }

                //Ingame_Window.draw(Cell_Button.Rect);
            }
        }
        */
