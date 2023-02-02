#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    char a[m][n];
    for( int i=0 ; i<m ; i++){
        for( int j=0 ; j<n ; j++){
            cin >> a[i][j];
        }
    }
    // Xet hang
    for( int i=0 ; i<m ; i++){
        for( int j=0 ; j<=n-5 ; j++){
            if( a[i][j]!='.' ){
                int dem=0;
                for( int k=0 ; k<5 ; k++){
                    if( a[i][j+k]==a[i][j] ) dem++;
                }
                if( dem==5 ){
                    if( a[i][j]=='X' ) cout << "-1";
                    else cout << "1";
                    return 0;
                }
            }
        }
    }
    //Xet cot
    for( int i=0 ; i<n ; i++){
        for( int j=0 ; j<=m-5 ; j++){
            if( a[i][j]!='.' ){
                int dem=0;
                for( int k=0 ; k<5 ; k++){
                    if( a[j+k][i]==a[j][i] ) dem++;
                }
                if( dem==5 ){
                    if( a[j][i]=='X' ) cout << "-1";
                    else cout << "1";
                    return 0;
                }
            }
        }
    }
    // Xet cheo chinh
    for( int i=0 ; i<=m-5 ; i++){
        for( int j=0 ; j<=n-5 ; j++){
            if( a[i][j]!='.' ){
                int dem=0;
                for( int k=0 ; k<5 ; k++){
                    if( a[i+k][j+k]==a[i][j] ) dem++;
                }
                if( dem==5 ){
                    if( a[i][j]=='X' ) cout << "-1";
                    else cout << "1";
                    return 0;
                }
            }
        }
    }
    //Xet cheo phu
    for( int i=0 ; i<=m-5 ; i++){
        for( int j=4 ; j<n ; j++){
            if( a[i][j]!='.' ){
                int dem=0;
                for( int k=0 ; k<5 ; k++){
                    if( a[i+k][j-k]==a[i][j] ) dem++;
                }
                if( dem==5 ){
                    if( a[i][j]=='X' ) cout << "-1";
                    else cout << "1";
                    return 0;
                }
            }
        }
    }
    cout << "0";
}