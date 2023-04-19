// 시간은 모르지만 아마 1시간 걸렸을 듯..

#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> que;

void output(int num, int max) {
	int cnt = 1;

	while (1) {
		if (max == que.front().second &&		// 찾고자 하는 문서의 위치가 같고 그 문서의 우선순위가 가장 높다면
			num == que.front().first) {			// 반복문 종료
			break;
		}
		else if (max == que.front().second) {	// 우선순위가 가장 높은 문서가 오면 그 문서를 출력
			que.pop();
			cnt++;
			int size = que.size();

			max = que.front().second;
			for (int i = 0; i < size; i++) {	// 남은 문서 중 우선순위가 높은 문서를 찾음
				if (max < que.front().second) {
					max = que.front().second;
				}
				que.push(que.front());
				que.pop();
			}
		}
		else {	// 현재 문서보다 중요도가 높은 문서가 있다면 현재 문서를 가장 뒤로 보냄
			que.push(que.front());
			que.pop();
		}
	}
	cout << cnt << endl;
}

void input(int m, int p) {

	int i = 0;		// 문서 번호
	int number;		// 궁금한 문서의 번호
	int priority;	// 우선순위
	int max = 0;	// 현재 문서 중 가장 높은 우선순위

	while (m--) {
		cin >> priority;
		que.push({ i, priority });
		if (p == i) {
			number = i;		// 궁금한 문서가 들어오면 그 문서의 번호 저장
		}
		if (max < priority) {
			max = priority;
		}
		i++;
	}
	output(number, max);
}

int main() {
	int N;		// 테스트케이스의 수
	int M;		// 문서의 중요도
	int P;		// 궁금한 문서의 위치

	cin >> N;
	while (N--) {
		cin >> M >> P;		// 문서의 수, 문서의 위치
		input(M, P);
		que = queue<pair<int, int>>();		// que 초기화
	}
	return 0;
}

/*
문서의 개수(m)		궁금한 문서의 위치(p)
중요도
*/
