#include <iostream>
using namespace std;

int T;
long long P[102] = { 0, };

long long Sol(int n) {
	if (P[n] == 0) {  // 저장된 값이 없으면
		return P[n] = Sol(n - 3) + Sol(n - 2); 
	}
	else {
		return P[n];
	}
}

int main() {
	cin >> T;

  // 초기
	P[1] = 1, P[2] = 1, P[3] = 1;
	P[4] = 2, P[5] = 2;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		Sol(N);
		cout << P[N] << endl;
	}
}
