//13m10s
// 풀었던거라 얼마 안 걸리네요 ㅎㅎ

#include <iostream>
#include <queue>
using namespace std;

queue<int> que;
int max_size = 0;		// 초기에는 que가 비어 있기 때문에 0으로 설정
int student_number = 100000;		// 학생 번호를 최대로 설정

void output() {
	cout << max_size << " " << student_number;
}

void line(int A, int a) {
	if (A == 1) {		// 유형 1의 경우에는 학생을 맨 뒤에 저장
		que.push(a);
		if (que.size() > max_size		// 기다리는 학생의 수가 최대거나
		|| (que.size() == max_size && student_number > a)) {	// 대기하는 학생 수는 같지만 맨 뒤에 줄서는 학생이 가장 작은 경우
			max_size = que.size();		// 최대 대기 인원 변경
			student_number = a;			// 맨 뒤에 줄 선 학생의 번호 저장
		}
	}
	else {
		que.pop();
	}
}

int main() {
	int n;		// 식사가 준비되는 n개의 정보
	int A, a;
	cin >> n;

	while (n--) {
		cin >> A;
		if (A == 1) {	// 유형 1일 경우 줄서는 학생의 번호도 입력받음
			cin >> a;
			line(A, a);
		}				// 유형 1의 경우에는 한명이 식사를 함
		else {
			line(A, 0);
		}
	}
	output();
	return 0;
}
