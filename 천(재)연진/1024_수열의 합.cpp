#include <iostream>
using namespace std;

long double N, L;

void Sol(int l) {
	if (l > 100) {
		cout << -1;
		return;
	}
	long double first_num = (2 * N - l * (l + 1)) / (2 * l);	// 등차수열 공식 이용해서 첫번째 오는 숫자 구하기

	if (int(first_num) == first_num && first_num >=-1) {	// 숫자가 정수이고 -1보다 크면
		for (int i = 1; i <= l; i++) {	// 수열 출력
			cout << int(first_num + i) << " ";	
		}
	}
	else {	// 그렇지 않을 경우 수열의 길이를 늘림
		Sol(l + 1);
	}

}

int main() {
	cin >> N >> L;
	Sol(L);
}
