#include <iostream>
#include <cmath>
using namespace std;
struct ToaDo{
    double x, y;
};
void nhapToaDo( ToaDo& td){
    cin >> td.x >> td.y;
}
void inToaDo( const ToaDo& td){
    cout << "(" << td.x << "," << td.y << ")";
}
bool laGocToaDo( const ToaDo& td){
    if( td.x==0 && td.y==0 ) return true;
    else return false;
}
bool laTrenTungHoanh(const ToaDo& td){
    if( td.x==0 || td.y==0 ) return true;
    else return false;
}
bool laTrenDuongCheo(const ToaDo& td){
    if( td.x==td.y || td.x==-td.y ) return true;
    else return false;
}
bool laDoiXung(const ToaDo& td1, const ToaDo& td2){
    if( td1.x+td2.x==0 && td1.y+td2.y==0 ) return true;
    else return false;
}
int trenGocPhanTu(const ToaDo& td){
    if( td.x>0 ){
        if( td.y>0 ) return 1;
        else if( td.y<0 ) return 2;
    }
    else if( td.x<0 ){
        if( td.y>0 ) return 4;
        else if( td.y<0 ) return 3;
    }
}
double tinhKhoangCach(const ToaDo& td1, const ToaDo& td2){
    return sqrt( (td1.x-td2.x)*(td1.x-td2.x) + (td1.y-td2.y)*(td1.y-td2.y) );
}

int main()
{
    int n;
    cout << "Nhap so diem: ";
    cin >> n;
    ToaDo a[n];
    cout << "\nNhap lan luot toa do x, y cach nhau boi dau cach";
    for( int i=0 ; i<n ; i++){
        cout << "\nNhap toa do diem thu " << i+1 << ":\n";
        cin >> a[i].x >> a[i].y;
    }
    int dem_goc_td=0, dem_tren_truc=0, dem_tren_cheo=0, dem_doi_xung=0, goc_mot=0, goc_hai=0, goc_ba=0, goc_bon=0;
    for( int i=0 ; i<n ; i++){
        if( laGocToaDo( a[i] ) ) dem_goc_td++;
        if( laTrenTungHoanh( a[i] ) ) dem_tren_truc++;
        if( laTrenDuongCheo( a[i] ) ) dem_tren_cheo++;
        if( trenGocPhanTu( a[i] )==1 ) goc_mot++;
        else if( trenGocPhanTu( a[i] )==2 ) goc_hai++;
        else if( trenGocPhanTu( a[i] )==3 ) goc_ba++;
        else if( trenGocPhanTu( a[i] )==4 ) goc_bon++;
    }
    cout << "\nSo diem la goc toa do: " << dem_goc_td;
    cout << "\nSo diem nam tren truc: " << dem_tren_truc;
    cout << "\nSo diem nam tren duong cheo: " << dem_tren_cheo;
    cout << "\nSo diem tren goc phan tu thu 1: " << goc_mot;
    cout << "\nSo diem tren goc phan tu thu 2: " << goc_hai;
    cout << "\nSo diem tren goc phan tu thu 3: " << goc_ba;
    cout << "\nSo diem tren goc phan tu thu 4: " << goc_bon;
    for( int i=0 ; i<n ; i++){
        for( int j=i+1 ; j<n ; j++){
            if( laDoiXung( a[i], a[j] ) ) dem_doi_xung++;
        }
    }
    cout << "\nSo cap diem doi xung qua goc toa do: " << dem_doi_xung;
    ToaDo goc;
    goc.x=0;
    goc.y=0;
    for( int i=0 ; i<n ; i++){
        for( int j=i+1 ; j<n ; j++){
            if( tinhKhoangCach(a[j], goc)<tinhKhoangCach(a[i], goc) ) swap(a[i], a[j]);
        }
    }
    cout << "\nThu tu theo khoang cach den goc toa do: \n";
    for( int i=0 ; i<n ; i++){
        cout << "(" << a[i].x << "," << a[i].y << ")\n";
    }
    return 0;
}
