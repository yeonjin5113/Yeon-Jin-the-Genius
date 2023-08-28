#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, D;
int dis[100001];
vector<pair<int, int>> road[100001];


void Sol() {
	for (int i = 1; i <= D; i++) {
		if (road[i].size() == 0) {  // 지름길이 없으면
			dis[i] = dis[i - 1] + 1;  // 이전 거리 + 1
		}
		else {
			for (int j = 0; j < road[i].size(); j++) {
				int s = road[i][j].first;
				int d = road[i][j].second;

        // 이전 거리 + 1, 현재 저장된 거리, 새로운 지름길 중 가장 작은 값 저장
				dis[i] = min(dis[i - 1] + 1, min(dis[i], dis[s] + d));
			}
		}
	}
}

int main() {
	cin >> N >> D;

  // 입력받기
	for (int i = 0; i < N; i++) {
		int s, f, d;

		cin >> s >> f >> d;
		road[f].push_back(make_pair(s, d));
	}
	memset(dis, 10001, sizeof(dis));  // 가장 길이가 긴 값으로
	dis[0] = 0;
	Sol();
	cout << dis[D];
}
