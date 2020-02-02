#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int N;
int alphabet[27];
string word[11];
int ans;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word[i];
		for (int j = 0; j < word[i].size(); j++) {
			// a~g를 count해야함.
			alphabet[word[i][j] - '0'-17] += pow(10,(word[i].size() - 1 - j));

		}
	}

	for (int i = 0; i < 26; i++) {
		for (int j = i; j < 27; j++) {
			if (alphabet[i] < alphabet[j]) {
				int temp = alphabet[i];
				alphabet[i] = alphabet[j];
				alphabet[j] = temp;
			}
		}
	}

	int count = 9;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == 0) {
			continue;
		}
		ans += (alphabet[i] * (count--));
	}

	cout << ans << '\n';
	return 0;
}
