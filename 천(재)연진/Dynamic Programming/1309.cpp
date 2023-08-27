#include <iostream>

using namespace std;

/*
  dp[k][0] : xx   dp[k][1] : ox   dp[k][2] : xo
*/
long long N, dp[100000][3]; 

void DP() {
  dp[0][0] = 1;  // 첫 번째 줄에 새우는 경우의 수는 전부 1
  dp[0][1] = 1;
  dp[0][2] = 1;

  for (int i = 1; i < N; i++) {
    /*
      i - 1 : xx   ox   xo   세 가지 모두 가능
      i     : xx   xx   xx 
    */
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];

    /*
      i - 1 : xx   xo   두 가지만 가능
      i     : xx   ox 
    */
    dp[i][1] = dp[i - 1][0] + dp[i - 1][2];

    /*
      i - 1 : xx   ox   두 가지만 가능
      i     : xx   xo 
    */
    dp[i][2] = dp[i - 1][0] + dp[i - 1][1];

    // 문제 조건
    for (int j = 0; j < 3; j++) {
      dp[i][j] %= 9901;
    }
  }
}

void Sol() {
  cin >> N;
  DP();
  cout << (dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2]) % 9901;  // 가능한 모든 경우의 수 출력
}

int main(void) { Sol(); }
