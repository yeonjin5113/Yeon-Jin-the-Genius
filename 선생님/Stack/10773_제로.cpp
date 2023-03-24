#include <iostream>
#include <stack>

using namespace std;

long K;  // 입력할 금액의 수, 총 금액이 최대 10^11까지 갈 수 있으므로 long 사용
stack<long> stck;  // 금액을 저장할 장부

void FillStack()
{
    for (int i = 0; i < K; i++) {
        long n;  // 금액
        cin >> n;  // 금액을 입력

        if (n != 0) {  // 장부에 일단 저장
            stck.push(n);
        } else {  // 직전에 적은 금액을 삭제
            stck.pop();
        }
    }
}

long CountTotal()
{
    long total = 0;  // 장부에 적힌 금액들의 총 합
    
    while (!stck.empty()) {  // 장부에 적힌 금액을 모두 확인
        total += stck.top();  // 금액을 총합에 더한 뒤
        stck.pop();  // 해당 금액을 삭제
    }

    return total;
}

void Solution()
{
    cin >> K;  // 입력 횟수를 받아서

    FillStack();  // 금액들로 장부를 채우고

    cout << CountTotal() << endl;  // 장부 속 금액의 총 합을 출력
}

int main(void)
{
    Solution();
}