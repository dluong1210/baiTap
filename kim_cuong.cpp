#include <iostream>
#include <windows.h>

using namespace std;

void TextColor(int x)//X là mã màu
{
 //Các hàm này là hàm thao tác API với windows bạn cứ coppy thôi không cần phải hiểu quá sâu
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

int main() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    cin >> n ;
    for ( int a=-n ; a<=n ; a++ ) {
        TextColor( abs(a)*16 + 5 );
        for ( int b=-n ; b<=n ; b++ ) {
            if ( a<0 ) {
                if( b>(a+n) || b<-(a+n) ) cout << ". ";
                else cout << "* " ;
            }
            else {
                if ( b<-(n-a) || b>(n-a) ) cout << ". ";
                else cout << "* " ;
            }
        }
        cout << '\n' ;
        Sleep(100);
    }
    return 0;
}
        
