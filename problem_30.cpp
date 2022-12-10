#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"



const int nax = 5005;
int dp[nax][nax];

int main()
{
    string str , ptr ;
    cin>>str>>ptr;
    for(ll i =0;i<ptr.length()+1;i++)
    {
        dp[0][i] = i;
    }
    for(ll i=0;i<str.length()+1;i++)
    {
        dp[i][0] = i;

    }

    for(ll i = 1;i<str.length()+1;i++)
    {
        for(ll j=1;j<ptr.length()+1 ; j++)
        {
            dp[i][j] = 1e9;

            if(str[i-1]==ptr[j-1])
            {
                dp[i][j] =dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i-1][j]+1 , min(dp[i][j-1] +1, dp[i-1][j-1]+1));
            }
        }

    }

    cout<<dp[str.length()][ptr.length()]<<endl;



    return 0 ;
}