#include <iostream>
#include <string>
#include <stack>
/*1h30m*/

#include <vector>
#include <sstream>
using namespace std;

int main() {
	int N;	// N : 전체 케이스의 수
	string str;
	stack<string> st;
	vector<string> vec;

	cin >> N;	//전체 케이스의 수


	for (int i = 0; i <= N; i++) {
		getline(cin, str);	// \n이 들어올 때까지 입력

		vec.push_back(str);		//입력된 문자열을 vector에 저장
	}

	for (int i = 1; i <= N; i++) {
		cout << "Case #" << i << ": ";

		/*공백으로 나눈 후 단어별로 stack에 저장*/
		stringstream ss(vec[i]);
		while (getline(ss, str, ' ')) {
			st.push(str);
		}
		/*스택에 저장된 단어 출력*/
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << "\n";
	}
}
