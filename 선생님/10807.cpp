#include <iostream>
#include <vector>
#include <algorithm>  // std::count가 포함된 라이브러리

using namespace std;

int main()
{
    int size, target, input, cnt = 0;
    vector<int> vec;

    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> input;
        vec.push_back(input);
    }

    cin >> target;
    
    /*
        std::count
        전달 인자 : 검사할 범위의 처음과 마지막 반복자, 찾으려 하는 값
                    (ex. 처음부터 끝까지 : begin(), end()
                         처음부터 6개만큼 : begin(), begin() + 6
                         n번째 부터 m개만큼 : begin() + n, begin() + n + m)
        반환값 : target 값의 개수
        
        count_if()와의 차이 : count_if는 직접 조건을 수정할 수 있음, count는 조건이 arr[i] == target, 같은 지만 비교할 수 있음
                             (ex. 0이상 6이하의 정수를 세라, "abaedabcdabc"에서 "abc"의 개수를 세라, etc)
    */
    cnt = count(vec.begin(), vec.end(), target);

    cout << cnt << endl;
}a
