#include <iostream>
using namespace std;

int map[101][101];
long long map_cnt[101][101] = { {0}, };
int N;

void Sol() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map_cnt[i][j] != 0) {
				int n = map[i][j];
				if (n == 0) {	// 0이면 넘어감
					continue;
				}
				// 오른쪽과 아래로 이동하여 이전의 수를 더함
				map_cnt[i + n][j] += map_cnt[i][j];
				map_cnt[i][j + n] += map_cnt[i][j];
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	map_cnt[0][0] = 1;
	Sol();
	cout << map_cnt[N - 1][N - 1];
}
