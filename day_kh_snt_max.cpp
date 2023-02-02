#include <iostream>
using namespace std;
int main()
{
    int n, max=0, day=0, nho;
    cin >> n;
    for( int i=1 ; i<=n ; i++){
        int dem=0;
        for( int j=1 ; j<=i ; j++){
            if( i%j==0 ) dem++;
        }
        if( dem!=2 ){
            day++;
            if( day>max ){
                max=day;
                nho=i;
            }
        }
        else if( dem==2){
            day=0;
        }
    }
    for( int i=nho-max+1 ; i<=nho ; i++){
        cout << i << " ";
    }
    return 0;
}