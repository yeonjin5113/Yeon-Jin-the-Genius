#include <iostream>
#include <cstring>
using namespace std;

/*
A가 B의 2-친구
1. A와 B가 친구
2. A와 C가 친구, B와 C가 친구
*/

int N;	// 사람의 수
int people[51][51];		// 친구면 1, 아니면 0
int cnt = 0, max_cnt = 0;
int visit[51];

void friend_count(int n, int p) {	//본인, 친구
	for (int i = 0; i < N; i++) {
		if (i != n) {	// 본인이 아니고
			if (people[i][p] == 1 && !visit[i]) {	// 친구의 친구이고 내 친구가 아니면
				visit[i] = 1;
				cnt++;
			}
		}
	}
}


int main() {
	cin >> N;

	// 친구인지 아닌지 입력받음
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			if (c == 'Y') {	// 1번
				people[i][j] = 1;
			}
			else if (c == 'N') {
				people[i][j] = 0;
			}
		}
	}

	// 2번
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (people[j][i] == 1) {	// 친구, 본인
				if (!visit[j]) {
					cnt++;
					visit[j] = 1;
				}
				friend_count(i, j);		// 본인, 친구
			}
		}
		max_cnt = max(cnt, max_cnt);
		memset(visit, 0, sizeof(visit));
		cnt = 0;
	}
	cout << max_cnt;

}
