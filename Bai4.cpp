#include <iostream>
#include <string>
using namespace std;
struct Date{
    int d, m, y;
    void nhapDate(){
        string dd, mm, yy;
        getline(cin, dd, '/');
        d=stoi(dd);
        getline(cin, mm,'/');
        m=stoi(mm);
        getline(cin, yy);
        y=stoi(yy);
    }   
    void inDate() const{
        cout << d << "/" << m << "/" << y;
    }
};
struct DiemMonHoc{
    double tp[10], ck, tk;
    int heso_tp[10], heso_ck;
    char xlsv;
    void nhapDiem(){
        int n;
        cout << "Nhap so luong diem thanh phan: ";
        cin >> n;
        for( int i=0 ; i<10 ; i++){
            if( i>n-1 ){
                heso_tp[i]=-1; // Xac dinh so luong diem thanh phan
                break;
            }
            cout << "Nhap diem thanh phan thu " << i+1 << ": ";
            cin >> tp[i];
            cout << "He so: ";
            cin >> heso_tp[i];
        }
        cout << "\nNhap diem cuoi ky: ";
        cin >> ck;
        cout << "Nhap he so diem cuoi ky: ";
        cin >> heso_ck;
    }
    void inDiem() const {
        int i=0;
        while( heso_tp[i]!=-1 ){
            cout << "\nDiem thanh phan thu " << i+1 << ": " << tp[i];
            cout << "\tHe so: " << heso_tp[i];
            i++;
        }
        cout << "\nDiem cuoi ky: " << ck << "\tHe so: " << heso_ck;
    }
};
struct SinhVien{
    int msv;
    string ten;
    Date ns;
    DiemMonHoc int1008;
};
void nhapSinhVien(SinhVien& sv){
    cout << "\nNhap ma sinh vien: ";
    cin >> sv.msv;
    cout << "Nhap ho va ten: ";
    getline(cin, sv.ten); // Do khi nhap msv xong dung enter thi lenh getline mat nen ta phai getline 2 lan
    getline(cin, sv.ten);
    cout << "Nhap ngay sinh (theo dang dd/mm/yyyy) : ";
    sv.ns.nhapDate();
    cout << "\nNhap diem:\n";
    sv.int1008.nhapDiem();
}
void inSinhVien( const SinhVien& sv){
    cout << "Ho va ten: " << sv.ten;
    cout << "\nMa sinh vien: " << sv.msv;
    cout << "\nNgay sinh: " ;
    sv.ns.inDate();
    cout << "\nDiem mon hoc cua sinh vien:\n";
    sv.int1008.inDiem();
}
void dtkSinhVien(SinhVien& sv){
    // Tong diem= diem * he so
    // Diem tong ket= Tongdiem/tong_heso
    double tong_diem=sv.int1008.ck*sv.int1008.heso_ck;
    int tong_heso=sv.int1008.heso_ck;
    for( int j=0 ; j<10 ; j++){
        if( sv.int1008.heso_tp[j]== -1 ) break;
        else{
            tong_diem+=sv.int1008.tp[j]*sv.int1008.heso_tp[j];
            tong_heso+=sv.int1008.heso_tp[j];
        }
    }
    sv.int1008.tk=tong_diem/tong_heso;
}
void xhSinhVien(SinhVien& sv){
    if( sv.int1008.tk>=8.5 ) sv.int1008.xlsv='A';
    else if( sv.int1008.tk>=7 ) sv.int1008.xlsv='B';
    else if( sv.int1008.tk>=5.5 ) sv.int1008.xlsv='C';
    else if( sv.int1008.tk>=4 ) sv.int1008.xlsv='D';
    else sv.int1008.xlsv='F';
}
int main()
{
    int n;
    double tong_diem=0;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    SinhVien sv[n];
    for( int i=0 ; i<n ; i++){
        cout << "\nSinh vien " << i+1 << ":";
        nhapSinhVien(sv[i]);
        dtkSinhVien(sv[i]);
        xhSinhVien(sv[i]);
        tong_diem+=sv[i].int1008.tk;
    }
    // Diem trung binh ca lop
    cout << "\nDiem trung binh mon hoc cua ca lop: " << (double)tong_diem/n;
    // sap xep diem tu cao den thap
    for( int i=0 ; i<n ; i++){
        for( int j=i+1 ; j<n ; j++){
            if( sv[j].int1008.tk > sv[i].int1008.tk ) swap(sv[i], sv[j]);
        }
    }
    cout << '\n';
    cout << "\nSap xep sinh vien co diem tu cao den thap:\n" << endl;
    for( int i=0 ; i<n ; i++){
        cout << sv[i].ten << '\t' << sv[i].msv << '\t' << sv[i].int1008.tk << endl; 
    }
    // Dem xep loai hoc tap
    int dem_A=0, dem_B=0, dem_C=0, dem_D=0, dem_F=0;
    for( int i=0 ; i<n ; i++){
        if( sv[i].int1008.xlsv=='A' ) dem_A++;
        else if( sv[i].int1008.xlsv=='B' ) dem_B++;
        else if( sv[i].int1008.xlsv=='C' ) dem_C++;
        else if( sv[i].int1008.xlsv=='D' ) dem_D++;
        else dem_F++;
    }
    cout << "\nSo sinh vien dat diem A: " << dem_A;
    cout << "\nSo sinh vien dat diem B: " << dem_B;
    cout << "\nSo sinh vien dat diem C: " << dem_C;
    cout << "\nSo sinh vien dat diem D: " << dem_D;
    cout << "\nSo sinh vien dat diem F: " << dem_F << endl;
    // sinh vien truot mon
    cout << "\nMa sinh vien cua cac sinh vien truot mon:\n";
    for( int i=0 ; i<n ; i++){
        if( sv[i].int1008.xlsv=='F' ) cout << sv[i].msv << endl;
    }
    if( dem_F==0 ) cout << "None";
    return 0;
}