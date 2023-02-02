#include <iostream>
using namespace std;
struct Dathuc{
    int bac;
    double mang_he_so[100];
};
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
int main()
{
    double a, b;
    int n;
    cout << "Nhap lan luot a, b, n cua da thuc (a+b)^n: ";
    cin >> a >> b >> n;
    Dathuc dt, dt_nho;
    // tao da thuc bac 1
    dt.bac=1;
    dt.mang_he_so[0]=a;
    dt.mang_he_so[1]=b;
    // Tao da thuc tich luy
    dt_nho.bac=0;
    dt_nho.mang_he_so[0]=1;
    //Tam giac pascal
    cout << "Tam giac pascal: \n";
    cout << "1\n";
    for( int i=0 ; i<n ; i++){
        Dathuc dt_tich;
        tich( dt, dt_nho, dt_tich);
        for( int i=0 ; i<=dt_tich.bac ; i++){
            cout << dt_tich.mang_he_so[i] << " ";
        }
        cout << endl;
        dt_nho=dt_tich;
    }
    // tinh gia tri (a+b)^n
    double sum=0;
    for( int i=0 ; i<=dt_nho.bac ; i++){
        sum+=dt_nho.mang_he_so[i];
    }
    cout << "\nGia tri cua da thuc (a+b)^n: " << sum;
    //He so cua so hang thu i
    cout << "\nNhap so hang muon tim he so: ";
    int i;
    cin >> i;
    cout << "\nHe so cua so hang thu " << i << " la: ";
    cout << dt_nho.mang_he_so[i-1];
    return 0;
}