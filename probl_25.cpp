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

const int nax = 1e6+10;
//const int mod = 1e9 + 7;


int main()
{
    ll test;
    cin>>test;
    vector<vector<ll>>dp(nax , vector<ll>(8,0));

    for(ll i=0;i<8;i++)
    {
      dp[0][i]= 1;
    }
    for(ll i=1;i<nax;i++)
    {
      for(ll j=0;j<8;j++)
      {
        if(j==0 or j==2 or j==3 or j==4 or j==5)
        {
          dp[i][j] = (dp[i-1][0]+ dp[i-1][1] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5])%mod;
        }
        else{
          dp[i][j]= (dp[i-1][2] + dp[i-1][6] + dp[i-1][7])%mod;
        }
      }
    }

    while(test--)
    {
      ll n ; 
      cin>>n;
      cout<<(dp[n-1][2] + dp[n-1][6])%mod<<endl;

    }
    


    return 0 ;
}