#include <iostream>
using namespace std;

int N, M;
int square[51][51];
int square_size = 0, max_size = 0;
int cnt = 0;

/*
P1(x, y)	 P2(x + s, y)
P3(x, y + s)   P4(x + s,y + s)
*/

void Sol(int n, int x, int y) {

	if (cnt == 0) {
		for (int i = x + 1; i < M; i++) {
			if (square[y][i] == n) {	// P2
				square_size = i - x;	// 정사각형 크기
				if (y + square_size >= N) {	// 주어진 범위에서 넘어가면 반복문 종료
					break;
				}
				cnt++;
				if (cnt == 1) {	// P3
					if (square[y + square_size][x] == n) {
						cnt++;
					}
				}
				if (cnt == 2) {	// P4
					if (square[y + square_size][x + square_size] == n) {	// 정사각형이 만들어지면
						max_size = max(square_size, max_size);	// 값을 비교해 큰 값을 저장
					}
				}
				cnt = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	string number;

	/* 숫자 하나씩 받아오기 */
	for (int i = 0; i < N; i++) {	// 세로
		cin >> number;
		for (int j = 0; j < M; j++) {	// 가로
			square[i][j] = number[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num = square[i][j];
			cnt = 0;
			Sol(num, j, i);		// P1
		}
	}
	if (max_size == 0) {
		cout << 1;
	}
	else {
		cout << (max_size + 1) * (max_size + 1);
	}

}
