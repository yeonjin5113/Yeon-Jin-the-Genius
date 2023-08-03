// 38m

#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];	// 세로, 가로
int visit[101][101];
int result[101];
int M, N, K;	// 세로, 가로, 직사각형의 수

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int cnt = 1;

void check(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (arr[ny][nx] == 0 && visit[ny][nx] == 0) {
				visit[ny][nx] = 1;
				++cnt;
				check(nx, ny);
			}
		}
	}
}

void map(int lx, int ly, int rx, int ry) {
	for (int i = lx; i < rx; i++) {		// 직사각형인 부분을 1로
		for (int j = ly; j < ry; j++) {
			arr[j][i] = 1;
		}
	}
}

int main() {
	cin >> M >> N >> K;

	while (K--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		map(x1, y1, x2, y2);
	}
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[j][i] == 0 && visit[j][i] == 0) {	// 방문한 적 없고 사각형의 내부가 아닌 경우
				visit[j][i] = 1;
				check(i, j);
				result[k++] = cnt;
				cnt = 1;
			}
		}
	}

	// 결과 출력
	sort(result, result + k);	// 오름차순 정렬
	cout << k << endl;
	for (int i = 0; i < k; i++) {
		cout << result[i] << " ";
	}

}
