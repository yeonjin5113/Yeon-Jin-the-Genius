// 29m 56s

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> que;

void result(int H, int cnt) {
	if (que.top() >= H) {	// 거인 중 가장 키큰 사람이 센티보다 크거나 같으면
		cout << "NO" << endl;	// NO를 출력하고
		cout << que.top();		// 키가 가장 큰 거인 출력
	}
	else {	// 모든 거인이 센티보다 작으면
		cout << "YES" << endl;	// YES를 출력하고
		cout << cnt;			// 뿅망치 사용횟수 출력
	}
}

int height(int t, int cm_h) {
	int i = 0;
	while(i < t) {
		int h = que.top();	
		if (h == 1 || que.top() < cm_h) {	// 키가 가장 큰 사람이 1이거나 센티의 키보다 작으면 반복문 나감
			break;
		}
		else {	// 거인 중 가장 키가 큰 사람을 1/2로 줄임
			que.pop();
			que.push(h / 2);
			i++;		// 뿅망치를 사용할 때마다 횟수 증가
		}
	}

	return i;
}

int main() {
	int N;		// 인구수
	int H;		// 센티의 키
	int T;		// 뿅망치 횟수 제한
	int h;		// 거인의 키
	int cnt;

	cin >> N >> H >> T;

	while (N--) {
		cin >> h;
		que.push(h);		// 오름차순으로 거인의 키 저장
	}
	cnt = height(T, H);		// 뿅망치 사용 횟수를 받음
	result(H, cnt);		
	return 0;
}

/*
뿅망치를 맞으면 키가 1/2이 됨
1인 경우는 줄어들지 않음
*/
