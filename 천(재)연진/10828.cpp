//20

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int in_stack(int N) {
	int num;
	string cmd;
	stack<int> st;
	vector<int> vec;

	while (N--) {
		cin >> cmd;

		if (cmd == "push") {	//push가 입력되면 스택에 저장
			cin >> num;
			st.push(num);
		}
		else if (cmd == "pop") {
			if (!st.empty()) {	//pop이 입력되고 스택이 비어있지 않으면
				vec.push_back(st.top());	// 백터에 가장 위에 있는 숫자를 저장
				st.pop();
			}
			else {//pop이 입력되고 스택이 비어있으면
				vec.push_back(-1);		// 백터에 -1을 저장
			}
		}
		else if (cmd == "size") {
			vec.push_back(st.size());
		}
		else if (cmd == "empty") {
			if (st.empty()) {
				vec.push_back(1);
			}
			else {
				vec.push_back(0);
			}
		}
		else if (cmd == "top") {
			if (!st.empty()) {
				vec.push_back(st.top());
			}
			else {
				vec.push_back(-1);
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	return 0;
}

int main() {
	int N;		// N : 명령의 수

	cin >> N;
	in_stack(N);
}
