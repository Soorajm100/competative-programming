#include<bits/stdc++.h>
using namespace std ; 

typedef long long ll ;
#define endl  "\n";

int main()
{
    ll n  ; 
    cin>>n;
    vector<ll>ans(9);
    vector<ll>dp(n+1 ,INT_MAX );
    for(ll i = 1 ; i<=ans.size();i++)ans[i-1] = i;
    dp[0] = 0;
 
    for(ll i= 0 ; i<=n;i++)
    {
        ll ele = i;
        while(ele>0)
        {
            dp[i] = min(dp[i] , dp[i-ele%10] +1);
            ele = ele/10;

        }
    }

    cout<<dp[n]<<endl;

    return 0 ; 
}