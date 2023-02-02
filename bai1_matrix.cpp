#include <iostream>
using namespace std;
struct matrix{
    int m, n;
    int** a;
};
void nhapMatrix( matrix& mt){
    cout << "Nhap so hang: ";
    cin >> mt.m;
    cout << "Nhap so cot: ";
    cin >> mt.n;
    cout << "\nNhap ma tran: \n";
    //Cap phat bo nho dong
    mt.a=new int*[mt.m];
    for( int i=0 ; i<mt.m ; i++){
        mt.a[i]=new int[mt.n];
        for( int j=0 ; j<mt.n ; j++){
            cin >> mt.a[i][j];
        }
    }
}
void inMatrix(const matrix& mt){
    for( int i=0 ; i<mt.m ; i++){
        for( int j=0 ; j<mt.n ; j++){
            cout << mt.a[i][j] << " ";
        }
        cout << endl;
    }
}
void tongMatrix(const matrix& mt1, const matrix& mt2, matrix& mtTong){
    // Khoi tao ma tran Tong
    mtTong.m=mt1.m;
    mtTong.n=mt1.n;
    mtTong.a=new int*[mtTong.m];
    for( int i=0 ; i<mtTong.m ; i++){
        mtTong.a[i]=new int[mtTong.n];
    }
    // Tong vi tri tuong ung cua mt1 & mt2
    for( int i=0 ; i<mt1.m ; i++){
        for( int j=0 ; j<mt1.n ; j++){
            mtTong.a[i][j]=mt1.a[i][j]+mt2.a[i][j];
        }
    }
}
void tichMatrix(const matrix& mt1, const matrix& mt2, matrix& mtTich){
    // Khoi tao mang tich:
    mtTich.m=mt1.m;
    mtTich.n=mt2.n;
    mtTich.a=new int*[mtTich.m];
    for( int i=0 ; i<mtTich.m ; i++){
        mtTich.a[i]=new int[mtTich.n];
        for( int j=0 ; j<mtTich.n ; j++){
            mtTich.a[i][j]=0; // Vi tinh tich phai cong don nen tao ma tran tich = 0
        }
    }
    for( int i=0 ; i<mtTich.m ; i++){
        for( int j=0 ; j<mtTich.n ; j++){
            for( int x=0 ; x<mt1.n ; x++){
                mtTich.a[i][j]+=mt1.a[i][x]*mt2.a[x][j];
            }
        }
    }
}
void transformMatrix( const matrix& mt, matrix& kq){
    // Khoi tao ma tran chuyen vi
    kq.m=mt.n;
    kq.n=mt.m;
    kq.a=new int*[kq.m];
    for( int i=0 ; i<kq.m ; i++){
        kq.a[i]=new int[kq.n];
    }
    for( int i=0 ; i<kq.m ; i++){
        for( int j=0 ; j<kq.n ; j++){
            kq.a[i][j]=mt.a[j][i];
        }
    }
}
// Ham yeu cau nhap lai neu du lieu sai
void Nhaplai( matrix& mt1, matrix& mt2){
    cout << "Nhap lai ma tran 1: \n";
    nhapMatrix(mt1);
    cout << "Nhap lai ma tran 2 : \n";
    nhapMatrix(mt2);
}
int main()
{
    matrix a, b, tich, tong, aT, bT;
    int choose; // Vi nhieu ma tran khong the cung luc tinh tong va tich, nen tao choose de nguoi dung chon phep tinh
    cout << "Nhap ma tran 1: \n" << endl;
    nhapMatrix(a);
    cout << "\nNhap ma tran 2: \n" << endl;
    nhapMatrix(b);
    while(1){
        cout << "\nBan muon tinh gi: \n";
        cout << "1.Tong 2 ma tran\t2.Tich 2 ma tran\t3.Ma tran chuyen vi\t4.Khong muon tinh\n";
        cin >> choose;
        if( choose==1 ){
            // Tinh tong
            if( a.m!=b.m || a.n!=b.n ){
                // Neu 2 ma tran nhap vao khong thoa man, tao vong lap cho den khi 2 ma tran tinh duoc
                int choose_1; // Nguoi dung chon nhap lai hoac tinh phep tinh khac
                do{
                    if( a.m!=b.m || a.n!=b.n ){
                        cout << "\nMa tran ban nhap vao khong phu hop:\n";
                        cout << "1.Nhap lai ma tran\t2.Thu phep tinh khac.\n";
                        cin >> choose_1;
                        if( choose_1==1 ){
                            // Neu chon 1: yeu cau nhap lai va tiep tuc kiem tra
                            cout << "\nHai ma tran phai cung kich co:\n";
                            Nhaplai(a, b);
                            continue;
                        }
                    }
                }
                while( choose_1!=1 && choose_1!=2 ); //Neu chon khac 1 va 2 khong thoat khoi vong lap
                if( choose_1==2 ) continue; // Neu chon 2: dua nguoi dung tro lai chon phep tinh
            }
            cout << "\nTong cua 2 ma tran la: \n";
            tongMatrix(a, b, tong);
            inMatrix(tong);
        }
        else if( choose==2 ){
            //Tinh tich
            if( a.n!=b.m ){
                // Neu 2 ma tran tinh tich khong thoa man:
                int choose_2; // Chon nhap lai hoac tinh phep tinh khac
                do{
                    if( a.n!=b.m ){
                        cout << "\nMa tran khong hop le: \n";
                        cout << "1.Nhap lai ma tran\t2.Thu phep tinh khac.\n";
                        cin >> choose_2;
                        if( choose_2==1 ){
                            // Neu chon 1: yeu cau nhap lai va tiep tuc kiem tra xem thoa man khong
                            cout << "\nSo cot ma tran 1 phai bang so hang ma tran 2\n";
                            Nhaplai(a, b);
                            continue;
                        }
                    }
                }
                while( choose_2!=1 && choose_2!=2 ); // Neu chon khac 1 va 2 khong thoat khoi vong lap
                if( choose_2==2 ) continue; // Chon 2: Dua tro ve buoc chon phep tinh
            }
            cout << "\nTich cua 2 ma tran la: \n";
            tichMatrix(a, b, tich);
            inMatrix(tich);
        }
        else if( choose==3 ){
            // Tinh chuyen vi
            cout << "\nChuyen vi cua ma tran a: \n";
            transformMatrix( a, aT);
            inMatrix(aT);
            cout << "\nChuyen vi cua ma tran b: \n";
            transformMatrix( b, bT);
            inMatrix(bT);
        }
        else if( choose==4 ) break; // Chon 4: ket thuc chuong trinh
        // Hoi muon tinh tiep khong?
        char s;
        do{
            cout << "\nBan muon thu phep tinh khac? (c hoac k)\n";
            cin >> s;
        }
        while( s!='c' && s!='k' );
        if( s=='k' ) break; // Chon k: ket thuc chuong trinh
        else if( s=='c' ){
            // Neu chon tinh tiep: Hoi nguoi dung muon nhap lai ma tran khong
            do{
                cout << "\nBan co muon nhap lai 2 ma tran (c hoac k): \n";
                cin >> s;
            }
            while( s!='c' && s!='k' );
            if( s=='c' ){
                Nhaplai(a, b);
                continue;
            }
        }
    }
}