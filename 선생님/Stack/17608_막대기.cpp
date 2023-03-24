#include <iostream>
#include <stack>

using namespace std;

int N;  // the number of sticks
stack<int> stck;  // container of sticks

// Count viewable sticks
int Count()
{
    // max: refers to heighest stick among currently checked sticks
    // ret: the number of sticks which are in vision
    int max = 0, ret = 0;
    
    // check all the sticks, starting from right end to left
    while (!stck.empty()) {
        if (stck.top() > max) {  // if find stick higher than previous heighest stick,
            ret++;  // count it
            max = stck.top();  // replace the heighest stick
        }
        stck.pop();  // move on to next stick
    }
    
    return ret;
}

void Solution()
{
    cin >> N;
    
    // fill stack from left to right
    // one on the right end will be on top of the stack
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        stck.push(n);
    }
    
    cout << Count() << endl;
}

int main()
{
    Solution();
}
