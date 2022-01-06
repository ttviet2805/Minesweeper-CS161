#include "GEN.h"

int Random(int l, int r) {
	long long t = RAND_MAX + 1;

	return l + (t * t * t * rand() + t * t * rand() + t * rand() + rand()) % (r - l + 1);
}

void Build_Game(int m, int n, int Bomb, int a[41][41], int c[41][41]) {
    srand(time(0));

	for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) a[i][j] = 0, c[i][j] = 10;
    bool vs[55][55];
    memset(vs, false, sizeof(vs));

    int numBomb = 0;

	while(1) {
        if(numBomb == Bomb) break;
		int val = Random(0, m * n - 1);

		int Row = val / n, Col = val % n;

        if(vs[Row][Col]) {
            continue;
        }
        numBomb++;

		a[Row][Col] = 9;

		vs[Row][Col] = true;
	}

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 9) continue;

			for(int u = -1; u <= 1; u++) for(int v = -1; v <= 1; v++) {
				int ni = i + u, nj = j + v;
				if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue;

				a[i][j] += (a[ni][nj] == 9);
			}
		}
	}
}
