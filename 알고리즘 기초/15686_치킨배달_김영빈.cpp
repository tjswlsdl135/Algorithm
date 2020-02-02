#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int N, M;

long long city_chicken_distance = 54321;
int target;
vector<pair<int, int>> house_target;
vector<pair<int, int>> chicken;
vector<pair<int, int>> tmp;
bool visited[51][51];

void dfs(vector<pair<int, int>> chicken_target, int index) {
	if (chicken_target.size() == M) {
		// 2의 개수 찼을 때 각 1에서 2까지의 거리 최소 찾기
		int temp = 0;
		for (int i = 0; i < house_target.size(); i++) {
			long long chicken_distance = 4321;
			for (int j = 0; j < chicken_target.size(); j++) {
				int x = abs(house_target[i].first - chicken_target[j].first);
				int y = abs(house_target[i].second - chicken_target[j].second);
				if (chicken_distance > (x + y)) {
					chicken_distance = (x + y);
				}
			}
			temp += chicken_distance;
		}
		if (city_chicken_distance > temp)
			city_chicken_distance = temp;
		return;
	}
	for (int j = index + 1; j < chicken.size(); j++) {
		chicken_target.push_back(chicken[j]);
		dfs(chicken_target, j);
		chicken_target.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> target;
			if (target == 1) {
				house_target.push_back({ i, j });
			}
			if (target == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	// 1요소 집어넣고 돌리고 빼고 돌리기
	tmp.push_back(chicken[0]);
	dfs(tmp, 0);
	tmp.pop_back();
	dfs(tmp, 0);

	cout << city_chicken_distance << '\n';
	return 0;
}
