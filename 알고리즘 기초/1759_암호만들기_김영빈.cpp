#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int L, C;
char arr[21];

void searching(int index, string str, int aeiou, int n_aeiou) {
	if (str.size() == L) {
		if (n_aeiou < 2 || aeiou < 1) {
			return;
		}
		cout << str << '\n';
	}

	for (int i = index; i < C; i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
			searching(i + 1, str + arr[i], aeiou + 1, n_aeiou);
		}
		else {
			searching(i + 1, str + arr[i], aeiou, n_aeiou + 1);
		}
	}
}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + C);

	searching(0, "", 0, 0);
	return 0;
}
