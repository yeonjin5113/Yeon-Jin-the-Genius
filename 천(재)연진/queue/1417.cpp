//1H15M

#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> que;		// 득표수, 번호
int dasom_vote;

void add_vote() {
	int cnt = 0;

	if (que.size() == 1 || que.top().second == 1) {		// 다솜이 혼자 나가거나 다솜이의 표가 가장 많을 경우에는 그냥 출력
		cout << cnt;
	}
	else {	// 다솜이의 표가 다른 사람보다 적을 경우에는
		while (que.top().first >= dasom_vote) {		 // 다솜이의 표가 가장 높아질 때까지 반복
			int number = que.top().second;		// 현재 가장 많은 표를 받은 번호
			int n = que.top().first;			// 현재 가장 많은 표를 받은 사람의 득표수

			que.pop();
			que.push({ n - 1, number });		// 그 사람의 표를 하나 빼고 다시 저장
			dasom_vote++;		// 다솜이 표에 추가
			cnt++;
		}
		cout << cnt;
	}
		
}

int main() {
	int N;		// 후보의 수
	int vote;
	int n = 1;	// 후보자의 번호

	cin >> N;
	while (N--) {
		cin >> vote;
		if (n == 1) {
			dasom_vote = vote;
		}
		que.push({ vote, n++ });
	}
	add_vote();

	return 0;

}
