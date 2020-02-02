#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int M;
vector<int> vec;
int answer[100001];
int find_num;
int num;

int binarySearch(int start, int end, int target) {
	if (start > end) {
		return 0;
	}
	else{
		int mid = (start + end) / 2;
		if (vec[mid] == target) {
			return 1;
		}
		else if (vec[mid] < target) {
			return binarySearch(mid + 1, end, target);
		}
		else {
			return binarySearch(start, mid - 1, target);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(),vec.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> find_num;
		// binary_search
		cout << binarySearch(0, N - 1, find_num) << '\n';
	}
	return 0;
}
