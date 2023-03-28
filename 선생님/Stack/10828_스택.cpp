#include <iostream>

using namespace std;

// 단수한 형태의 stack을 구현한 구조체
// stack용 함수는 멤버함수로 구현하지 않음
typedef struct _Stack
{
    int arr[10000];  // 데이터를 저장하는 배열
    int size = 0;  // 데이터의 수
} Stack;

int N;  // 명령의 수

// 정수 n을 stack에 push한 뒤, size를 1 늘림
void Push(Stack& stack, int n)
{
    stack.arr[stack.size] = n;
    stack.size++;
}

// stack의 top을 출력한 뒤 사이즈를 1 줄이는 함수
void Pop(Stack& stack)
{
    if (stack.size == 0) {
        cout << -1 << endl;
    } else {  // size만 줄이는 이유는 다음 pop에 어차피 기존 데이터가 지워지기 떄문
        cout << stack.arr[stack.size - 1] << endl;
        stack.size--;
    }
}

// size를 출력하는 함수
void Size(Stack& stack)
{
    cout << stack.size << endl;
}

// stack에 데이터가 있는지 없는지를 출력
void Empty(Stack& stack)
{
    if (stack.size == 0) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

// stack의 top을 출력하는 함수, pop과 달리 삭제 연산이 없음
void Top(Stack& stack)
{
    if (stack.size == 0) {
        cout << -1 << endl;
    } else {
        cout << stack.arr[stack.size - 1] << endl;
    }
}

void Solution()
{
    Stack stack;

    cin >> N;  // 명령 횟수 입력

    for (int i = 0; i < N; i++) {
        string cmd;  // 명령
        cin >> cmd;  // 명령 입력

        // 각 명령어에 따른 명령 수행
        if (cmd == "push") {
            int num;
            cin >> num;
            Push(stack, num);
        } else if (cmd == "pop") {
            Pop(stack);
        } else if (cmd == "size") {
            Size(stack);
        } else if (cmd == "empty") {
            Empty(stack);
        } else if (cmd == "top") {
            Top(stack);
        } else {
            return;
        }
    }
}

int main(void)
{
    Solution();
}