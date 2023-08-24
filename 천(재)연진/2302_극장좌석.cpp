#include <iostream>
using namespace std;

int N;	// 좌석의 개수 1 ~ 40
int M;	// 고정석의 개수 0 ~ N
int fix[41];
long long cnt[42] = { 0 };
long long result = 1;

int Sol(int n) {
	if (cnt[n] == 0) {
		return cnt[n] = Sol(n - 1) + Sol(n - 2);
	}
	else {
		return cnt[n];
	}
}


int main() {
	cin >> N >> M;
	cnt[0] = 1, cnt[1] = 1, cnt[2] = 2;		// 초기값


	for (int i = 0; i < M; i++) {
		cin >> fix[i];	// 고정석 입력
		if (i == 0) {	// 1 ~ 처음 고정석
			result *= Sol(fix[i] - 1);	
		}
		else {	// 고정석 ~ 고정석
			result *= Sol(fix[i] - fix[i - 1] - 1);
		}
	}
	if (fix[M - 1] != N) {	// 고정석 ~ 마지막 좌석
		result *= Sol(N - fix[M - 1]);
	}

	cout << result;
}
