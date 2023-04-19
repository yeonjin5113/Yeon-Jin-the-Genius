// 49m

#include <iostream>
#include <queue>
using namespace std;

queue<int> que;

void game() {
	long long t = 1;

	while (que.size() != 1) {
		long long n = (t * t * t) % que.size();		// (t^3) % 사람의 수 나머지를 구함
		if (n == 0) {			// 나머지가 0이면 
			n += que.size();	// 제일 마지막에 있는 사람이므로 인원수만큼 더해줌
		}
		for (int i = 1; i < n; i++) {
			que.push(que.front());		
			que.pop();
		}
		que.pop();		// t^3을 외칠 때 앞에 있는 사람 제거
		t++;
	}
	cout << que.front();	// 마지막에 남은 사람 출력
}

int main() {
	int N;		// 참가자의 수
	int i = 1;		// 참가자 번호
	cin >> N;

	while (N--) {
		que.push(i++);
	}
	game();
	return 0;
}
