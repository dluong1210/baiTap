#include <bits/stdc++.h>
using namespace std;

string reply;

void traloi( int n, int rd)
{
    if( n-rd>100 ) cout << "qua lon\n";
    else if(n-rd<-100 ) cout << "qua nho\n";
    else if(n-rd>50 ) cout << "hoi lon\n";
    else if(n-rd<-50 ) cout << "hoi nho\n";
    else if( n-rd>10 || n-rd<-10 ) cout << "gan roi do, pham vi 50 so nua \n";
    else if(n-rd>5 || n-rd<-5 ) cout << "rat gan roi do, pham vi 10 so nua \n";
    else if(n-rd!=0) cout << "pham vi 5 so nua\n";
}
void ketqua( int so_luot, int rd )
{
    if( so_luot==1 ) cout << "tuyet voi, ban doan ra ngay so do\n";
    else cout << "dung roi !!! " << rd << "\ndoan " << so_luot << " lan moi ra =))\n";
}
void choitiep()
{
    while(true){
        cout << "muon choi tiep khong ?( c hoac k)";
        cin >> reply;
        if( reply=="c" || reply=="k") break;
        else continue;
    }
}
int main()
{
    srand(time(0));
    int a;
    cout << "toi vua nghi ra so khoang 1 den 1000\n";
    while(true){
        int i=0;
        int rd=rand()%1000+1;
        while (true)
        {
            cout << "hay doan so do?\n";
            cin >> a;
            if( a==rd )
            {
                i++;
                break;
            }
            else{
                traloi(a, rd);
                i++;
            }
        }
    ketqua(i, rd);
    choitiep();
    system("cls");
    if( reply=="c") continue;
    else cout << "bai bai" ;
        break;
    }
    return 0;
}
