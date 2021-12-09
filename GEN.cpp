#include "GEN.h"

int Random(int l, int r) {
	long long t = RAND_MAX + 1;

	return l + (t * t * t * rand() + t * t * rand() + t * rand() + rand()) % (r - l + 1);
}

void Build_Game(int n, int Bomb, int a[105][105], int c[105][105]) {
    srand(time(0));

	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) a[i][j] = 0, c[i][j] = 10;

	for(int i = 1; i <= Bomb; i++) {
		int val = Random(0, n * n - 1);

		int Row = val / n, Col = val % n;

		a[Row][Col] = 9;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 9) continue;

			for(int u = -1; u <= 1; u++) for(int v = -1; v <= 1; v++) {
				int ni = i + u, nj = j + v;
				if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

				a[i][j] += (a[ni][nj] == 9);
			}
		}
	}
}
