#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ans = 1;
int x[4] = { 1,0,-1,0 };
int y[4] = { 0,1,0,-1 };
char arr[51][51];
int check[51][51];
bool curCheck[51][51];
bool inf = false;

void dfs(int i, int j) {
	if (inf) return;
	for (int k = 0; k < 4; k++) {
		int a = i + y[k] * (arr[i][j] - '0');
		int b = j + x[k] * (arr[i][j] - '0');
		if (a >= 0 && b >= 0 && a < N && b < M) {
			if (curCheck[a][b] == true) inf = true;
			else if (arr[a][b] != 'H' && check[a][b] <= check[i][j]) {
				check[a][b] = check[i][j] + 1;
				curCheck[a][b] = true;
				ans = max(ans, check[a][b]);
				dfs(a, b);
				curCheck[a][b] = false;
			}
		}
	}
}

int main() {
	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) 
		cin >> arr[i][j];
	check[0][0] = 1;
	curCheck[0][0] = true;
	dfs(0, 0);
	if (inf) printf("%d", -1);
	else printf("%d", ans);
}
