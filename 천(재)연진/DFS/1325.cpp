// 42m17s
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;	// 컴퓨터의 수, 연결된 수
vector<int> vec[10001];	// 신뢰하는 관계 저장
int visit[10001];		// 해킹한 컴퓨터인지
int result[10001];		// 해킹한 컴퓨터의 수 저장
int cnt = 1;
int max_cnt = 0;

void check(int n) {
	for (int i = 0; i < vec[n].size(); i++) {	
		int num = vec[n][i];
		if (!visit[num]) {
			cnt++;
			visit[num] = 1;
			check(num);
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		vec[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		visit[i] = 1;
		check(i);
		result[i] = cnt;
		max_cnt = max(max_cnt, cnt);	// 해킹한 컴퓨터의 최댓값
		/* 초기화 */
		cnt = 1;
		memset(visit, 0, sizeof(visit));
	}

	for (int i = 1; i <= N; i++) {
		if (result[i] == max_cnt) {		// 가장 많은 컴퓨터를 해킹한
			cout << i << " ";			// 컴퓨터의 번호 출력
		}
	}
}
