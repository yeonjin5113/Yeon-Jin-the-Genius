// 26m

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> que;	// 내림차순의 우선순위 큐



void input(int N) {
	int n = N * N;
	int num;

	while (n--) {
		cin >> num;
		if (que.size() == N) {		// N보다 더 많은 수 가 입력되면
			if (que.top() < num) {	// que에 들어가 있는 가장 작은 수와 비교하여
				que.pop();			// num이 더 큰 경우에 큐에 넣음
				que.push(num);
			}
		}
		else {
			que.push(num);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);   // 이거 쓰면 해결된다길래 썼는데 진짜 해결됨;~;
	cin.tie(NULL);                      //이것도 마찬가지...
	int N;

	cin >> N;
	input(N);
	cout << que.top();

	return 0;
}
