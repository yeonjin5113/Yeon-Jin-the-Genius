#include <iostream>

using namespace std;

int T, n;
int arr[2][100000]; 
int dp[100000][3];  // dp[k][0] : k번째 열에서 스티커를 하나도 떼지 않는다.
                    // dp[k][1] : k번째 열의 첫 행의 스티커를 뗀다.
                    // dp[k][2] : k번째 열의 두 번째 행의 스티커를 뗀다.

void Input() {
  cin >> n;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      int score;
      cin >> score;
      arr[i][j] = score;
    }
  }
}

void DP() {
  dp[0][0] = 0;  // 하나도 안 떼면 0점
  dp[0][1] = arr[0][0];  // 첫 행의 스티커를 떼면 arr[0][0]에 저장된 스티커 점수
  dp[0][2] = arr[1][0];  // 두 번째 행의 스티커를 떼면 arr[0][1]에 저장된 스티커 점수
  
  for (int i = 1; i < n; i++) {
    /*
      하나도 안 떼면, 직전 열까지의 점수 경우의 수들 중, 최대값 저장
      dp[i - 1][0] : xx   dp[i - 1][1] : ox   dp[i - 1][2] : xx
                     xx                  xx                  ox
    */
    dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));  

    /*
      첫 번째 행의 스티커를 떼면, 직전 열에서 하나도 안 뗀 경우와, 두 번째 열에서 뗀 경우 중, 큰 값
      dp[i - 1][0] : xo   dp[i - 1][2] : xo
                     xx                  ox
    */
    dp[i][1] = arr[0][i] + max(dp[i - 1][0], dp[i - 1][2]);

    /*
      두 번째 행의 스티커를 떼면, 직전 열에서 하나도 안 뗀 경우와, 첫 번째 열에서 뗀 경우 중, 큰 값
      dp[i - 1][0] : xx   dp[i - 1][2] : ox
                     xo                  xo
    */
    dp[i][2] = arr[1][i] + max(dp[i - 1][0], dp[i - 1][1]);
  }
}

int main(void) {
  cin >> T;
  for (int t = 0; t < T; t++) {
    Input();
    DP();
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;  // 최대값 출력
  }
}
