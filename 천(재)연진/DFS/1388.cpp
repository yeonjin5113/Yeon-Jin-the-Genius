#include <iostream>
using namespace std;

int N, M;	// 방의 세로, 가로
char arr[50][50];	// 바닥 장식 모양 저장 배열
bool visit[50][50] = { false };		// 방문했던 곳인지 아닌지 체크

void DFS(int i, int j) {

	if (arr[i][j] == '-') {
		int n = j + 1;
		if (arr[i][n] == '-' && n < M && !visit[i][n]) {	// 연속으로 -가 있다면 하나로 생각
			visit[i][n] = true;
			DFS(i, n);
		}
	}
	else {
		int n = i + 1;
		if (arr[n][j] == '|' && n < N && !visit[n][j]) {
			visit[n][j] = true;
			DFS(n, j);
		}
	}
}

int main() {
	cin >> N >> M;

	/* 바닥 장식 모양 입력 받기 */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;	// 필요한 나무 판자의 개수

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j]) {		// 개수를 세지 않은 나무 판자라면
				visit[i][j] = true;	// 방문했음으로 바꿈
				DFS(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}
