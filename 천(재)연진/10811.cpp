#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;  // N : 바구니의 수, M : M번 역순으로
    int i, j;
    vector<int> vec;
    
    cin >> N >> M;

    for (int n=0; n< N; n++){
        vec.push_back(n+1);
    }
    
    for (int n=0; n<M; n++){
        cin >> i >> j;
        reverse(vec.begin()+i-1, vec.begin()+j);
    }
    
    for (int n=0; n<N; n++){
        cout << vec[n] << " ";
    }
}
