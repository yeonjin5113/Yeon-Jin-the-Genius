// 44m 50s

#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> que;	// 도수레벨, 선호도	(도수가 낮은 것부터 저장)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> out_que;	// 선호도, 도수레벨

void min_cal(int day, int add_prefer) {
	int i = 0;
	int prefer_result = 0;

	while (1) {
		if (que.empty()) {
			cout << "-1";
			break;
		}
		out_que.push({que.top().second, que.top().first});	// 선호도가 낮은 순으로 큐에 저장
		prefer_result += que.top().second;					// 도수가 낮은 순으로 선호도를 저장
		i++;

		if (i == day && prefer_result >= add_prefer) {		// 만족하고자하는 선호도보다 높으면
			cout << que.top().first;	// 가장 높은 도수 출력
			break;
		}
		else if (i == day && prefer_result < add_prefer) {	// 선호도를 만족하지 못하면
			prefer_result -= out_que.top().first;			// 선호도가 가장 낮은 맥주를 제거하고 다른 맥주를 넣음
			out_que.pop();
			i--;
			que.pop();

		}
		else {
			que.pop();
		}
	}
}

int main() {
	int N;		// 축제가 열리는 기간
	int M;		// 선호도의 합
	int K;		// 맥주 종류의 수

	cin >> N >> M >> K;

	while (K--) {
		int prefer, level;
		cin >> prefer >> level;

		que.push({ level, prefer });		// 도수레벨과 선호도 순으로 큐에 저장 (도수가 낮은 것부터 큐에 저장됨)
	}
	min_cal(N, M);
	return 0;
}

/*
	맥주의 도수 레벨 > 전씨의 간 -> 맥주병
	맥주 N개의 선호도의 합이 M 이상 되도록
	선호도   도수레벨
*/
