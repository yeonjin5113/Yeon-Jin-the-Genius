//1

#include <iostream>
#include <queue>
using namespace std;

vector<int> vec;

int d(int n) {	// 각각의 자리수를 더하는 함수
	int num = n;
	num += num / 1000 + (num % 1000) / 100 + (num % 100) / 10 + (num % 10);

	return num;
}

void self_number() {
	int i = 1;
	while (i < 10000) {
		int n = d(i) - 1;		// 생성자를 찾음
		if (n < 10000) {		// 10000보다 높은 숫자가 나오기 때문에 작을 때로 함...
			/*처음엔 n<10000을 때로 했는데 왜 안 되는지 모르겠음*/
			vec[n] = 0;			// 생성자가 있는 숫자는 벡터를 0으로 만듦
		}
		i++;
	}
	/*출력*/
	for (int i = 0; i < 10000; i++) {
		if (vec[i] != 0) {
			cout << vec[i] << endl;		// 생성자가 없는 숫자만 출력함
		}
	}
}

int main() {

	for (int i = 1; i <= 10000; i++) {
		vec.push_back(i);			// 1 ~ 10000까지의 숫자를 벡터에 넣음
	}
	
	self_number();			// 셀프넘버인지 확인하기
	return 0;
}
