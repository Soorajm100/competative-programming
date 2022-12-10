// one of the good problems for dynamic programming  
// 3 cases 

/*
 one we take the number 
 one left of the numbet case 
 one right to the number case 
 if its  0 we have many  possibi;ites so we do looping 
 if its not zero then  we have only one possibilites so  lucky :)
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n";
ll mod = 1e9 +7;

int main()
{
    ll n , m ;
    cin>>n>>m;
    vector<ll>ans(n);
    for(ll i =0;i<n;i++)cin>>ans[i];
    vector<vector<ll>>dp(n+1 , vector<ll>(m+1 , 0));
    if(ans[0]!=0)dp[0][ans[0]] = 1 ;
    else{
        for(ll i=1;i<=m;i++)
        {
            dp[0][i]= 1 ;
        }
    }
    for(ll i = 1 ; i<n;i++)
    {
        if(ans[i]==0)
        {
            for(ll j=1;j<=m;j++)
            {
                if(j-1>=1)
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
                }

                dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;

                if(j+1<=m)
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mod;
                }

            }            
        }
        else{

            if(ans[i]-1>=0)
            {
                dp[i][ans[i]] = (dp[i][ans[i]] + dp[i-1][ans[i]-1])%mod;

            }

            dp[i][ans[i]] = (dp[i][ans[i]] + dp[i-1][ans[i]])%mod;

             if(ans[i]+1<=m)
            {
                dp[i][ans[i]] = (dp[i][ans[i]] + dp[i-1][ans[i]+1])%mod;

            }
        }
    }

    ll total = 0 ;
    for(ll i=1;i<=m;i++)
    {
        total=( total + dp[n-1][i])%mod;
    }

    cout<<total<<endl;


    return 0 ;
}