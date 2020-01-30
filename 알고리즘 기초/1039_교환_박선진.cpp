#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, K, index, ans;
bool check[11][1000003];

int swapNum(int n, int a, int b) {
	int n1, n2, ret;
	n1 = n / pow(10, a); n1 %= 10;
	n2 = n / pow(10, b); n2 %= 10;
	if (b == index - 1 && n1 == 0) return 0;
	ret = n - n1 * pow(10, a) - n2 * pow(10, b) + n1 * pow(10, b) + n2 * pow(10, a);
	return ret;
}

void dfs(int num, int l) {
	if (l == K) ans = max(ans, num);
	else {
		for (int i = 0; i < index; i++) {
			for (int j = i + 1; j < index; j++) {
				int tmp = swapNum(num, i, j);
				if (check[l][tmp] || tmp == 0) continue;
				check[l][tmp] = true;
				dfs(tmp, l + 1);
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	int tmp = N;
	while (tmp) tmp /= 10, index++;
	dfs(N, 0);
	if (!ans) printf("-1");
	else printf("%d", ans);
}
