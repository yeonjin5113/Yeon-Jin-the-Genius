// 2시간은 걸린 듯 ㅠ

#include <iostream>
using namespace std;

int N, M, K;			// 세로, 가로 길이, 음쓰 수
int arr[101][101];		// 음식물 좌표 표시하는 배열
int visit[101][101];	// 방문했는지 확인하는 배열
int dx[4] = { 0, 1, 0, -1 };	// 상하좌우에 음식물 있는지
int dy[4] = { 1, 0, -1, 0 };	// 상하좌우에 음식물 있는지
int max_size = 0;	
int cnt = 0;
int s = 1;

void trash_size(int size, int x, int y) {
	int nx, ny;

	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		
		/* 상하좌우에 음쓰가 있고 방문한 적 없는 곳이라면 */
		if (1 <= nx && nx <= M && 1 <= ny && ny <= N && !visit[ny][nx]) {
			if (arr[ny][nx]) {
				visit[ny][nx] = 1;
				s += 1;		// 사이즈를 늘림
				trash_size(s, nx, ny);
				// 왜 size+1로 하면 안 되는지 모르겠음
			}
		}
		
	}
	max_size = max(s, max_size);
}

int main() {
	cin >> N >> M >> K;

	int r, c;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		arr[r][c] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] && !visit[i][j]) {	// 음식물이 있고 방문한 적 없다면
				visit[i][j] = 1;	// 방문했음으로 표시
				s = 1;
				trash_size(s, j, i);
			}
		}
	}
	cout << max_size;
}
