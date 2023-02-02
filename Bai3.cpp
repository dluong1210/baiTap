#include <iostream>
using namespace std;
struct Dathuc{
    int bac;
    double mang_he_so[100];
};
void nhapDathuc( Dathuc& dt){
    cout << "\nNhap bac cua da thuc: ";
    cin >> dt.bac;
    for( int i=0 ; i<=dt.bac ; i++){
        cout << "\nNhap vao he so a" << i << " : ";
        cin >> dt.mang_he_so[i];
    }
}
void inDathuc( const Dathuc& dt){
    for( int i=0 ; i<=dt.bac ; i++){
        if( i==0 ) cout << dt.mang_he_so[i];
        else{ 
            if( dt.mang_he_so[i]<0 ) cout << " + " << "(" << dt.mang_he_so[i] << ")" << "x^" << i; // Neu he so do < 0 them dau ngoac cho dep
            else cout << " + " << dt.mang_he_so[i] << "x^" << i;
        }
    }
}
void quyChuanDathuc( Dathuc& dt){
    while( dt.mang_he_so[dt.bac]==0 && dt.bac!=0 ){
        dt.bac--;
    }
}
void tong( const Dathuc& dt1, const Dathuc& dt2, Dathuc& dtTong){
    dtTong.bac=max( dt1.bac, dt2.bac );
    for( int i=0 ; i<=dtTong.bac ; i++){
        if( i>dt1.bac ){
            dtTong.mang_he_so[i]=dt2.mang_he_so[i];
        }
        else if( i>dt2.bac ){
            dtTong.mang_he_so[i]=dt1.mang_he_so[i];
        }
        else {
            dtTong.mang_he_so[i]=dt1.mang_he_so[i]+dt2.mang_he_so[i];
        }
    }
}
void hieu(const Dathuc& dt1, const Dathuc& dt2, Dathuc & dtHieu){
    dtHieu.bac=max( dt1.bac, dt2.bac );
    for( int i=0 ; i<=dtHieu.bac ; i++){
        if( i>dt1.bac ){
            dtHieu.mang_he_so[i]=-dt2.mang_he_so[i];
        }
        else if( i>dt2.bac ){
            dtHieu.mang_he_so[i]=dt1.mang_he_so[i];
        }
        else dtHieu.mang_he_so[i]=dt1.mang_he_so[i]-dt2.mang_he_so[i];
    }
}
void tich(const Dathuc& dt1, const Dathuc& dt2, Dathuc& dtTich){
    dtTich.bac=dt1.bac+dt2.bac;
    for( int i=0 ; i<=dtTich.bac ; i++){
        dtTich.mang_he_so[i]=0;
    }
    for( int i=0 ; i<=dt1.bac ; i++){
        for( int j=0 ; j<=dt2.bac ; j++){
            dtTich.mang_he_so[i+j]+=dt1.mang_he_so[i]*dt2.mang_he_so[j];
        }
    }
}
double tinhGiaTriDathuc(const Dathuc& dt, double X){
    double kq=dt.mang_he_so[0];
    for( int i=1 ; i<=dt.bac ; i++){
        kq+=dt.mang_he_so[i]*X;
        X*=X;
    }
    return kq;
}
int main()
{
    Dathuc dt1, dt2, tongdt, hieudt, tichdt;
    double x;
    cout << "Nhap da thuc 1:\n";
    nhapDathuc(dt1);
    cout << "\nNhap da thuc 2:\n";
    nhapDathuc(dt2);
    quyChuanDathuc(dt1);
    quyChuanDathuc(dt2);
    tong(dt1, dt2, tongdt);
    quyChuanDathuc(tongdt);
    hieu(dt1, dt2, hieudt);
    quyChuanDathuc(hieudt);
    tich(dt1, dt2, tichdt);
    quyChuanDathuc(tichdt);
    cout << "\nTong cua hai da thuc:\n";
    inDathuc(tongdt);
    cout << "\nHieu cua hai da thuc: \n";
    inDathuc(hieudt);
    cout << "\nTich cua hai da thuc: \n";
    inDathuc(tichdt);
    char s;
    do{
        int a;
        cout << "\nChon da thuc ban muon tinh gia tri( chon 1-6 ):\n";
        cout << "1.Da thuc 1\t2.Da thuc 2\t3.Da thuc tong\t4.Da thuc hieu\t5.Da thuc tich\t6.Khong muon tinh\n";
        cin >> a;
        if( a==6 ) break;
        cout << "\nNhap bien x: ";
        cin >> x;
        if( a==1 ) cout << "Gia tri da thuc 1 tai x=" << x << " la: " << tinhGiaTriDathuc(dt1, x);
        else if( a==2 ) cout << "Gia tri da thuc 2 tai x=" << x << " la: " << tinhGiaTriDathuc(dt2, x);
        else if( a==3 ) cout << "Gia tri da thuc tong tai x=" << x << " la: " << tinhGiaTriDathuc(tongdt, x);
        else if( a==4 ) cout << "Gia tri da thuc hieu tai x=" << x << " la: " << tinhGiaTriDathuc(hieudt, x);
        else if( a==5 ) cout << "Gia tri da thuc tich tai x=" << x << " la: " << tinhGiaTriDathuc(tichdt, x);
        cout << endl;
        cout << "Ban muon tinh lai khong? (c hoac k) \n";
        cin >> s;
        while( s!='c' && s!='k' ){
            cout << "\nNhap lai( c hoac k): ";
        }
        if( s=='k' ) break;
    }
    while( s=='c' );
}