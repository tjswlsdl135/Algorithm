#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N, K;
string sent;
vector<string> sentence;
int ans;
bool alphabet[26];
bool canRead;
int cnt;

int can_read() {
	canRead = true;
	cnt = 0;
	for (int i = 0; i < sentence.size(); i++) {
		canRead = true;
		string sent = sentence[i];
		for (int j = 0; j < sent.size(); j++) {
			if (alphabet[sent[j] - 'a'] == false) {
				canRead = false;
				break;
			}
		}
		if (canRead == true) {
			cnt++;
		}
	}
	return cnt;
}

void add_character(int idx, int times) {
	if (times == K) {
		if (ans < can_read()) {
			ans = can_read();
			return;
		}
	}
	for (int i = idx; i < 26; i++) {
		if (alphabet[i] == true) { //a,n,t,i,c 는 원래 true
			continue;
		}
		alphabet[i] = true;
		add_character(i + 1, times + 1);
		alphabet[i] = false;
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> sent;
		sentence.push_back(sent);
	}
	//최소 5개 알파벳 필요
	if (K < 5) {
		cout << 0;
		return 0;
	}
	alphabet['a' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['c' - 'a'] = true;
	K -= 5;
	add_character(0, 0);
	cout << ans << '\n';
	return 0;
}
