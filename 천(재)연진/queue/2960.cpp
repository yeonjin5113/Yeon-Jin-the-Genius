// 1H06M
// 다시 풀었는데도 무려 1시간이 걸림;~;

#include <iostream>
#include <queue>
using namespace std;

void eratos(int n, int k) {
	queue<int> que;
	int i = 2;
	int cnt = 1;	// 지울 숫자를 찾기 위해 카운트함
	int P = 2;		// 정수 (2부터 시작되기 때문에 2가 가장 처음 소수인 숫자)
	int number = 2;		// 가장 최근에 지워진 숫자
	int j = 0;		// 큐의 사이즈를 확인하기 위해
		// 큐의 사이즈 만큼 다 돌면 지우지 않은 수 중 가장 작은 수를 찾기 위해 필요

	n -= 1;
	while (n--) {	// 2 ~ N까지의 정수를 큐에 저장
		que.push(i++);
	}

	que.pop();		// 가장 처음의 소수인 2를 제거
	int size = que.size();

	while (cnt != k) {		// K번째 지우는 수가 나올 때까지 반복
		if (que.front() % P == 0) {		// P의 배수를 순서대로 지움
			cnt++;
			number = que.front();
			que.pop();
		}
		else {	// P의 배수가 아니라면 가장 맨 뒤로 보냄
			que.push(que.front());
			que.pop();
		}
		j++;
		if (j == size) {		// 큐의 사이즈만큼 돌았는데 아직 K번째 수를 찾지 못했다면
			
			if (cnt == k) {
				break;
			}
			P = que.front();	// 지우지 않은 수 중 가장 작은 수를 P로 놓음
			number = P;
			que.pop();
			size = que.size();
			j = 0;
			cnt++;				// 가장 앞에 있는 숫자를 지웠기 때문에 cnt 증가
			
		}
	}
	cout << number;
}

int main() {
	int N;		// 정수
	int K;		// 지울 번호의 순서

	cin >> N >> K;
	eratos(N, K);

	return 0;

}
