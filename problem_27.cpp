#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define endl "\n";
void dfs(ll i , ll j , vector<string>&ans , ll n, ll m , vector<vector<bool>>&vis)
{
    if(i<0 or i>=n or j<0 or j>=m or vis[i][j]==true or ans[i][j]=='#')
    {
        return ; 
    }
    vis[i][j]  = true;
   // cout<<i<<j<<" ";
    dfs(i+1 , j , ans , n , m , vis);
    dfs(i , j+1 , ans , n , m , vis);
    dfs(i , j-1 , ans , n , m , vis);
    dfs(i-1 , j , ans , n , m , vis);


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

    for(ll i =0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(ans[i][j]=='.' and vis[i][j]==false)
            {
                count++;
                dfs(i,j, ans , n , m , vis);
            }
        }
    }
    cout<<count<<endl;

    return 0;
}