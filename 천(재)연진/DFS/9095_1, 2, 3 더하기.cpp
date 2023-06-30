// 50m

#include <iostream>
#include <vector>
using namespace std;

int T;		// 테스트 케이스 수
vector<int> vec;
int cnt = 0;	// 가능한 방법
int arr[3] = { 1, 2, 3 };

void cal(int size, int n) {
	if (size == vec[n]) {	// 만들고자 하는 숫자와 같아지면 증가
		cnt++;
		return;
	}
	else if (size > vec[n]) {	// 사이즈보다 크면 종료
		return;
	}
	for (int i = 0; i < 3; i++) {	// 현재 사이즈에서 1~3까지 더함
		cal(size + arr[i], n);
	}
}

int main() {
	cin >> T;
	int n;

	for (int i = 0; i < T; i++) {	// 테스트 케이스 벡터에 넣기
		cin >> n;
		vec.push_back(n);
	}
	for (int i = 0; i < T; i++) {	// 가능한 수 계산한 후 벡터에 넣음
		cal(0, i);
		vec[i] = cnt;
		cnt = 0;
	}
	for (int i = 0; i < T; i++) {	// 출력
		cout << vec[i] << endl;
	}
}
