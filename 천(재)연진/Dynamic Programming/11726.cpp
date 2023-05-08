#include <iostream>
using namespace std;

int arr[1001];
int n;
int  num1, num2;

int DP(int i) {

	if (arr[i] == 0) {
		num1 = DP(i - 1);
		num2 = DP(i - 2);
		arr[i] = (num1 + num2) % 10007;
		return arr[i];
	}
	else {
		return arr[i];
	}
}

int main() {
	cin >> n;

	arr[1] = 1;
	arr[2] = 2;

	int num = DP(n);
	cout << num;

}
