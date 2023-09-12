// 거의 다 풀었는데 살짝 보고 풀었음..

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int price[10002];
int P[10002];

void Sol() {
	price[1] = P[1];

	for (int i = 2; i <= N; i++) {
		price[i] = P[i];	// i개 들어있는 카드팩의 가격
		for (int j = 1; j < i; j++) {
			// 
			price[i] = max(price[i], price[j] + price[i - j]);	
		}
	}
}

int main() {
	cin >> N;	// 구매하고자 하는 카드의 수

	// 카드의 가격 입력
	for (int i = 1; i <= N; i++) {
		cin >> P[i];	
	}

	Sol();
	cout << price[N];
}
