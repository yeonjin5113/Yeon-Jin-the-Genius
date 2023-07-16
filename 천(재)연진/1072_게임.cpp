#include <iostream>
using namespace std;

long long X, Y;	// 게임횟수, 이긴 게임
int Z;	// 승률


int main() {
	cin >> X >> Y;

	Z = Y * 100 / X;	// 현재의 승률
	int Z_1;	// 바뀐 승률
	
	if (Z >= 99) {	// 승률이 100이 될 수 없고, 100일 경우에는 더 높아질 수 없음
		cout << -1;
	}
	else {
		long long n;
		n = (X * Z + X - 100 * Y) / (99 - Z);

		while (1) {
			Z_1 = (Y + n) * 100 / (X + n);

			if (Z < Z_1) {	// 바뀐 승률이 더 클 경우
				cout << int(n);		// 게임횟수 출력
				break;	// 반복문 종료
			}
			else {	// 게임횟수를 증가시켜서 승률계산함
				n += 1;
			}
		}
		
	}

}
