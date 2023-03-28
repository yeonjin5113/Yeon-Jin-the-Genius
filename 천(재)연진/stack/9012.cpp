#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int VPS(int num) {
	string ip;					// 괄호 문자열
	stack<char> st;				//문자열을 저장할 스택
	vector<string> result;		// VPS의 결과

	while (num--) {
		cin >> ip;		// 괄호 문자열 입력

		for (int i = 0; i < ip.length(); i++) {
			// 문자열이 비어 있으면 스택에 넣음
			if (st.empty()) {
				st.push(ip[i]);
				// ')'은 올바른 괄호 문자열이 아니기 때문에 for문에서 나감
				if (ip[i] == ')') {		
					break;
				}
			}
			else {
				// 입력된 값과 스택에 저장된 값이 동일하면 pop
				if (st.top() != ip[i]) {
					st.pop();
				}
				// 아니면 push
				else {
					st.push(ip[i]);
				}
			}
		}
		// 스택이 비어 있으면(VPS면) YES, 아니면 NO
		if (st.empty()) {
			result.push_back("YES");
		}
		else {
			result.push_back("NO");
			// 스택에 저장되어 있는 문자들을 지워줌
			while (!st.empty()) {
				st.pop();
			}
		}
	}
	// 결과 출력
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	return 0;
}

int main() {
	int num;	//입력 데이터의 수

	cin >> num;
	VPS(num);
}
