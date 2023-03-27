//25497 1H -> 틀림

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int count(int n) {
	int cnt = 0;		// 기술을 사용한 총 횟수
	string input;			// 임스가 사용할 기술
	stack<char> st;

	cin >> input;

	for (int i = 0; i < n; i++) {
		/*숫자면 무조건 추가*/
		if (isdigit(input[i])) {
			cnt++;
		}
		else {
			/*S나 L이면 스택에 추가*/
			if (input[i] == 'S' || input[i] == 'L') {
				st.push(input[i]);
			}
			else {
				/*S 다음에 K이거나 L 다음에 R이면 카운트*/
				if ((st.top() == 'S' && input[i] == 'K')
					|| (st.top() == 'L' && input[i] == 'R')) {
					st.pop();
					cnt++;
				}
				else {
					st.pop();
				}
			}
		}
	}
	return cnt;
}

int main() {
	int N;		// 총 기술 사용 횟수

	cin >> N;		// 기술 사용 횟수 입력
	cout << count(N);
}
