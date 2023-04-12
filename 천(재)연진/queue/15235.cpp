//50m32s

#include <iostream>
#include <queue>
#include <array>
using namespace std;


typedef struct info
{
	int n;	// 참가자 번호
	int piece;		// 필요한 피자의 수
};

void time(int n) {
	queue<info> qu;
	array<int, 1000> times;
	int num;		// 피자의 수
	int i = 0;		// 참가자 번호
	int t = 1;		// 시간
	
	/*참가자의 번호와 필요한 피자의 수를 저장*/
	for (int i = 0; i < n; i++) {
		cin >> num;
		qu.push({ i, num });
	}

	while (!qu.empty()) {
		qu.front().piece -= 1;
		if (qu.front().piece == 0) {	// 필요한 피자를 모두 받으면
			times[qu.front().n] = t;	// 배열에 피자를 받은 시간 저장
			qu.pop();					// 큐에서 뺌
		}
		else {
			qu.push(qu.front());		// 아직 필요한 피자가 남았다면
			qu.pop();					// 맨 뒤로 옮겨줌
		}
		t++;	// 피자를 받을 때마다 시간 증가
	}
	/*시간 출력*/
	for (int i = 0; i < n; i++) {
		cout << times[i] << " ";
	}
}

int main() {
	int N;		// 참가자의 수
	
	cin >> N;
	time(N);
}
