// 35m
#include <iostream>
#include <vector>
using namespace std;

int T;		// 테스트 케이스의 개수
long long x_1, y_1, x_2, y_2;    // 출발점, 도착점
int cnt = 0;	// 진입/이탈 횟수

void Sol(int x, int y, int r) {
	long long dis1, dis2;
	dis1 = (x - x_1) * (x - x_1) + (y - y_1) * (y - y_1);    // 출발지점과 행성 사이의 거리
	dis2 = (x - x_2) * (x - x_2) + (y - y_2) * (y - y_2);    // 도착지점과 행성 사이의 거리
	if ((dis1 < r * r && dis2 > r * r) || (dis1 > r * r && dis2 < r * r)) {    // 출발과 도착지점 중 하나의 점만 원안에 있는 경우
		cnt += 1;
	}
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;	// 행성계의 개수
		cin >> x_1 >> y_1 >> x_2 >> y_2;	// 출발점, 도착점
		cin >> n;	
		for (int j = 0; j < n; j++) {
			int x, y, r;
			cin >> x >> y >> r;		// 행성계 중점과 반지름
			Sol(x, y, r);
		}
		cout << cnt << endl;
		cnt = 0;
	}
}
