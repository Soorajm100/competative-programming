#include<bits/stdc++.h>
using namespace std ; 

typedef long long ll;
#define endl "\n"

int f(int ind , vector<ll>&coins , int target , vector<vector<ll>>&dp){
        if(ind<0)return 0;
        if(ind==0){
            if(target%coins[0]==0)return target/coins[0];
            else return 1e9;
        }
        
        
       
        
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        
        int pick = INT_MAX , notpick;
        
        notpick = 0 + f(ind-1 , coins , target , dp);
        if(coins[ind]<=target){
            pick =1 + f(ind , coins , target-coins[ind] , dp);
        }
        
        
        
        return dp[ind][target] = min(pick , notpick);
        
        
    }

int main()
{

    ll n , target ; 
    cin>>n>>target;
    vector<ll>ans(n);
    for(ll i=0;i<n;i++)cin>>ans[i];
    vector<vector<ll>>dp(n+1 , vector<ll>(target+1 , -1));
    cout<<f(ans.size() ,ans ,target  , dp )<<endl;
    return 0 ;
}