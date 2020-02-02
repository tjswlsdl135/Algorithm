#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> vec;
int frame;
int candidate;
int input;

int main() {
	cin >> frame;
	cin >> candidate;
	for (int i = 0; i < candidate; i++) {
		cin >> input;
		bool check = false;
		for (int j = 0; j < vec.size(); j++) {
			if (vec[j].first == input) {
				vec[j].second++;
				check = true;
			}
		}
		if (!check && vec.size() < frame) { //안찼을 때 추가
			vec.push_back({ input,1 });
			continue;
		}

		if (!check && vec.size() == frame) { // 꽉 찼을 때 제거하고 추가
			int min = 1001; // 추천 수
			int index = 21; // 사진 수
			for (int j = 0; j < vec.size(); j++) {
				if (vec[j].second < min) {
					min = vec[j].second;
					index = j;
				}
			}
			vec.erase(vec.begin() + index);
			vec.push_back({ input,1 });
		}
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].first << ' ';
	}
	cout << '\n';
	
	return 0;
}
