// vv importtwnt dp problem get to learn lot from this. 

#include<bits/stdc++.h>
using namespace std ; 

typedef long long  ll;
#define endl "\n"
ll mod = 1e9 + 7;
void read(ll n , vector<int>&ans)
{
    for(ll i= 0;i<n;i++)
    {
        cin>>ans[i];
    }
}

void print(ll n , vector<int>&ans)
{
    for(ll i = 0;i<n;i++)
    {
        cout<<ans[i]<<" " ;
    }
    cout<<endl;
}

int main()
{
    int n ,x ; 
    cin>>n>>x;
    vector<int>price(n);
    vector<int>pages(n);
    read(n , price);
    read(n, pages);
   vector<vector<int>>dp(n+1 , vector<int>(x+1 , 0));
   ll maxy =INT_MIN;
   ll sum=0 ; 
   

   for(ll i= 0;i<n;i++)
   {
    for(ll j = 0 ;j<=x;j++)
    {
        dp[i+1][j] = dp[i][j]%mod;

        if(j-price[i]>=0)
        {
            dp[i+1][j] = max(dp[i+1][j] , pages[i] + dp[i][j-price[i]])%mod;

        }
    }

   }

   cout<<dp[n][x]%mod<<endl;

    return 0 ;
}