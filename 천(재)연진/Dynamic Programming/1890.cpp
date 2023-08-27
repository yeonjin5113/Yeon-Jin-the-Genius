#include <iostream>

using namespace std;

int N, arr[100][100];
long long dp[100][100];  // dp[i][j] : 0, 0에서 i, j로 이동 가능한 경우의 수

void Input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }
}

void DP() {
  dp[0][0] = 1;  // 0, 0에서 0, 0으로 이동하는 방법은 한 가지.
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      
      // (i + arr[i][j]) == (i + 0) == i < N
      // 위 부등식이 성립하므로 아래의 분기문들의 조건이 true가 됨
      // 각 분기문의 내부 연산은 dp[i + arr[i][j]][j] == dp[i + 0][j] == dp[i][j]
      // 즉, dp[i][j]에 대한 연산을 중복으로 수행하므로, arr[i][j] == 0에 대해서는 연산을 건너 뜀.
      if (arr[i][j] == 0) {
        continue;
      }

      
      if (i + arr[i][j] < N) {  // 수직 방향으로 점프했을 때, 지도를 벗어나지 않는다면
        dp[i + arr[i][j]][j] += dp[i][j];  // 도착 지점에, 경우의 수를 추가한다.
      }
      if (j + arr[i][j] < N) {  // 수평 방향으로 점프했을 때, 지도를 벗어나지 않는다면
        dp[i][j + arr[i][j]] += dp[i][j];  // 도착 지점에, 경우의 수를 추가한다.
      }
    }
  }
}

void Sol() {
  Input();
  DP();
  cout << dp[N - 1][N - 1];
}

int main(void) { Sol(); }
