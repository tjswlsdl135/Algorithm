#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> houses;
queue<pair<int, int>> Q2;
int N, M, cnt, houseNum;
int x[4] = { 1,0,-1,0 };
int y[4] = { 0,1,0,-1 };
int map[52][52];
int ans = 10000000;
pair<int, int> store[14];
vector<int> v;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				store[cnt] = { i,j };
				map[i][j] = 0;
				if (cnt < M)
					v.push_back(1);
				else
					v.push_back(0);
				cnt++;
			}
			else if (map[i][j] == 1) {
				houses.push_back({ i,j });
				houseNum++;
				map[i][j] = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	do {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				map[i][j] = 10000;
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 1) {
				int a = store[i].first;
				int b = store[i].second;
				map[a][b] = 0;
				Q2.push({ a,b });
			}
		}
		int tmpAns = 0;
		pair<int, int> tmp;
		while (!Q2.empty()) {
			tmp = Q2.front();
			Q2.pop();
			int c = map[tmp.first][tmp.second];
			for (int i = 0; i < 4; i++) {
				int a = tmp.first + y[i];
				int b = tmp.second + x[i];
				if (a >= 0 && b >= 0 && a < N && b < N && map[a][b] > c + 1) {
					map[a][b] = c + 1;
					Q2.push({ a,b });
				}
			}
		}
		for (int i = 0; i < houseNum; i++) {
			int a = houses[i].first;
			int b = houses[i].second;
			tmpAns += map[a][b];
		}
		ans = min(ans, tmpAns);
		while (!Q2.empty()) {
			Q2.pop();
		}

	} while (next_permutation(v.begin(), v.end()));
	printf("%d", ans);

	return 0;
}
