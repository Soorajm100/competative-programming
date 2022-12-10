#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define endl "\n";
string res ="";
bool  dfs(ll i , ll j , vector<string>&ans , ll n, ll m , vector<vector<bool>>&vis , string st)
{
    if(i<0 or i>=n or j<0 or j>=m or vis[i][j]==true or ans[i][j]=='#')
    {
        return  false; 
    }

    if(ans[i][j]=='B')
    {
        res = st;
        return true;
    }

    vis[i][j]  = true;
   // cout<<i<<j<<" ";
    return (dfs(i+1 , j , ans , n , m , vis , st+'D') or
    dfs(i , j+1 , ans , n , m , vis ,st+'R') or
    dfs(i , j-1 , ans , n , m , vis ,st+ 'L') or
    dfs(i-1 , j , ans , n , m , vis ,st + 'U') );


}

int main()
{

    ll n , m ;
    cin>>n>>m;
    vector<string>ans(n);
    vector<vector<bool>>vis(n+1 , vector<bool>(m+1 , false));
    for(int i=0;i<n;i++)
    {
        cin>>ans[i];
    }
    ll count=  0;
    string st ="";
    for(ll i =0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(ans[i][j]=='A' and vis[i][j]==false)
            {
                
                if(dfs(i,j, ans , n , m , vis , st)){
                    cout<<"YES"<<endl;
                    cout<<res.length()<<endl;
                    cout<<res<<endl;
                    break;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    

    return 0;
}