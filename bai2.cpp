//Cho ngay dau tien cua bo lich nay la Thu 3 1/1/1901
#include <iostream>
#include <windows.h>
using namespace std;
struct Date{
    int day, month, year ;
};
//Tinh so ngay cua mot thang, nam
int SoNgayCuaThangNam( const Date& d){
    if( d.month==2 ){
        if( d.year%4==0 ){
            return 29;
        }
        else return 28;
    }
    else if( (d.month<=7 && d.month%2==1) || (d.month>7 && d.month%2==0) ) return 31;
    else return 30;
}
void nhapDate(Date& d){
    string _d, _m, _y;
    getline(cin, _d, '/');
    getline(cin, _m, '/');
    getline(cin, _y);
    d.day=stoi(_d);
    d.month=stoi(_m);
    d.year=stoi(_y);
}
void inDate(const Date& d){
    cout << d.day << "/" << d.month << "/" << d.year << '\n';
}
bool laDateHopLe(const Date& td){
    if( td.day<=SoNgayCuaThangNam( td ) && td.day>0 && (td.month>=1 && td.month<=12) && td.year>1900 ){
        return true;
    }
    else return false;
}
void quyChuanDate(const Date& d, Date& d_hop_le){
    if( !laDateHopLe(d) ){
        //Tim ngay hop le
        if( d.day<1 ) d_hop_le.day=1;
        else if( d.day>SoNgayCuaThangNam(d) ) d_hop_le.day=SoNgayCuaThangNam(d);
        else d_hop_le.day=d.day;
        //Tim thang hop le
        if( d.month<1 ) d_hop_le.month=1;
        else if( d.month>12 ) d_hop_le.month=12;
        else d_hop_le.month=d.month;
        //Tim nam hop le
        if( d.year<1901 ) d_hop_le.year=1901;
        else d_hop_le.year=d.year; 
        //Doan ngay hop le
        cout << "Y ban co phai la ngay: " ;
        inDate(d_hop_le);
        char s;
        //Chay vong lap chon a hoac b
        do{
            cout << "\na. Dung y toi roi\t" << "b. Khong dung y toi\n" << "\t (chon a hoac b)";
            cin >> s;
            if( s=='a'){
                return;
            }
            else if( s=='b' ){
                Date d;
                cout << "\nMoi nhap lai ngay: ";
                nhapDate(d);
                quyChuanDate( d, d_hop_le); // Sau khi nhap date tiep tuc kiem tra hop le
            }
        }
        while( s!='a' && s!='b' );
    }
    else d_hop_le=d;
}
void tinhDateHomQua(const Date& hom_nay, Date& hom_qua){
    //Neu hom_nay la dau thang
    if( hom_nay.day==1 ){
        hom_qua.month=hom_nay.month-1;
        //Neu thang cua hom_nay=1
        if( hom_qua.month<1 ){
            hom_qua.month=12;
            hom_qua.year=hom_nay.year-1;
            hom_qua.day=SoNgayCuaThangNam(hom_qua); // chuyen ve ngay cuoi cua thang truoc do
        }
        else {
            hom_qua.day=SoNgayCuaThangNam(hom_qua);
            hom_qua.year=hom_nay.year;
        }
    }
    else{
        hom_qua=hom_nay;
        hom_qua.day=hom_nay.day-1;//Gan hom_qua=hom_nay roi tru di 1 ngay
    }
}
void tinhDateNgayMai(const Date& hom_nay, Date& ngay_mai){
    //Neu hom_nay la cuoi thang
    if( hom_nay.day==SoNgayCuaThangNam(hom_nay) ){
        ngay_mai.day=1;
        ngay_mai.month=hom_nay.month+1;
        //Neu thang cua hom_nay=12 -> thang ngay_mai=1 && tang 1 nam
        if( ngay_mai.month>12 ){
            ngay_mai.month=1;
            ngay_mai.year=hom_nay.year+1;
        }
        else ngay_mai.year=hom_nay.year;
    }
    //Neu khong phai cuoi thang
    else{
        ngay_mai=hom_nay;
        ngay_mai.day=hom_nay.day+1; //Gan ngay_mai=hom_nay roi tang 1 ngay

    }
}
void congDate(const Date& d1, int ngay, Date& d2){
    d2=d1;//Gan d2=d1 roi thuc hien tinh toan tren d2
    //Dung vong lap cong ngay vao tung thang, vi so ngay moi thang la khac nhau
    while( ngay!=0 ){
        if( d2.day+ngay>SoNgayCuaThangNam(d2) ){
            ngay=ngay-(SoNgayCuaThangNam(d2)-d2.day+1);
            d2.month++;
            if( d2.month>12 ){
                d2.month=1;
                d2.year++;
            }
            d2.day=1;
        }
        else if( d2.day+ngay<=SoNgayCuaThangNam(d2) ){
            d2.day+=ngay;
            ngay=0;
        }
    }
}
void truDate(const Date& d1, int ngay, Date& d2){
    d2=d1; //Gan d2=d1 roi thuc hien tinh toan tren d2
    //Vi moi thang co so ngay khac nhau, nen ta tru tung thang mot
    while( ngay!=0 ){
        if( d2.day-ngay<1 ){
            ngay=ngay-d2.day;
            d2.month--;
            if( d2.month<1 ){
                d2.month=12;
                d2.year--;
            }
            d2.day=SoNgayCuaThangNam(d2);
        }
        else if( d2.day-ngay>=1 ){
            d2.day=d2.day-ngay;
            ngay=0;
        }
    }
}
bool ktBangDate(const Date& d1, const Date& d2){
    if( d1.day==d2.day && d1.month==d2.month && d1.year==d2.year ) return true;
    else return false;
}
bool ktNhoHonDate(const Date& d1, const Date& d2){
    if( d1.year<d2.year || (d1.year==d2.year && d1.month<d2.month) || (d1.year==d2.year && d1.month==d2.month && d1.day<d2.day) ) return true;
    else return false;
}
bool ktLonHonDate(const Date& d1, const Date& d2){
    if( d1.year>d2.year || (d1.year==d2.year && d1.month>d2.month) || (d1.year==d2.year && d1.month==d2.month && d1.day>d2.day) ) return true;
    else return false;
}
int tinhKhoangCach(const Date & d1, const Date & d2){
    int ngay=0;
    //TH1: d1>d2
    if( ktLonHonDate(d1, d2) ){
        //Neu khac so nam
        if( d1.year>d2.year ){
            //So ngay cua d1 tinh tu dau nam: sn1
            ngay+=d1.day;
            for( int i=1 ; i<d1.month ; i++){
                if( i==2 ){
                    if( d1.year%4==0 ) ngay+=29;
                    else ngay+=28;
                }
                else if( (i<=7 && i%2==1) || (i>=8 && i%2==0) ) ngay+=31;
                else ngay+=30;
            }
            //So ngay cua d2 cho den het nam: sn2
            ngay+=SoNgayCuaThangNam(d2)-d2.day;
            for( int i=d2.month+1 ; i<=12 ; i++){
                if( i==2 ){
                    if( d2.year%4==0 ) ngay+=29;
                    else ngay+=28;
                }
                else if( (i<=7 && i%2==1) || (i>=8 && i%2==0) ) ngay+=31;
                else ngay+=30;
            }
            //Chenh lech ngay= so nam chenh lech + sn1 + sn2
            for( int i=d2.year+1 ; i<=d1.year-1 ; i++){
                if( i%4==0 ) ngay+=366; //nam nhuan
                else ngay+=365; //nam khong nhuan
            }
        }
        //Neu cung nam
        else if( d1.year==d2.year ){
            //So ngay tu d1 den dau thang cua d2
            int sn_d1=d1.day;
            for( int i=d2.month ; i<=d1.month-1 ; i++){
                if( i==2 ){
                    if( d1.year%4==0 ) sn_d1+=29;
                    else sn_d1+=28;
                }
                else if( (i<=7 && i%2==1) || (i>=8 && i%2==0) ) sn_d1+=31;
                else sn_d1+=30;
            }
            //Chenh lech bang so ngay tu d1 den dau thang cua d2 tru di d2.day
            ngay=sn_d1-d2.day;
        }
    }
    //TH2 d1<d2 code tuong tu doi vi tri d1 <-> d2
    else if( ktNhoHonDate ){
        //Neu khac so nam
        if( d1.year<d2.year ){
            //So ngay cua d2 tinh tu dau nam: sn1
            ngay+=d2.day;
            for( int i=1 ; i<d2.month ; i++){
                if( i==2 ){
                    if( d2.year%4==0 ) ngay+=29;
                    else ngay+=28;
                }
                else if( (i<=7 && i%2==1) || (i>=8 && i%2==0) ) ngay+=31;
                else ngay+=30;
            }
            //So ngay cua d1 cho den het nam: sn2
            ngay+=SoNgayCuaThangNam(d1)-d1.day;
            for( int i=d1.month+1 ; i<=12 ; i++){
                if( i==2 ){
                    if( d1.year%4==0 ) ngay+=29;
                    else ngay+=28;
                }
                else if( (i<=7 && i%2==1) || (i>=8 && i%2==0) ) ngay+=31;
                else ngay+=30;
            }
            //Chenh lech ngay= so nam chenh lech + sn1 + sn2
            for( int i=d1.year+1 ; i<=d2.year-1 ; i++){
                if( i%4==0 ) ngay+=366; //nam nhuan
                else ngay+=365; //nam khong nhuan
            }
        }
        //Neu cung so nam
        else if( d1.year==d2.year ){
            //So ngay tu d12den dau thang cua d1
            int sn_d2=d2.day;
            for( int i=d1.month ; i<=d2.month-1 ; i++){
                if( i==2 ){
                    if( d1.year%4==0 ) sn_d2+=29;
                    else sn_d2+=28;
                }
                else if( (i<=7 && i%2==1) || (i>=8 && i%2==0) ) sn_d2+=31;
                else sn_d2+=30;
            }
            //Chenh lech bang so ngay tu d1 den dau thang cua d2 tru di d2.day
            ngay=sn_d2-d1.day;
        }
    }
    //TH3 d1=d2 ham se return ngay=0 luon nen ta khong can xet
    return ngay;
}
int main()
{
    int n, dem_dau_thang=0, dem_cuoi_thang=0, dem_ngay_lien_ke=0;
    cout << "\nNhap so Date: ";
    cin >> n;
    Date a[n];
    cout << "\nNhap ngay thang nam theo dang dd/mm/yyyy \n";
    for( int i=0 ; i<n ; i++){
        cout << "\nNhap Date thu " << i+1 << ": ";
        Date thu;
        nhapDate(thu);
        quyChuanDate( thu, a[i] );
        if( a[i].day==1 ) dem_dau_thang++;
        else if( a[i].day==SoNgayCuaThangNam(a[i]) ) dem_cuoi_thang++;
    }
    system("cls");
    cout << "\nSo luong ngay la dau thang: " << dem_dau_thang;
    cout << "\nSo luong ngay la cuoi thang: " << dem_cuoi_thang;
    for( int i=0 ; i<n ; i++){
        for( int j=i+1 ; j<n ; j++){
            if( ktNhoHonDate( a[j], a[i] ) ) swap( a[j], a[i] );
        }
    }
    cout << "\nSap xep cac ngay theo thu tu tang dan:\n";
    for( int i=0 ; i<n ; i++){
        inDate( a[i] );
        cout << endl;
    }
    for( int i=0 ; i<n ; i++){
        if( tinhKhoangCach( a[i], a[i+1] )==1 ) dem_ngay_lien_ke++;
    }
    cout << "So luong cap ngay lien ke: " << dem_ngay_lien_ke;
    int thu2=0, thu3=0, thu4=0, thu5=0, thu6=0, thu7=0, cn=0;
    //Cho ngay dau tien cua bo lich nay la Thu 3 1/1/1901
    Date ngay_dau;
    ngay_dau.day=1;
    ngay_dau.month=1;
    ngay_dau.year=1901;
    for( int i=0 ; i<n ; i++){
        //Tinh khoang cach tu date a[i] den 1/1/1901
        int ngay= tinhKhoangCach( a[i], ngay_dau);
        //Vi ngay_dau:1/1/1901 la thu ba nen chia lay du cho 7 duoc
        if( ngay%7==6 ) thu2++;
        else if( ngay%7==0 ) thu3++;
        else if( ngay%7==1 ) thu4++;
        else if( ngay%7==2 ) thu5++;
        else if( ngay%7==3 ) thu6++;
        else if( ngay%7==4 ) thu7++;
        else if( ngay%7==5 ) cn++;
    }
    cout << "\nSo luong ngay duong lich la: ";
    cout << "\nThu 2: " << thu2
         << "\nThu 3: " << thu3
         << "\nThu 4: " << thu4
         << "\nThu 5: " << thu5
         << "\nThu 6: " << thu6
         << "\nThu 7: " << thu7
         << "\nChu Nhat: " << cn;
    return 0;
}