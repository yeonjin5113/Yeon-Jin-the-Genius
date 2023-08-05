#include <iostream>
using namespace std;

long long W, H, f, c, x_1, y_1, x_2, y_2;
long long cnt = 0;

void Sol() {
	if (f * 2 <= W) {
		if (f + x_2 <= W) {	// cnt 포함됨
			if (f - x_1 > 0 && f - x_2 >= 0) {	// 반대편도 완전 겹침
				cnt *= 2;
			}
			else if (f - x_1 > 0 && f - x_2 < 0) {	// 왼쪽 끝나는 지점이 0보다 작을 경우
				cnt += (f - x_1) * (y_2 - y_1);		// 겹쳐지는 부분만 구함
			}
		}
	}
	else {	// 왼쪽이 넘어간 경우
		if (f + x_1 < W) {
			if (f + x_2 <= W) {		// 양쪽이 모두 색칠되는 경우
				cnt *= 2;
			}
			else if (f + x_2 > W) {	// 왼쪽면에만 색칠이 안 되는 경우 경우
				cnt += (W - f - x_1) * (y_2 - y_1);	// 오른쪽 색칠되지 않는 부분만 구함
			}
		}
	}

	cout << W * H - cnt * (c + 1);	// 색칠되지 않는 곳 * 나눈 구간 수
}

int main() {
	cin >> W >> H >> f >> c >> x_1 >> y_1 >> x_2 >> y_2;

	//처음 색칠되지 않는 부분의 크기
	cnt = (x_2 - x_1) * (y_2 - y_1);
	Sol();
}
