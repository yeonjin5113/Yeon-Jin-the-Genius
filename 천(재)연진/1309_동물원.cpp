#include <iostream>
using namespace std;

int N;	// 우리의 크기 세로
int num[100001] = { 0 };

int Sol(int n) {
	if (num[n] == 0) {
		num[n] = (Sol(n - 1) * 2 + Sol(n - 2)) % 9901;
		return num[n];
	}
	else {
		return num[n];
	}
}

int main() {
	cin >> N;
	num[0] = 1, num[1] = 3, num[2] = 7, num[3] = 17;  // 초기
	if (N != 1) {
		Sol(N);
	}
	cout << num[N];
}
