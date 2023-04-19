// 28m 11s

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> box;		// 선물의 수
queue<int> kid;		// 아이가 원하는 선물의 수

void result() {
	if (kid.empty()) {	// 모든 아이가 선물을 받아감
		cout << "1";
	}
	else {
		cout << "0";
	}
}

void gift() {
	int num;

	while (!kid.empty()) {
		if (box.top() >= kid.front()) {		// 아이가 원하는 만큼 선물이 있다면
			num = box.top();
			num -= kid.front();		// 아이가 원하는 수만큼 선물 수에서 빼줌
			box.pop();
			box.push(num);
			kid.pop();		// 아이가 선물을 가져갔다면 큐에서 pop
		}
		else {	// 아이가 원하는 만큼 선물이 없으면 반복문을 나옴
			break;
		}
	}
}

int main() {
	int N;		// 선물상자의 수
	int M;		// 선물 받을 아이들
	int num;	// 선물의 수

	cin >> N >> M;

	while (N--) {
		cin >> num;
		box.push(num);		// 선물의 개수 저장
	}
	while (M--) {
		cin >> num;
		kid.push(num);		// 아이가 원하는 선물의 수 저장
	}
	gift();
	result();

	return 0;
}
