#include <iostream>
#include <windows.h>
using namespace std;

void TextColor(int x)//X là mã màu
{
 //Các hàm này là hàm thao tác API với windows bạn cứ coppy thôi không cần phải hiểu quá sâu
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

int main()
{
    int k=0;
    for( int i=0 ; i<=10 ; i++){
        system("cls");
        for( int j=0 ; j<=10 ; j++){
            if( j<k ) {
                TextColor( 7*16 + 0 );
                cout << " ";
                TextColor( 0 + 7 );
            }
            else cout << " ";
        }
        k++;
        cout << endl << "Loadingg... " << i*10 << "%" ;
        Sleep(250);
    }
    cout << endl << "Complete !!!";
}