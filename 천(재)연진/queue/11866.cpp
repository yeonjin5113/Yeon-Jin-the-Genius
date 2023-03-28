// 28m09s

#include <iostream>
#include <queue>
using namespace std;

void josephus(int p, int num) {
	queue<int> per;		// 순열

	for (int i = 1; i <= p; i++) {
		per.push(i);			// 1부터 p까지 순서대로 큐에 저장
	}
	cout << '<';

	while (!per.empty()) {
		for (int i = 1; i < num; i++) {		// 제거하고자 하는 순서가 오기 전까지 큐의 맨 뒤로 보냄
			per.push(per.front());
			per.pop();
		}
		cout << per.front();		// 제거하고자 하는 순서(num)가 되면 출력

		/*출력 모양을 맞추기 위해*/
		if (per.size() == 1) {
			per.pop();
		}
		else {
			cout << ", ";
			per.pop();
		}
	}
	cout << '>';
}

int main() {
	int N;		// 사람의 수
	int K;		//제거하고자 하는 순서

	cin >> N >> K;
	josephus(N, K);
}
