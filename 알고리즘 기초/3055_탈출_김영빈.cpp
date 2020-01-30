#include<iostream>
#include<queue>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q_move;
queue<pair<int, int>> q_water;
pair<int, int> temp;
char Map[51][51];
int row, col;
int ans;

void extend_water() {
	int size = q_water.size();
	for (int i = 0; i < size; i++) {
		temp = q_water.front();
		q_water.pop();
		for (int k = 0; k < 4; k++) {
			int ix = temp.first + dx[k];
			int iy = temp.second + dy[k];
			if (ix >= 0 && ix < row && iy >= 0 && iy < col) {
				if (Map[ix][iy] == '.') {
					q_water.push({ ix,iy });
					Map[ix][iy] = '*';
				}
			}
		}
	}
}

bool extend_move() {
	int size = q_move.size();
	for (int i = 0; i < size; i++) {
		temp = q_move.front();
		q_move.pop();
		for (int k = 0; k < 4; k++) {
			int ix = temp.first + dx[k];
			int iy = temp.second + dy[k];
			if (ix >= 0 && ix < row && iy >= 0 && iy < col) {
				if (Map[ix][iy] == '.') {
					q_move.push({ ix,iy });
					Map[ix][iy] = 'S';
				}
				if (Map[ix][iy] == 'D') {
					q_move.push({ ix,iy });
					return true;
				}
			}
		}
	}
	return false;
}
int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> Map[i][j];
		}
	}

	//bfs
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (Map[i][j] == '*') {
				q_water.push({ i,j });
			}
			if (Map[i][j] == 'S') {
				q_move.push({ i,j });
			}
		}
	}
	
	while (1) {
		++ans;
		if (q_move.empty()) {
			cout << "KAKTUS" << '\n';
			return 0;
		}
		extend_water();
		if (extend_move()) {
			cout << ans << '\n';
			return 0;
		}
	}
	return 0;
}
