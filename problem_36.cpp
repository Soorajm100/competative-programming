#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

const int nax = 505;

int dp[505][505];
int main()
{

    ll width ,height ; 
    cin>>width>>height;

    for(ll i=1;i<=width;i++)
    {
        for(ll j=1;j<=height;j++)
        {
            dp[i][j] = 1e9;
        }

    }

    for(ll i=1;i<nax;i++)
    {
        dp[i][i] =0;
    }


     for(ll i=1;i<=width;i++)
    {
        for(ll j=1;j<=height;j++)
        {
            for(ll cut=1;cut<=i;cut++)
            {
                dp[i][j] = min(dp[i][j] , dp[cut][j] + dp[i-cut][j]+1 );

            }

            for(ll cut=1;cut<=j;cut++)
            {
                dp[i][j] = min(dp[i][j] , dp[i][cut] + dp[i][j-cut]+1 );

            }
        }

    }
    
    
    cout<<dp[width][height]<<endl;
    return 0;
}