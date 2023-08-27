#include <iostream>

using namespace std;

int n, arr[1001], dp[1001];  // dp[i]에는 arr[i]를 포함해 가장 많은 상자를 담은 수. 
                             // dp[i]가 1일 경우, arr[i]보다 큰 상자가 이전에 없으므로, 자신만 담아서 1

void Input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  arr[1000] = 1001;
}

void DP() {
  dp[0] = 1;

  // i = 1, 2, 3 ... 999, 1000 순으로 상자를 담는 경우의 수를 저장해 나간다.
  for (int i = 1; i < 1001; i++) {  
    int maxi = 0;  // 가장 많이 담는 경우의 수
    
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {  // 상자를 담을 수 있다면
        maxi = max(maxi, dp[j]);  // 최대값 갱신
      }
    }
    
    dp[i] = maxi + 1;  // 최대 상자 개수(maxi) + 현재 상자 (1)
  }
}

void Sol() {
  Input();
  DP();
  cout << dp[1000] - 1;  // arr[1000]에는 크기 1001의 가상의 상자가 있으므로, 해당 상자를 빼고 출력
}

int main(void) { Sol(); }
