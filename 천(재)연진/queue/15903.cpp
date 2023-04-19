// 17m05s		-> long long 인지 알기 어렵

#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> que;

void cal(int m) {	// 가장 작은 점수를 계산하는 프로그램
	long long num1, num2;
	long long sum = 0;

	for (int i = 0; i < m; i++) {
		num1 = que.top();	// 가장 작은 수를 꺼냄
		que.pop();
		num2 = que.top();
		que.pop();

		que.push(num1 + num2);		// 가장 작은 두 수를 저장함
		que.push(num1 + num2);		// 가장 작은 두 수를 저장함
	}

	while (!que.empty()) {
		sum += que.top();	// 큐에 있는 수를 저장함
		que.pop();
	}
	cout << sum;
}

int main() {
	int n;		// 카드의 개수
	int m;		// 카드 합체를 몇 번하는지
	long long s;		// 카드의 상태를 나타내는 자연수
	cin >> n >> m;

	while (n--) {
		cin >> s;
		que.push(s);
	}
	cal(m);

	return 0;
}
