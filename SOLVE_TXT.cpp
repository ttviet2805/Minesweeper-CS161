#include "SOLVE_TXT.h"

void Put_txtFile(int type) {
    ofstream fout;
    fout.open("GAME_STATE.txt");

    // Make state for Board
    int numMine = 0, Row, Col;
    if(type == 1) numMine = Num_Mine_Beginner, Row = 9, Col = 9;
    if(type == 2) numMine = Num_Mine_Intermediate, Row = 16, Col = 16;
    if(type == 3) numMine = Num_Mine_Expert, Row = 16, Col = 30;

    int state[41][41], board[41][41];
    Build_Game(Row, Col, numMine, state, board);

    fout << type << '\n';
    fout << Row << ' ' << Col << ' ' << numMine << '\n';
    fout << 0 << '\n';

    for(int i = 0; i < Row; i++) {
        for(int j = 0; j < Col; j++) {
            fout << board[i][j] << ' ';
        }

        fout << '\n';
    }

    fout << '\n';

    for(int i = 0; i < Row; i++) {
        for(int j = 0; j < Col; j++) {
            fout << state[i][j] << ' ';
        }

        fout << '\n';
    }

    fout.close();
}

void Put_Custom(int Row, int Col, int numMine) {
    ofstream fout;
    fout.open("GAME_STATE.txt");

    int state[41][41], board[41][41];
    Build_Game(Row, Col, numMine, state, board);

    fout << 4 << '\n';
    fout << Row << ' ' << Col << ' ' << numMine << '\n';
    fout << 0 << '\n';

    for(int i = 0; i < Row; i++) {
        for(int j = 0; j < Col; j++) {
            fout << board[i][j] << ' ';
        }

        fout << '\n';
    }

    fout << '\n';

    for(int i = 0; i < Row; i++) {
        for(int j = 0; j < Col; j++) {
            fout << state[i][j] << ' ';
        }

        fout << '\n';
    }

    fout.close();
}

void Save_txtFile(int type, int Row, int Col, int numMine, int Time, int board[41][41], int state[41][41]) {
    ofstream fout;
    fout.open("GAME_STATE.txt");

    fout << type << '\n';
    fout << Row << ' ' << Col << ' ' << numMine << '\n';
    fout << Time << '\n';

    for(int i = 0; i < Row; i++) {
        for(int j = 0; j < Col; j++) fout << board[i][j] << ' ';

        fout << '\n';
    }

    fout << '\n';

    for(int i = 0; i < Row; i++) {
        for(int j = 0; j < Col; j++) fout << state[i][j] << ' ';

        fout << '\n';
    }

    fout.close();
}

void Reset_LeaderBoard() {
    ofstream fout;
    fout.open("GAME_LEADERBOARD.txt");

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) fout << 0 << ' ';

        fout << '\n';
    }

    fout.close();
}

bool cmp(int a, int b) {
    if(a == 0) return false;
    if(b == 0) return true;

    return a < b;
}

void Change_LeaderBoard(int type, int Time) {
    if(type == 4) return;

    ifstream fin;
    fin.open("GAME_LEADERBOARD.txt");

    int a[5][5];
    memset(a, 0, sizeof(a));

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            fin >> a[i][j];
        }
    }

    fin.close();

    ofstream fout;
    fout.open("GAME_LEADERBOARD.txt");

    a[type][4] = Time;
    sort(a[type] + 1, a[type] + 1 + 4, cmp);

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            fout << a[i][j] << ' ';
        }

        fout << '\n';
    }

    fout.close();
}

void Delete_Data() {
    ofstream fout;
    fout.open("GAME_STATE.txt");

    fout << -1 << '\n';
    fout.close();
}
