#include <iostream>
using namespace std;

int N, M;	// 앞마당의 길이, 대회시간
int arr[101];
int s = 1;
int max_size = 0;

void snow(int size, int pos, int time) {
	if (pos == N || time == M) {
		max_size = max(max_size, size);
		return;
	}

	for (int i = 0; i < 2; i++) {
		if (i == 0) {	// 눈을 굴리는 경우
			snow(size + arr[pos + 1], pos + 1, time + 1);
		}
		else {	// 눈을 던지는 경우
			snow(size / 2 + arr[pos + 2], pos + 2, time + 1);
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	snow(s, 0, 0);
	cout << max_size;
	return 0;
}
