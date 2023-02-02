#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int move_x=1, move_y=1;
int *ptr1=&move_x, *ptr2=&move_y;

void print( int a, int b, int x, int y)
{
    for( int i=0 ; i<a+2 ; i++){
        for( int j=0 ; j<b+2 ; j++){
            if( (i==0 || i==a+1) && (j==0 || j==b+1) ) cout << ".";
            else if( i==0 ) cout << "__";
            else if( i==a+1 ) cout << "--";
            else if( j==0 || j==b+1 ) cout << "|";
            else if( i==x && j==y ) cout << "o ";
            else cout << "  ";
        }
        cout << '\n';
    }
}
void xoaBang(){
    system("cls");
}
void delay()
{
    string s;
    getline( cin, s);
}
void chaybong(int a, int b, int* x, int* y)
{
    if( (*x==1 && *y!=1) || *x==a ) *ptr1*=-1;
    if( (*y==1 && *x!=1) || *y==b ) *ptr2*=-1;
    *x+=(*ptr1);
    *y+=(*ptr2);
}
bool choitip()
{
    char c;
    while( c!='c' && c!='k' ){
        cout << "Muon choi tip khum ? (c hoac k)\n";
        cin >> c;
    }
    if( c=='k' ) return false;
    else return true;
}
int main()
{
    int a = 11, b = 10;
    int *x=new int(1) , *y=new int(1) ;
    bool tiep=true;
    while ( tiep ){
        // cout << "Nhap kich thuoc bang: ";
        // cin >> a >> b;
        // cout << "Nhap vi tri bong: ";
        // cin >> *x >> *y;
        // print(a, b, *x, *y);
        // delay();
        while(true)
        {
            xoaBang();
            print(a, b, *x, *y);
            chaybong(a, b, x, y);
            Sleep(50);
            if( (*x==0 || *x==a-1) && (*y==0 || *y==b-1) ) break;
        }
        x=NULL; y=NULL;
        tiep=choitip();
    }
    return 0;
}