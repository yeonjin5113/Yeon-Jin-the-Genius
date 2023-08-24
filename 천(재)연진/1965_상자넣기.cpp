#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;	// 상자의 개수
int box[1001][2];	// 상자의 크기, 넣을 수 있는 상자의 수
int max_cnt = 1;	// 최대 상자의 수

void Sol(int n) {
	for (int i = 0; i < n; i++) {	// 앞의 상자들 중
		// 상자 크기가 크고 넣을 수 있는 상자의 수가 더 많은 경우
		if (box[i][0] < box[n][0] && box[i][1] >= box[n][1]) {
			max_cnt = max(max_cnt, box[i][1] + 1);
			box[n][1] = box[i][1] + 1;	
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> box[i][0];
		box[i][1] = 1;

		if (i != 0) {
			Sol(i);
		}
	}
	cout << max_cnt;
}
