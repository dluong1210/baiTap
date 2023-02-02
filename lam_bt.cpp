#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> a={5, 4, 3, 2, 1};
    nth_element(a.begin(), a.begin()+2, a.end());
    for( int i=0 ; i<5 ; i++){
        cout << a[i] << endl;
    }
}