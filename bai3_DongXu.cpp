#include <iostream>
using namespace std;
struct DongXu{
    int d, xu;
    DongXu( int _d=0, int _xu=0){
        d=_d;
        xu=_xu;
    }
};
void nhapDongXu( DongXu& dx){
    cin >> dx.d >> dx.xu;
}
void inDongXu( const DongXu& dx){
    cout << dx.d << " dong va " << dx.xu << " xu";
}
void quyChuanDongXu( DongXu& dx){
    if( dx.xu>99 ){
        dx.d+=dx.xu/100;
        dx.xu%=100;
    }
}
void tongDongXu( const DongXu& dx1, const DongXu& dx2, DongXu& dxTong ){
    dxTong.d=dx1.d+dx2.d;
    dxTong.xu=dx1.xu+dx2.xu;
    quyChuanDongXu( dxTong );
}
bool soSanhNhoHonDongXu( const DongXu& dx1, const DongXu& dx2){
    if( (dx1.d<dx2.d) || ( dx1.d==dx2.d && dx1.xu<dx2.xu) ) return true;
    else return false;
}
void diffDongXu( const DongXu& dx1, const DongXu& dx2, DongXu& dxDiff ){
    if( soSanhNhoHonDongXu(dx1, dx2) ){
        dxDiff.xu=(100-dx1.xu)+dx2.xu;
        dxDiff.d=dx2.d-(dx1.d+1);
    }
    else{
        dxDiff.xu=(100-dx2.xu)+dx1.xu;
        dxDiff.d=dx1.d-(dx2.d+1);
    }
    quyChuanDongXu(dxDiff);
}
DongXu chiaXu( const DongXu& dx, DongXu& kq, int n){
    // Ham ket hop vua chia xu, vua return ve so tien du ra
    kq.d=dx.d/n; // Chia dong truoc
    kq.xu=(dx.xu+(dx.d%n)*100)/n; // So dong con du quy ve xu roi chia tiep
    DongXu hoaHong;
    hoaHong.d=0;
    hoaHong.xu=(dx.xu+(dx.d%n)/n)%n;// Hoa hong cua nguoi chia la so tien du ra
    quyChuanDongXu(hoaHong);
    return hoaHong;
}
void xoaXu( DongXu dx[], DongXu xoa, int& n ){
    // Ham ket hop vua xoa DongXu, vua sua lai kich co mang
    DongXu chenh[n]; // Tao 1 mang de tim xem DongXu nao gan voi gia tri nhap vao nhat, roi thuc hien xoa
    for( int i=0 ; i<n ; i++){
        diffDongXu(dx[i], xoa, chenh[i]);
    }
    int min=0;
    for( int i=0 ; i<n ; i++){
        // Tim vi tri ma gan voi gt nhap vao nhat
        if( soSanhNhoHonDongXu(chenh[i], chenh[min]) ) min=i;
    }
    // Thuc hien xoa
    for( int i=min ; i<n-1 ; i++){
        dx[i]=dx[i+1];
    }
    n--;
}
int main()
{
    // Tao vong lap de co the choi nhieu lan
    while(1){
        int n, max, min=0;
        cout << "Nhap vao so luong DongXu: ";
        cin >> n;
        DongXu dx[n], sum_dx, kq;
        cout << "\nNhap lan luot dong va xu cach nhau boi dau cach.\n";
        for( int i=0 ; i<n ; i++){
            cout << "\nNhap DongXu thu " << i+1 << ": \n";
            nhapDongXu(dx[i]);
            tongDongXu( dx[i], sum_dx, sum_dx);// Nhap ket hop tinh tong DongXu luon
        }
        for( int i=0 ; i<n ; i++){
            if( soSanhNhoHonDongXu(dx[i], dx[min]) ) min=i; //Nguoi co it tien nhat la nguoi duoc loi nhat khi chia xu
        }
        // Sap xep mang theo thu tu giam dan
        for( int i=0 ; i<n ; i++){
            for( int j=i+1 ; j<n ; j++){
                if( soSanhNhoHonDongXu(dx[i], dx[j]) ) {
                    swap(dx[i], dx[j]);
                    if( i==0 ) max=j; //Nguoi co nhieu tien nhat la nguoi thiet nhat khi chia xu
                }
            }
        }
        // Chia Xu
        DongXu hoaHong = chiaXu(sum_dx, kq, n); // Ham vua chia xu, vua tinh hoa hong 
        cout << "\nChia deu cho ca lop thi moi sinh vien duoc:\n";
        inDongXu(kq);
        cout << endl << "\nNguoi thuc hien chia duoc tra so hoa hong la:\n";
        inDongXu(hoaHong);
        if( n==1 ) max=0;
        cout << endl << "\nSinh vien duoc loi nhat la sinh vien thu " << min+1 << ".";
        cout << "\nSinh vien bi thiet nhat la sinh vien thu " << max+1 << ".\n"; // Vi mang bat dau tu 0 nen thu tu sinh vien phai +1 so voi mang
        // In mang theo thu tu giam dan
        cout << "\nSap xep theo thu tu giam dan:\n";
        for( int i=0 ; i<n ; i++){
            cout << endl;
            inDongXu(dx[i]);
        }
        cout << endl;
        // Xoa xu theo gia tri nhap vao
        while(1){
            DongXu xoa;
            cout << "\nNhap khoan tien gan voi khoan tien ma ban muon xoa:\n";
            nhapDongXu(xoa);
            xoaXu(dx, xoa, n);
            if( n==0 ){
                cout << "\nBan da xoa het ca mang.";
                break;
            }
            cout << "\nMang sau khi da xoa: ";
            for( int i=0 ; i<n ; i++){
                cout << endl;
                inDongXu(dx[i]);
            }
            cout << endl;
        }
        // Hoi nguoi choi muon thu lai khong
        char s;
        do{
            cout << "\nBan muon thu lai khong? (c hoac k)\n";
            cin >> s;
        }
        while( s!='c' && s!='k' );
        if( s=='c' ) cout << endl;
        else return 0;
    }
}