#include <iostream>
using namespace std;
int main()
{
    int sum=0 ;
    char a[9];
    for( int i=0; i<9 ; i++)
    {
        cin >> a[i];
    }
    for( int i=0 ; i<9 ; i++)
    {
        sum+=(10-i)*(a[i]-48);
    }
    for( int i=0 ; i<9 ; i++ )
    {
        if( i==0 || i==3 || i==8 ) cout << a[i] << "-" ;
        else cout << a[i];
    }
    a[9]=11-(sum%11)+48;
    if ( a[9]==58 ) cout << "X" ;
    else
    cout << a[9] ;
}