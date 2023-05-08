#include <iostream>
using namespace std;

int n;
int arr[1001];

int DP(int i) {
	if (i == 1) {
		return arr[1] = 1;
	}
	if (i == 2) {
		return arr[2] = 3;
	}
	if (arr[i] == 0) {
		return arr[i] = (DP(i - 1) + DP(i - 2) * 3 - arr[i - 2]) % 10007;
    // DP(i-1) 이전 모양에서 1*2가 붙는 경우
    // DP(i-2)에서 2*1, 2*2, 1*2(2개)가 붙는 경우
    // arr[i-2] 겹치는 경우 제외
	}
	return arr[i];
}

int main() {
	cin >> n;

	cout << DP(n);
}
