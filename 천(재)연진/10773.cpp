/*22m41s*/
#include <iostream>
#include <stack>
using namespace std;

int Solution() {
	int K, num, add = 0;
	stack<int> number;

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num == 0) {
			number.pop();
		}
		else {
			number.push(num);
		}
	}

	while (!number.empty()) {
		add += number.top();
		number.pop();
	}
	return add;
}

int main() {
	cout << Solution();
}
