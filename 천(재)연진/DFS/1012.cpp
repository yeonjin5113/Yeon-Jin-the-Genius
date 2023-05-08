//34m25s

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T;			// 테스트 케이스의 수
int cnt = 0;	// 배추흰지렁이의 수
int arr[51][51];	// 배추가 심어있는 지도
int visit[51][51];	// 방문했는지 확인하기 위한 배열
vector<int> vec;	// 결과 저장을 위한 벡터

int dx[4] = { 0, 1, 0, -1 };	// 상하좌우
int dy[4] = { 1, 0, -1, 0 };

int N, M;

void count(int x, int y) {	// 가로, 세로
	for (int i = 0; i < 4; i++) {	// 상하좌우에 배추가 있는지 확인
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < M && 0 <= ny && ny < N) {
			if (!visit[ny][nx] && arr[ny][nx]) {
				visit[ny][nx] = 1;
				count(nx, ny);
			}
		}
	}
}

int main() {
	cin >> T;

	while (T--) {	
		int K;	
		cin >> M >> N >> K;		// 가로, 세로, 배추가 심어있는 위치의 개수

		for (int i = 0; i < K; i++) {	// 배추가 있는 좌표를 입력받음
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0; i < N; i++) {	// 세로
			for (int j = 0; j < M; j++) {	//가로
				if (!visit[i][j] && arr[i][j]) {	// 방문한적 없고 배추가 있으면
					visit[i][j] = 1;
					cnt++;
					count(j, i);
				}
			}
		}
		vec.push_back(cnt);

		/* 초기화 */
		cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));

	}
	
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
}
