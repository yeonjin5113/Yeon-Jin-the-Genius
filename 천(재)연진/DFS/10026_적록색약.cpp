//33m
#include <iostream>
#include <cstring>
using namespace std;

int N;
char grid[101][101];		// 그림
int visit[101][101];
int cnt = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void color_count(int x, int y, char col) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			if (grid[ny][nx] == col && !visit[ny][nx]) {	// 방문한적 없고 같은 색인 경우
				if (grid[ny][nx] == 'R') {
					grid[ny][nx] = 'G';
				}
				visit[ny][nx] = 1;
				color_count(nx, ny, col);
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {	// 가로
		for (int j = 0; j < N; j++) {	// 세로
			cin >> grid[j][i];
		}
	}

	// 적록색약이 아닌 사람
	for (int i = 0; i < N; i++) {	// 가로
		for (int j = 0; j < N; j++) {	// 세로
			if (!visit[j][i]) {
				visit[j][i] = 1;
				char c = grid[j][i];
				color_count(i, j, c);
				if (c == 'R') {	// 적록색약은 빨강과 초록을 구별하지 못하기 때문에
					grid[j][i] = 'G';	// 빨강을 초록으로 바꿈
				}
				cnt++;
			}
		}
	}
	cout << cnt << " ";
	memset(visit, 0, sizeof(visit));
	cnt = 0;

	//적록색약인 사람
	for (int i = 0; i < N; i++) {	// 가로
		for (int j = 0; j < N; j++) {	// 세로
			if (!visit[j][i]) {
				visit[j][i] = 1;
				char c = grid[j][i];
				color_count(i, j, c);
				cnt++;
			}
		}
	}
	cout << cnt;
}
