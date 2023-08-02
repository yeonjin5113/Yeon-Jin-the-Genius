#include <iostream>
#include <cmath>
using namespace std;

int dx[3] = { 1, 0, 1 };
int dy[3] = { 0, 1, 1 };
long long cnt = 0;
long long N, r, c;

void Sol(int x, int y) {
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		cnt++;
		if (nx == c && ny == r) {
			return;
		}
		
	}
}

int main() {
	cin >> N >> r >> c;

	long long num = pow(2, N);
	long long sum = 0 ,n = 0;

	while (num != 2) {	// 2*2 배열이 될 때까지 배열을 4등분함
		num = num / 2;
		sum = num * num;
		if (c < num && r < num) {	// 왼쪽 위
			n = n;
		}
		else if (c >= num && r < num) {	// 오른쪽 위
			n += sum;	// 첫번재로 방문
		}
		else if (c < num && r >= num) {	// 왼쪽 아래
			n += (sum * 2);		// 두번째로 방문
		}
		else {	//오른쪽 아래	
			n += (sum * 3);		// 세번째로 방문
		}
		r = r % num;
		c = c % num;
	}

	if (r != 0 || c != 0) {	// 2*2 배열에서 방문하는 순서 찾기
		Sol(0, 0);
	}
	

	cout << cnt + n;
}
