#include <iostream>
#include <string>
#include <stack>

using namespace std;

int T;  // 테스트 케이스의 수

/*
    입력 문자열이 올바른 괄호 문자열인지 검사하는 함수
    VPS의 조건 1. '('와 ')'의 수가 같아야 한다.
    VPS의 조건 2. ')'의 앞에는 최소 한개 이상의 '('가 있어야 한다.
    VPS의 조건 3. '('의 뒤에는 최소 한개 이상의 ')'가 있어야 한다.

    s: 검사할 괄호 문자열
    return: 올바르면 true, 아니면 false를 반환
*/
bool IsVPS(string s) 
{
    stack<char> stck;

    // 문자열의 각 문자를 순서대로 확인한다.
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {  // '('를 만나면 스택에 push한다.
            stck.push(s[i]);
        } else {  // ')'를 만나면
            if (stck.empty()) {  // '('가 없다면 false를 반환
                return false;
            } else {  // '('가 있다면 pop한다
                stck.pop();
            }
        }
    }

    if (!stck.empty()) {  // 문자열이 끝난 뒤에도 스택에 '('가 남아있다면 false를 반환
        return false;
    }

    // '('가 남아있지 않다면 true 반환
    return true;
}

/*
    괄호 문자열을 입력받아 VPS 검사를 진행한 뒤, 검사 결과를 출력하는 함수
*/
void Solution()
{
    string str;  // 괄호 문자열
    cin >> str;  // 괄호 문자열 입력

    if (IsVPS(str)) {  // str이 올바른 괄호 문자열이면 "YES" 출력
        cout << "YES" << endl;  
    } else {  // 아니면 "NO 출력"
        cout << "NO" << endl;
    }
}

int main(void)
{
    cin >> T;  // 테스트 케이스의 수를 입력

    for (int i = 0; i < T; i++) {
        Solution();  // 테스트 케이스 횟수만큼 문제를 풀이
    }

    return 0;
}