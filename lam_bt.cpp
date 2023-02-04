#include <iostream>
#include <vector>
using namespace std;
    vector<vector<int>> insert(vector<vector<int>>& s, vector<int>& news) {
        vector<int>c;
        int n = s.size();
        for( int i=0 ; i<s.size() ; i++){
        for(int j = 0; j< 2; j++)c.push_back(s[i][j]);}
            int a = 0 ,b = 0;
            vector<int> d;
            while(a < c.size()&& b < 2)
            {   
                if(c[a]>=news[b]){
                {d.push_back(news[b]);b++;}}
                else{d.push_back(c[a]);a++;}
                if(a>=c.size()||b>=2){
                 while (a<c.size())
                 {
                    d.push_back(c[a]);a++;
                 }
                 while(b<2)
                 {
            
                    d.push_back(news[b]);b++;
                 }}
            }int k = 0;
            vector<vector<int>> ans;
            vector<int> temp;
            for( int i=1 ; i<d.size() ; i++){
                if( d[i]-d[i+1]==1 ) temp.push_back(d[i]);
                else{
                    ans.push_back(temp);
                    temp={};
                } 
            }
            for(int i= 0 ;i < n+1 ;i ++)
            for(int j = 0;j < 2; j++)
            {s[i][j] = d[k];k++;}
            return ans;
    }
int main()
{
    vector<vector<int>> a={{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> b={4,8};
    vector<vector<int>> c = insert(a, b);
    for( int i=0 ; i<c.size() ; i++){
        for( int j=0 ; j<2 ; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}