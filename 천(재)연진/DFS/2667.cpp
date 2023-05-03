// 한시간 좀 넘은 듯

#include <iostream>
#include <queue>
using namespace std;

int N;					// 지도의 크기
int arr[26][26];		// 단지를 저장하는 배열
int visit[26][26];		// 방문했는지 확인하는 배열
priority_queue<int, vector<int>, greater<int>> result;		// 결과 저장 벡터
int num = 1;	// 단지 번호
int cnt = 1;	// 단지내 집의 수

int dx[4] = { 0, 1, 0, -1 };	// 상하좌우
int dy[4] = { 1, 0, -1, 0 };

void output() {
	cout << num - 1 << endl;	// 총 단지수
	while (!result.empty()) {	// 오름차순으로 단지내 집의 수 출력
		cout << result.top() << endl;
		result.pop();
	}
}

void check(int n, int c, int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		/* 방문한 적 없으면 단지내 집의 수 증가시킴 */
		if (1 <= nx && nx <= N && 1 <= ny && ny <= N
			&& !visit[ny][nx] && arr[ny][nx]) {
			visit[ny][nx] = 1;
			check(num, cnt++, nx, ny);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= N; j++) {
			arr[i][j] = temp[j - 1] - '0';
		}
	}

	for (int i = 1; i <= N; i++) {	//세
		for (int j = 1; j <= N; j++) {	//가
			if (!visit[i][j] && arr[i][j]) {	// 세로 가로
				visit[i][j] = 1;
				check(num, cnt, j, i);

				result.push(cnt);	// 단지내 집의 수
				num++;	// 연결된 집이 없으면 다음 단지를 찾기위해
				cnt = 1;
			}
		}
	}

	output();

}
