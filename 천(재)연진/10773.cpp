/*22m41s*/
#include <iostream>
#include <stack>
using namespace std;

int Solution() {
	int K, num, add = 0;	// K : 입력받을 수, num : 입력된 수
	stack<int> number;

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> num;
		
		/*0이 입력되면 최근에 입력된 수를 지움
		  0이 아닌 다른 숫자는 stack에 넣음*/
		if (num == 0) {
			number.pop();
		}
		else {
			number.push(num);
		}
	}
	/*stack이 빈 상태가 될 때까지 숫자를 뺀 후 더해줌*/
	while (!number.empty()) {
		add += number.top();
		number.pop();
	}
	return add;
}

int main() {
	cout << Solution();
}
