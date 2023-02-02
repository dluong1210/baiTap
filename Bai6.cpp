#include <iostream>
#include <cmath>
using namespace std;
struct Toado{
    double x, y;
    Toado() {}
    Toado( double _x, double _y){
        x=_x;
        y=_y;
    }
    void nhapToaDo(){
        cin >> x >> y;
    }
};
struct Tamgiac{
    Toado a, b, c;
    Tamgiac() {}
    Tamgiac( Toado _a, Toado _b, Toado _c){
        a=_a;
        b=_b;
        c=_c;
    }
    void nhapCanh(){
        cout << "Nhap toa do diem A: ";
        a.nhapToaDo();
        cout << "\nNhap toa do diem B: ";
        b.nhapToaDo();
        cout << "\nNhap toa do diem C: ";
        c.nhapToaDo();
    }
    void ViTriGocToaDo(){
        //Goi diem O(0, 0), O nam trong tam giac ABC khi va chi khi dien tich:
        // OAB + OBC + OAC = ABC. Ta di tinh dien tich tung tam giac mot
        double s, s1, s2, s3;
        // S.OAB. Do biet toa do 3 diem ta tinh dien tich theo dinh thuc (det)
        // Neu det=0 chung to goc toa do O va A B thang hang. Luc nay ta can chung minh O nam trong AB
        s1=abs(0.5*(a.x*b.y-a.y*b.x));
        // S.OBC. Dung det tinh tuong tu
        // Neu det=0 chung to O, B, C thang hang. Luc nay can chung minh O nam trong BC
        s2=abs(0.5*(b.x*c.y-b.y*c.x));
        // S.OAC. Dung det tinh tuong tu
        // Neu det=0. Ta can chung minh O nam trong AC
        s3=abs(0.5*(a.x*c.y-a.y*c.x));
        // S.ABC
        s=abs(0.5*(b.x*c.y-b.y*c.x-(a.x*c.y-a.y*c.x)+a.x*b.y-b.x*a.y));
        // Kiem tra xem ABC co phai tam giac khong
        if( s==0 ) {
            cout << "ABC dang thang hang hoac co diem trung nhau, khong phai mot tam giac";
            return;
        }
        //Kiem tra xem co diem nao la goc toa do khong
        else if( (a.x==0 && a.y==0 ) || (b.x==0 && b.y==0) || (c.x==0 && c.y==0) ) {
            cout << "Goc toa do nam tren canh cua tam giac";
            return;
        }
        // O nam tren AB khi va chi khi cac thanh phan x, y cua A va B trai dau nhau
        else if( s1==0 && (a.x*b.x<=0 && a.y*b.y<=0) ) cout << "Goc toa do nam tren canh AB cua tam giac";
        // Tuong tu O nam tren BC khi va chi khi S.OBC=0 & thanh phan BC trai dau nhau
        else if( s2==0 && (b.x*c.x<=0 && b.y*c.y<=0) ) cout << "Goc toa do nam tren canh BC cua tam giac";
        // Tuong tu voi O nam tren AC
        else if( s3==0 && (a.x*c.x<=0 && a.y*c.y<=0) ) cout << "Goc toa do nam tren canh AC cua tam giac";
        // Cuoi cung kiem tra xem O co nam trong ABC khong dua vao dien tich cac tam giac
        else if( s1+s2+s3==s ) cout << "Goc toa do nam trong tam giac";
        // Cac truong hop con lai deu nam ngoai tam giac
        else cout << "Goc toa do nam ben ngoai tam giac";
    }
};
int main()
{
    char s;
    do{
        cout << "Nhap toa do cac diem lan luot cach nhau boi dau cach: \n";
        Tamgiac ABC;
        ABC.nhapCanh();
        ABC.ViTriGocToaDo();
        do{
        cout << "\nBan muon thu tam giac khac khong? (c hoac k) \n";
        cin >> s;
        if( s=='k' ) break;
        cout << endl;
        }
        while( s!='c' && s!='k' ); //Neu cau tra loi khong hop le yeu cau nhap lai
    }
    while( s=='c' );
    cout << "Tam biet ^^";
    return 0;
}