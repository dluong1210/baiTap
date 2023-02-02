#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n=s1.size(), m=s2.size(), day, nho=0;
    if( n>=m ) day=n;
    else day=m;
    for( int i=day-1 ; i>=0 ; i--){
        if( i>=day-n ) s1[i]=s1[i-day+n];
        else s1[i]='0';
    }
    for( int i=day-1 ; i>=day-m ; i--){
        if( i>=day-n ) s2[i]=s2[i-day+m];
        else s2[i]='0';
    }
    int sum[day+1];
    sum[0]=0;
    for( int i=day-1 ; i>=0 ; i--){
        if( s1[i]-'0'+s2[i]-'0'>9 ){
            sum[i+1]=s1[i]-'0'+s2[i]-'0'-10+nho;
            nho=1;
            if( i==0 ){
                sum[0]=1;
            }
        }
        else{
            sum[i+1]=s1[i]-'0'+s2[i]-'0'+nho;
            nho=0;
        }
    }
    if( sum[0]==1 ) cout << sum[0];
    for( int i=1 ; i<day+1 ; i++){
        cout << sum[i];
    }
    return 0;
}