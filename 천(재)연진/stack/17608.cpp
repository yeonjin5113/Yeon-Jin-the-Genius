/*13m27s*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, h;	//N : 막대기의 개수, h : 막대기의 높이
	vector<int> height;	//막대기의 높이 배열

	int t, cnt=1;	//t : 가장 높이가 높은 막대, cnt : 보이는 막대의 수

	/*입력*/
	cin >> N;	//막대기의 수 입력
  //막대기별 높이
	for (int i = 0; i < N; i++) {
		cin >> h;
		height.push_back(h);
	}

	t = height[N-1];
	for (int i = N - 2; i >= 0; i--) {
		/*더 높으면 카운트*/
		if (t < height[i]) {
			t = height[i];
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
