#pragma once

#include <bits/stdc++.h>
using namespace std;

#include "MYCONST.h"
#include "GEN.h"

void Put_txtFile(int type);

void Save_txtFile(int type, int Row, int Col, int Time, int numMine, int board[41][41], int state[41][41]);

void Reset_LeaderBoard();

void Change_LeaderBoard(int type, int Time);

void Delete_Data();

void Put_Custom(int Row, int Col, int numMine);
