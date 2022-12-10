#include<bits/stdc++.h>
using namespace std  ;

typedef long long ll;
#define endl "\n"
ll mod = 1e9 + 7;
ll solve( ll n , vector<ll>&dp)
{

    
    if(n<0)return 0   ;

    if(n==0)
    {
        return 1;
    }


    if(dp[n]!=-1)return dp[n];

    ll out = 0;
    for(ll i=1;i<=6;i++)
    {
        out+= solve(n-i , dp);
    }

    return dp[n] = out%mod;

}

int main()
{ 

    ll n ;
    cin>>n;
    vector<ll>ans(6);
    for(ll i= 1;i<=6;i++)ans[i-1] =i; 
     ll target = n ;
     ll count=  0;
     vector<ll>dp(n+1 , -1);
     cout<<solve(n , dp)%mod<<endl;
    return 0 ; 
}