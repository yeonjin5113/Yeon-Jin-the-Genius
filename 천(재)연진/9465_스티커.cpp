#include <iostream>
#include <cstring>
using namespace std;

int T;
int sticker[2][100002];
int sum[3][100002] = { {0}, };	// 위, 아래, 선택안함

void Sol(int num) {
	sum[0][1] = sticker[0][1];  // 위를 선택한 경우
	sum[1][1] = sticker[1][1];  // 아래를 선택한 경우
	sum[2][1] = 0;  // 선택하지 않을 경우
	for (int i = 2; i <= num; i++) {
    /* 아래 + 위 순서대로 선택하는 경우, 선택안하고 위를 선택하는 경우
       위 + 아래 순서대로 선택하는 경우, 선택안하고 아래를 선택하는 경우
       이전 값중 큰 값 저장 */
		sum[0][i] = max(sum[1][i - 1] + sticker[0][i], sum[2][i - 1] + sticker[0][i]);
		sum[1][i] = max(sum[0][i - 1] + sticker[1][i], sum[2][i - 1] + sticker[1][i]);
		sum[2][i] = max(sum[0][i - 1], sum[1][i - 1]);
	}
}

int main() {
	cin >> T;

  // 입력받기
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> sticker[i][j];
			}
		}
		Sol(n);
		cout << max(sum[0][n], max(sum[1][n], sum[2][n])) << endl;  // 점수가 가장 큰 값 출력
		memset(sticker, 0, sizeof(sticker));    // 배열 초기화
		memset(sum, 0, sizeof(sum));
	}


}
