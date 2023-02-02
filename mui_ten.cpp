#include <iostream>
using namespace std;

void printArrow( int n, bool left )
{
    if( left ){
        for( int i=-n+1 ; i<n ; i++){
            for( int j=0 ; j<n ;j++){
                if( (i<=0 && j>=n-1+i) || (i>0 && j>=n-1-i) ) cout << "*";
                else cout << "  ";
            }
            cout << '\n';
        }
    }
    else if (!left){
        for( int i=-n+1 ; i<n ; i++){
            if( i<=0 ){
                for( int j=0 ; j<-i ; j++) cout << " ";
                for( int j=0 ; j<-i+1 ; j++) cout << "*";
            }
            else {
                for( int j=0 ; j<i ; j++) cout << " ";
                for( int j=0 ; j<i+1 ; j++) cout << "*";
            }
            cout << '\n';
        }
    }
}
int main()
{
    int n;
    cin >> n;
    bool chieu;
    cin >> chieu;
    printArrow(n , chieu);
    return 0;
}