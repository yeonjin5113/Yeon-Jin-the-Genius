#include <iostream>
using namespace std;

int stair[301];
int T;	// 계단의 수
int total = 0;
int D[301];	// DP 값 저장할 배열

void Sol(int n) {
	for (int i = n; i < T; i++) {
		D[i] = min(D[i - 2], D[i - 3]) + stair[i];	// 현재 계단은 필수로 밟아야 됨
	}
	// 전체에서 안 밟아도 되는 계단 최솟값 빼기
	cout << total - min(D[T - 2], D[T - 3]);
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> stair[i];
		total += stair[i];
	}
	D[0] = stair[0];
	D[1] = stair[1];
	D[2] = stair[2];
	Sol(3);
}
