#include <iostream>
#include <queue>
using namespace std;

int X;	// 정수 X
queue<int> que;

void result(int cnt) {
	int size = que.size();

	while (size--) {
		int num = que.front();
		que.pop();

		if (num == 1) {		// 정수가 1이 되면 연산을 사용하는 횟수의 최솟값 출력
			cout << cnt;
			return;
		}

		if (num % 3 == 0) {
			que.push(num / 3);
		}
		if (num % 2 == 0) {
			que.push(num / 2);
		}
		que.push(num - 1);
	}
	result(++cnt);
}

int main() {
	cin >> X;

	if (X == 1) {	// 정수가 1인 경우 0 출력
		cout << 0;
	}
	else {
		que.push(X);
		result(0);
	}
}
