#include <bits/stdc++.h>
using namespace std;
int main()
{
    int lt ;
    float th[10], gk[2], ck, st;
    float b=0, sum_th=0, sum_gk=0 ;
    cin >> lt ;
    for( int i=0 ; i<10 ; i++){
        cin >> th[i];
    }
    for( int i=0 ; i<10 ; i++){
        for( int j=i+1 ; j<10 ; j++){
            if( th[j]>th[i] ){
                int nho=th[i];
                th[i]=th[j];
                th[j]=nho;
            }
        }
    }
    for( int i=0 ; i<5 ; i++){
        sum_th+=th[i];
    }
    for( int i=0 ; i<2 ; i++){
        cin >> gk[i];
        sum_gk+=gk[i];
    }
    cin >> ck >> st;
    for( int i=0 ; i<10 ; i++){
        if( th[i]!=0 ) {
            b++;
        }
    }
    float a=(double)(2*sum_th/5)/2;
    float c=(double)(sum_gk)/2;
    float d=(double)(2*(st+ck))/2;
    float tk=0.2*a+0.2*c+0.6*d;
    if( lt+b<20 ) cout << "0.0";
    else if( tk>10.0 ) cout << "10.0";
    else cout << fixed << setprecision(1) << tk ;
    return 0;
}