#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> stck;

bool IsBalanced(string str){
    for (int i = 0; i < str.size() - 1; i++) {  // 마지막 온점을 제외한 모든 문자열을 검사
        if (str[i] == '[' || str[i] == '(') {  // 여는 괄호는 push
            stck.push(str[i]);
        } else if (str[i] == ']' || str[i] == ')') {  // 닫는 괄호는 stack을 검사
            if (stck.empty()) {  // 여는 괄호가 없다면 false 반환
                return false;
            }
            if (stck.top() == '(' && str[i] == ']' 
            || stck.top() == '[' && str[i] == ')') {  // 닫는 괄호가 다른 종류의 여는 괄호와 매칭된다면 false
                return false;
            } else {  // 아니라면 한 쌍으로 취급하고 pop
                stck.pop();
            }
        }
    }

    if (!stck.empty()) {  // 여는 괄호가 남아있다면 false 반환
        return false;
    }

    // 모든 괄호가 짝이 지어졌다면 true 반환
    return true;
}

void Solution()
{
    while(1) {
        string str;
        getline(cin, str);  // 공백을 포함한 입력 받기

        if (str == ".") {  // 입력의 종료
            break;
        }

        if (IsBalanced(str)) {  // 문자열이 균형 잡혔다면 yes 출력
            cout << "yes" << endl;
        } else {  // 아니면 no 출력
            cout << "no" << endl;
        }
        
        while(!stck.empty()) {
            stck.pop();
        }
    }
}

int main(void)
{
    Solution();
}