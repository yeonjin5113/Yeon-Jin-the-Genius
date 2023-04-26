// 28m57s

#include <iostream>
#include <set>
#include <string>
using namespace std;

int n;	// 카드의 수
int k;	// 선택할 카드의 수
int arr[10];	// 상근이가 뽑은 카드를 저장할 배열
bool visit[10] = { false };
set<int> numbers;	// 상근이가 만든 정수 저장


void com(int cnt, string num1) {	// cnt : 뽑은 카드의 수
	if (cnt == k) {	// 선택해야하는 만큼 뽑은 경우
		numbers.insert(stoi(num1));	// string을 int로 바꿔 set에 저장
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {	// 똑같은 카드를 두번 뽑을 수 없기 때문에 방문한 적있는지 확인
				visit[i] = true;	// 방문한 곳은 true로 바꿈
				string num2 = num1;
				num2 += to_string(arr[i]);	// 숫자 나열
				com(cnt + 1, num2);		// 뽑은 횟수와 나열한 숫자를 com에 넣음
				// cnt++로 처음에 했는데 왜 cnt가 증가하지 않는지 모루겠
				visit[i] = false;	
			}
			
		}
	}
}

int main() {
	cin >> n >> k;

	/* 뽑은 카드 저장 */
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	com(0, "");
	cout << numbers.size();
}
