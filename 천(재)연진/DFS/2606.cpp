// 43분쯤...?

#include <iostream>
#include <set>
#include <queue>
using namespace std;

int n, p;			// 컴퓨터의 수, 연결된 쌍의 수
set<int> s;			// 바이러스에 걸린 컴퓨터 저장
int arr[101][101];	// 컴퓨터의 최대 수 (1 ~ 100까지 쓰기 위해 크기는 101로함)

void check(int num) {
	for (int i = 1; i <= n; i++) {
		if (arr[num][i] == 1) {	// 바이러스에 걸린 네트워크인 경우
			if (i != 1) {	// 1로 인해 바이러스에 감염된 것이기 때문에 1은 제외시킴
				s.insert(i);
			}
			arr[num][i] = 0;	// 바이러스에 걸렸다는 것을 알게된 컴퓨터는
			arr[i][num] = 0;	// 0으로 바꿔줌
			check(i);	
		}
	}
}

int main() {
	cin >> n >> p;

	while (p--) {
		int num1, num2;
		cin >> num1 >> num2;
		arr[num1][num2] = 1;	// 네트워크 상 연결되어 있는 컴퓨터들은 1로 저장
		arr[num2][num1] = 1;	// num1과 num2는 네트워크상 연결된 컴퓨터
	}
	check(1);
	cout << s.size();	//  바이러스에 걸린 네트워크 수 출력
}

/*
queue<pair<int, int>> que;
void check(int num) {
	if (que.empty()) {
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		if (num == que.front().first) {
			int com = que.front().second;
			//cout << que.front().first << que.front().second << endl;
			que.pop();
			virus.insert(com);
			check(com);
		}
		else if (num == que.front().second) {
			int com = que.front().first;
			que.pop();
			virus.insert(com);
			check(com);
		}
		else {
			que.push(que.front());
			que.pop();
		}
	}
}

int main() {
	cin >> n >> p;

	while (p--) {
		int num1, num2;
		cin >> num1 >> num2;

		que.push({ num1, num2 });
	}
	check(1);
	cout << virus.size();
	return 0;
}
*/
