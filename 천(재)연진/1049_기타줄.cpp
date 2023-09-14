#include <iostream>
#include <algorithm>
using namespace std;

int N, M;	// N : 끊어진 기타줄의 수, M : 기타줄 브랜드의 수

int price[51][2];	// 패키지의 가격과, 낱개의 가격
int piece = 10000, pack = 10000;

int Cal() {
	int s = N / 6;	// 몫
	int r = N % 6;	// 나머지

	long long result1;
	long long result2;

	result1 = pack * s +  piece * r;	// 섞어서 사는 경우
	// 패키지로만 사는 경우
	if (N % 6 == 0) {
		result2 = pack * s;
	}
	else {
		result2 = pack * (s + 1);
	}	
	
	return min(result1, result2);  // 둘 중 작은 값 출력

}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> price[i][0] >> price[i][1];
		// 낱개와 세트의 최솟값
		piece = min(piece, price[i][1]);
		pack = min(pack, price[i][0]);
	}
	pack = min(piece * 6, pack);

	cout << Cal();

}
