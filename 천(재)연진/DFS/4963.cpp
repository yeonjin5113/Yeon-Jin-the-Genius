#include <iostream>
#include <algorithm>
using namespace std;

int w, h;			// 지도의 너비, 높이
int map[50][50];	// 지도(세로, 가로)
int visit[50][50];	// 방문했는지 확인하기 위해
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };	// 가로, 세로, 대각선 방향 이동
int dy[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };	// 가로, 세로, 대각선 방향 이동

void around(int x, int y) {
	for (int i = 0; i < 8; i++) {	
		int nx = x + dx[i];		// 가로, 세로, 대각선에도 
		int ny = y + dy[i];		// 섬이 있는지 확인

		if (map[ny][nx] == 1 && !visit[ny][nx]
			&& 0 <= nx && nx < w && 0 <= ny && ny < h) {
			// 방문한 적 없는 섬이고 너비, 높이 범위 안에 있는 경우
			visit[ny][nx] = 1;	// 방문했음으로 바꾸고
			around(nx, ny);		// 다시 그 주변을 탐색함
		}
	}
}

void island() {
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1 && !visit[i][j]) {	// 방문한 적 없는 섬인 경우
				visit[i][j] = 1;	// 방문했음으로 바꿈
				around(j, i);		// 주변에 섬이 있는지 확인
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}

int main() {
	while (1) {
		cin >> w >> h;	// 너비, 높이

		if (w == 0 && h == 0) {	// 0, 0이 입력되면 끝남
			break;
		}
		else {
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					cin >> map[i][j];
				}
			}
			fill(&visit[0][0], &visit[49][50], 0);	// 0으로 초기화
			island();	
		}
	}
}
