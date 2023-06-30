//1h30m
#include <iostream>
using namespace std;

int R, C;
char map[251][251];
int visit[251][251];

int sheep = 0, wolf = 0;
int sheep_num = 0, wolf_num = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, +1, 0, 0 };

// 하나의 울타리에 있는 양과 늑대의 수 비교
void count() {
	if (sheep > wolf) {
		wolf_num = wolf_num - wolf;
	}
	else {
		sheep_num = sheep_num - sheep;
	}
	sheep = 0;
	wolf = 0;
}

// 양과 늑대의 수 구하기
void result(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 울타리일 경우에는 이동하지 못함
		if (0 <= nx && nx < C && 0 <= ny && ny < R) {
			if (map[ny][nx] == 'v' && visit[ny][nx] == 0) {
				visit[ny][nx] = 1;
				wolf++;
				result(nx, ny);
			}
			else if (map[ny][nx] == 'o' && visit[ny][nx] == 0) {
				visit[ny][nx] = 1;
				sheep++;
				result(nx, ny);
			}
			else if (map[ny][nx] == '.' && visit[ny][nx] == 0) {
				visit[ny][nx] = 1;
				result(nx, ny);
			}
		}
	}
}

int main() {
	cin >> R >> C;	// 세로, 가로 입력 받음

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c;	
			cin >> c;
			map[i][j] = c;

			// 늑대와 양의 수 저장
			if (c == 'v') {
				wolf_num++;
			}
			else if (c == 'o') {
				sheep_num++;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if ((map[i][j] == 'v' || map[i][j] == 'o') && (visit[i][j] == 0)) {
				if (map[i][j] == 'v') {
					++wolf;
				}
				else {
					++sheep;
				}
				visit[i][j] = 1;
				result(j, i);	
				count();		
			}
		}
	}

	cout << sheep_num << " " << wolf_num;

}
