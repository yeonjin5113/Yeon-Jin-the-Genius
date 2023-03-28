//19m22s

#include <iostream>
#include <queue>
using namespace std;

void card(int n) {
	queue<int> qu;

	for (int i = 1; i <= n; i++) {
		qu.push(i);			// 1 ~ n까지 큐에 넣음
	}
	/*카드가 한장 남을 때까지 반복*/
	while (qu.size() != 1) {
		cout << qu.front() << " ";		//가장 위에 있는 카드를 버림	
		qu.pop();
		qu.push(qu.front());		//그 다음 카드를 아래로 옮김
		qu.pop();
	}
	cout << qu.front();		//마지막에 남은 카드 출력
}

int main() {
	int N;		// 카드의 수

	cin >> N;
	card(N);
}
