#include <iostream>
#include <vector>
using namespace std;

int N, M;	// 자연수, 수열의 길이
int visit[9];
int result[9];

void Sol(int n, int cnt) {
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			result[n] = i;
			Sol(n + 1, cnt + 1);
			visit[i] = 0;
		}
		if (cnt == M) {
			for (int i = 1; i <= M; i++) {
				cout << result[i] << " ";
			}
			cout << '\n';
			return;
		}
	}
}

int main() {
	cin >> N >> M;
	Sol(1, 0);
}
