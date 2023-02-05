#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countString( string s ){
    vector<int> a(26,0);
    int ans=0;
    for( int i=0 ; i<s.size() ; i++){
        if( a[s[i]-'a']==0 ) ans++;
        a[s[i]-'a']++;
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n;
    int ans[n];
    for( int i=0 ; i<n ; i++){
        vector<int> check(26,0);
        int j=1;
        string s, a, b;
        cin >> m >> s;
        for( int l=0 ; l<m ; l++){
            if( check[s[l]-'a']!=0 ){
                j=l;
                break;
            }
            else check[s[l]-'a']++;
        }
        for( int k=0 ; k<m ; k++){
            if( k<j ) a+=s[k];
            else b+=s[k];
        }
        ans[i]=countString(a)+countString(b);
    }
    for( int i=0 ; i<n ; i++){
        cout << ans[i] << endl;
    }
    return 0;
}