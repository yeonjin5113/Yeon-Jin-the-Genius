#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int arr[101][101];			// 지도
int visit[101][101];		// 방문했는지 확인을 위한 배열
int safe_zone[101][101];	// 물에 잠기지 않은 지역 -> 1
priority_queue<int> que;	// 결과 저장
int max_num = 0;			// 높이가 가장 높은 것과 낮은 것
int cnt = 0;

int dx[4] = { 0, 1, 0, -1 };	// 상하좌우
int dy[4] = { 1, 0, -1, 0 };

void count(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {	// 상하좌우에 안전한 영역이 있을 경우
			if (!visit[ny][nx] && safe_zone[ny][nx]) {
				visit[ny][nx] = 1;
				count(nx, ny);
			}
		}
	}
}

void func() {
	for (int i = 1; i <= N; i++) {	// 세
		for (int j = 1; j <= N; j++) {	// 가
			if (!visit[i][j] && safe_zone[i][j]) {	// 방문하지 않고 안전한 지역이면
				cnt++;
				count(j, i);
			}
		}
	}
	que.push(cnt);
	/* 초기화 */
	cnt = 0;
	memset(visit, 0, sizeof(visit));
	memset(safe_zone, 0, sizeof(safe_zone));
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {	// 세로
		for (int j = 1; j <= N; j++) {	// 가로
			int num;
			cin >> num;
			arr[i][j] = num;
			max_num = max(max_num, num);
		}
	}

	while (max_num >= 0) {
		for (int i = 1; i <= N; i++) {	// 세
			for (int j = 1; j <= N; j++) {	// 가
				if (arr[i][j] > max_num) {	// 기준 지역보다 높은 지역일 경우
					safe_zone[i][j] = 1;	// 안전한 영역으로 설정
				}
			}
		}	// 물에 잠기지 않는 지역을 1로 표시함
		func();
		max_num--;
	}

	cout << que.top();
}
