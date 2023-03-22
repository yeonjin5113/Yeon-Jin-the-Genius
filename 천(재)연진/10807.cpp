#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a,b, c, count=0;
    
    cin >> a;
    
    vector<int> v;
    
    for (int i=0; i<a; i++){
        cin >> b;
        v.push_back(b);
    }
    cin >> c;
    for (int i=0; i<a; i++){
        if (v[i] == c){
            count++;
        }
    }
    cout << count;
    
    return 0;
}
