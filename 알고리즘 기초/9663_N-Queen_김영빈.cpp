#include<iostream>
using namespace std;

int N;
int column[16];
int counting;

bool isPossible(int row) {
	for (int j = 1; j < row; j++) {
		if (column[j] == column[row])
			return false;
		if (abs(j - row) == abs(column[j] - column[row]))
			return false;
	}
	return true;
}

void N_Queen(int row) {
	if (row == N)
		counting++;
	else {
		for (int i = 1; i <= N; i++) {
			column[row + 1] = i;
			if (isPossible(row + 1)) {
				N_Queen(row + 1);
			}
			else {
				column[row + 1] = 0;
			}
		}
	}
	column[row] = 0;
}


int main() {
	cin >> N;
	N_Queen(0);
	cout << counting << '\n';
	return 0;
}
