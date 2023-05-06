#include <iostream>
#include <vector>
using namespace std;

int N, M;		// 정점의 개수, 간선의 개수
vector<int> vec[1001];
int visit[1001];
int cnt = 0;

void connect(int n) {
	int size = vec[n].size();
	for (int i = 0; i < size; i++) {
		int num = vec[n].back();
		vec[n].pop_back();
		if (!visit[num]) {
			visit[num] = 1;
			connect(num);
		}
	}
}

int main() {
	cin >> N >> M;

	int u, v;		// 간선의 양끝점

	for (int i = 0; i < M; i++) {
		cin >> u >> v;

		vec[u].push_back(v);	// 방향은 상관없음
		vec[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			connect(i);
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
