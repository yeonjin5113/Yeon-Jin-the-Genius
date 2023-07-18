#include <iostream>
#include <cmath>
using namespace std;

int x_1, y_1, r_1, x_2, y_2, r_2;

int Sol() {
	int r1 = max(r_1, r_2);
	int r2 = min(r_1, r_2);	
	double d = sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2));		// 두 점 사이의 거리

	if (d == 0 && r1 == r2) {	// 동일한 원일 경우
		return -1;
	}
	else if (d > r1 + r2 || r1-r2 > d) {	// 두 원이 서로 떨어져있을 경우, 하나의 원 안에 있을 경우
		return 0;
	}
	else if (d == r1 + r2 || d == r1 - r2) {	// 외접하거나 내접하는 경우
		return 1;
	}
	else if (d<r1 + r2 && r1 - r2<d) {
		return 2;
	}
}

int main() {
	int T;	// 테스트케이스 수
	cin >> T;

	while (T--) {
		cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
		cout << Sol() << endl;
	}
}
