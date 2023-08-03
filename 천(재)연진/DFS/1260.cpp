// 2~3시간 걸린 듯 이거 올렸는데 사라짐...

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;	// 정점의 개수, 간선의 개수
vector<int> vec[1001];
int visit[1001][1001];	// 방문한 적 있는지 확인
int visit2[1001][1001];	// 방문한 적 있는지 확인
int result1[1001];	// DFS 결과 저장
int result2[1001];
int cnt = 1;
int num = 1;

void output() {
	for (int i = 1; i <= N; i++) {
		if (result1[i] == 0) {
			break;
		}
		cout << result1[i] << " ";
	}

	cout << endl;
	for (int i = 1; i <= N; i++) {
		if (result2[i] == 0) {
			break;
		}
		cout << result2[i] << " ";
	}
}

void DFS(int n) {
	for (int i = 0; i < vec[n].size(); i++) {
		int j = vec[n][i];

		/* 결과에 저장한 정점와 연결되어 있는 경우 
			방문했음으로 바꿈*/
		for (int k = 1; k <= N; k++) {
			if (result1[k] == j) {
				visit[n][j] = 1;
				visit[j][n] = 1;
			}
		}
		/* 방문한 적 없는 경우 */
		if (!visit[n][j]) {
			visit[n][j] = 1;
			visit[j][n] = 1;
			result1[++cnt] = vec[n][i];
			DFS(vec[n][i]);
		}
	}
}

void BFS(int n) {
	for (int i = 0; i < vec[n].size(); i++) {
		int j = vec[n][i];

		for (int k = 1; k <= cnt; k++) {
			if (j == result2[k]) {
				visit2[n][j] = 1;
				visit2[j][n] = 1;
				break;
			}
		}

		/* 하나의 점에 연결된 모든 점을 탐색 */
		if (!visit2[n][j]) {
			visit2[n][j] = 1;
			visit2[j][n] = 1;
			result2[++cnt] = vec[n][i];
		}
		
	}

	if (num != N) {
		BFS(result2[++num]);
	}
}

int main() {
	int V;

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);	// 양방향이기 때문에
		vec[v].push_back(u);
	}

	// 방문해야하는 번호를 순서대로 정렬
	for (int i = 1; i <=N; i++) {
		sort(vec[i].begin(), vec[i].end());
	}
	
	result1[1] = V;		// 처음 방문하는 정점
	DFS(V);	

	cnt = 1;
	result2[1] = V;		// 처음 방문하는 정점
	BFS(V);
	output();
	
}
