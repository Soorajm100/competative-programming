// coin change problem 2 
// make a detailed  notes from it
// very  important problem 


#include<bits/stdc++.h>
using namespace std  ;

typedef long long ll;
#define endl "\n";
ll mod = 1e9 + 7;

int main()
{ 

    ll n , target ;
    cin>>n>>target;
    vector<ll>ans(n);
    for(ll i= 0;i<n;i++)cin>>ans[i]; 
     ll count=  0;
    vector<ll>dp(target+1 , 0);
  
     //memset(dp, 0 , sizeof(dp));
     dp[0] = 1 ; 
    
     for( ll j=0;j<n;j++)
     {
        for(ll i = 1 ; i<=target;i++)
        {
            if(i-ans[j]>=0)
            {
                dp[i] = (   dp[i-ans[j]] + dp[i]  )%mod  ; 
            }
       
        }
     }
     




    cout<<dp[target]%mod<<endl;


    return 0 ; 
}