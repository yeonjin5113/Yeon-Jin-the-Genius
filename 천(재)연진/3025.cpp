#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int input;
    vector<int> vec;
    
    for (int i=0; i<10; i++){
        cin >> input;
        vec.push_back(input%42);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    cout << vec.size();
}
