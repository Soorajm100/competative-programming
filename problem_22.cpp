#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll;

#define endl "\n"
ll mod = 1e9+7;

ll solve(vector<string>&grid , ll i , ll j  , vector<vector<bool>>&vis,vector<vector<ll>>&dp)
{
    if(i<0 or i>=grid.size() or j<0 or j>=grid[i].size() or grid[i][j]=='*' )
    {
        return 0;
    }
    if(i==grid.size()-1 and j== grid[i].size()-1)
    {
        return 1 ; 
    }
    if(dp[i][j]!=-1)return dp[i][j];

    vis[i][j] = true;

    ll out ;
    out =solve(grid , i , j+1 , vis , dp )+solve(grid ,  i+ 1 , j , vis , dp);;
 

    return  dp[i][j] = out%mod; 

}
int main()
{
    ll n;  
    cin>>n;
    vector<string>grid(n);
    for(ll i =0;i<n;i++)cin>>grid[i];
    vector<vector<bool>>vis(n+1  , vector<bool>(n+1 , false));
    vector<vector<ll>>dp(n+1  , vector<ll>(n+1 , 1));
    if(grid[n-1][n-1]=='*')
    {
        cout<<0<<endl;
        return 0 ; 
    }

    bool flag = false;
    for(ll i =0;i<n;i++)
    {
        if(flag==true or grid[0][i]=='*')
        {
            flag = true;
            dp[0][i] = 0 ;
        }else{
            dp[0][i] = 1;
        }
    }

    flag = false;
    for(ll i =0;i<n;i++)
    {
        if(flag==true or grid[i][0]=='*')
        {
            flag = true;
            dp[i][0] = 0 ;
        }else{
            dp[i][0] = 1;
        }
    }



     for(ll i =1;i<n;i++)
     {
        for(ll j=1;j<n;j++)
        {
            if(grid[i][j]=='*')
            {
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = (dp[i-1][j]  + dp[i][j-1])%mod;
            }
        }
     }

     cout<<dp[n-1][n-1]%mod<<endl;

    return 0 ;
}