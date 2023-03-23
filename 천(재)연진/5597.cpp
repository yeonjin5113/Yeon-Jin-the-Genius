#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    int input, output;
    array<int, 31> arr;
    fill(arr.begin(), arr.end(), 0);
    
    for(int i=0; i<28; i++){
        cin >> input;
        arr[input] = 1;
    }
    /*출력*/
    for (int i=1; i<=30; i++){
        if (arr[i] == 0){
            cout << i << "\n";
        }
    }
    
}
