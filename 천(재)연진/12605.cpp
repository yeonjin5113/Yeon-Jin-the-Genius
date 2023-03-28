#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	int N;	// N : 전체 케이스의 수
	string str;
	stack<string> st;
	vector<string> vec;
	vector<string> words;

	cin >> N;


	for (int i = 0; i <= N; i++) {
		getline(cin, str);	// \n이 들어올 때까지 입력

		vec.push_back(str);
	}

	for (int i = 1; i <= N; i++) {
		cout << "Case #" << i << ": ";

		stringstream ss(vec[i]);
		while (getline(ss, str, ' ')) {
			st.push(str);
		}

		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << "\n";
	}
	
}
