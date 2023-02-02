#include <iostream>
#include <string>
//#include <windows.h>
#include <conio.h>

using namespace std;

void TextColor(int x)//X là mã màu
{
 //Các hàm này là hàm thao tác API với windows bạn cứ coppy thôi không cần phải hiểu quá sâu
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}


void print( int sizeBang , int& viTri , string name){
    if( viTri + name.size() >= sizeBang ){
        for( int i=0 ; i<sizeBang ; i++){
            if( i==0 || i==sizeBang-1 ) cout << "|";
            else if( i <= (viTri + name.size()) - sizeBang+1 ) {
                TextColor( 0*16 + 7 );
                cout << name[sizeBang - viTri - 2 + i];
                TextColor( 0 + 7 );
            }
            else if( i==viTri ){
                TextColor( 0*16 + 7 );
                for( int j=i ; j<sizeBang-1 ; j++){
                    cout << name[j - viTri];
                }
                TextColor( 0 + 7 );
                i=sizeBang-2;
            }
            else {
                TextColor( 0*16 + 7 );
                cout << " ";
                TextColor( 0 + 7 );
            }
        }
    }
    else{
        for( int i=0 ; i<sizeBang ; i++){
            if( i==0 || i==sizeBang-1 ) cout << "|";
            else if( i==viTri ){
                TextColor( 0*16 + 7 );
                cout << name;
                i+=name.size()-1;
                TextColor( 0 + 7 );
            }
            else {
                TextColor( 0*16 + 7 );
                cout << " ";
                TextColor( 0 + 7 );
            }
        }
    }
}

int main()
{
    string name;
    getline( cin, name);
    int begin=1;
    for( float i=0 ; ; i+=0.005){
        if( kbhit() ) break;
        if( begin>=34 ) begin=1;
        system("cls");
        print(35, begin, name);
        begin++;
        Sleep(50);
    }
}