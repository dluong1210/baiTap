#include <iostream>
#include <string>
using namespace std;
struct PhanSo{
    int a, b;
    PhanSo( int _a=0, int _b=1){
        a=_a;
        b=_b;
    }
};
int stringToInt( string s){
    int n=s.size(), a=0;
    for( int i=0 ; i<n ; i++){
        if( s[i]>='0' && s[i]<='9' ){
            a*=10;
            a+=s[i]-'0';
        }
    }
    return a;
}
void nhapPhanSo( PhanSo& ps){
    string aa, bb;
    while(1){
        getline(cin, aa, '/');
        ps.a=stringToInt(aa);
        getline(cin, bb);
        ps.b=stringToInt(bb);
        if( ps.b==0 ){
            cout << "\nMau so phai khac 0, moi nhap lai:\n";
            continue;
        }
        else return;
    }
}
void inPhanSo( const PhanSo& ps){
    if( ps.b==1 ) cout << ps.a;
    else cout << ps.a << "/" << ps.b;
}
void toiGianPhanSo( PhanSo& ps){
    for( int i=2 ; i<=ps.b ; i++){
        if( ps.a%i==0 &&ps.b%i==0 ){
            ps.a/=i;
            ps.b/=i;
        }
    }
}
void tongPhanSo( const PhanSo& ps1, const PhanSo& ps2, PhanSo& psTong ){
    int mc=ps1.b;
    while(1){
        if( mc%ps1.b==0 && mc%ps2.b==0 ) break;
        else mc++;
    }
    psTong.a=ps1.a*(mc/ps1.b)+ps2.a*(mc/ps2.b);
    psTong.b=mc;
}
void hieuPhanSo( const PhanSo& ps1, const PhanSo& ps2, PhanSo& psHieu ){
    int mc=ps1.b;
    while(1){
        if( mc%ps1.b==0 && mc%ps2.b==0) break;
        else mc++;
    }
    psHieu.a=ps1.a*(mc/ps1.b)-ps2.a*(mc/ps2.b);
    psHieu.b=mc;
}
void tichPhanSo( const PhanSo& ps1, const PhanSo& ps2, PhanSo& psTich){
    psTich.a=ps1.a*ps2.a;
    psTich.b=ps1.b*ps2.b;
}
void thuongPhanSo( const PhanSo& ps1, const PhanSo& ps2, PhanSo& psThuong){
    psThuong.a=ps1.a*ps2.b;
    psThuong.b=ps1.b*ps2.a;
}
bool soSanhNhoHonPhanSo( const PhanSo& ps1, const PhanSo& ps2){
    int mc=ps1.b;
    while(1){
        if( mc%ps1.b==0 && mc%ps2.b==0 ) break;
        else mc++;
    }
    if( ps1.a*(mc/ps1.b)<ps2.a*(mc/ps2.b) ) return true;
    else return false;
}
int main()
{
    while(1){
        int n, dem_duong=0, dem_am=0, dem_khong=0;
        PhanSo sum_duoi1, sum_tren1;
        cout << "Nhap vao so luong phan so: ";
        cin >> n;
        cout << "\nNhap phan so co dang a/b. \n";
        PhanSo ps[n];
        for( int i=0 ; i<n ; i++){
            cout << "Nhap vao phan so thu " << i+1 << ": ";
            nhapPhanSo(ps[i]);
            if( ps[i].a*ps[i].b>0 ) dem_duong++;
            else if( ps[i].a==0 ) dem_khong++;
            else dem_am++;
        }
        for( int i=0 ; i<n ; i++){
            for( int j=i+1 ; j<n ; j++){
                if( soSanhNhoHonPhanSo(ps[i], ps[j]) ) swap(ps[i], ps[j]);
            }
        }
        for( int i=0 ; i<n ; i++){
            if( abs(ps[i].a/ps[i].b)<1 ) tongPhanSo(ps[i], sum_duoi1, sum_duoi1);
            else if(abs(ps[i].a/ps[i].b)>1 ) tongPhanSo(ps[i], sum_tren1, sum_tren1 );
        }
        cout << "\nSap xep theo thu tu giam dan: \n";
        for( int i=0 ; i<n ; i++){
            toiGianPhanSo(ps[i]);
            inPhanSo(ps[i]);
            cout << endl;
        }
        cout << "\nTong phan so co tri tuyet doi nho hon 1: ";
        if( sum_duoi1.a==0 ) cout << "0";
        else {
            toiGianPhanSo(sum_duoi1);
            inPhanSo(sum_duoi1);
        }
        cout << "\nTong phan so co tri tuyet doi lon hon 1: ";
        if( sum_tren1.a==0 ) cout << "0";
        else {
            toiGianPhanSo(sum_tren1);
            inPhanSo(sum_tren1);
        }
        cout << endl;
        char s;
        do{
            cout << "\nBan muon thu lai khong? (c hoac k)\n";
            cin >> s;
        }
        while( s!='c' && s!='k' );
        if( s=='k' ){
            cout << "\nTam biet ^^";
            break;
        }
    } 
    return 0;
}