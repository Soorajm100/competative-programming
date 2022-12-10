#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n";

int main()
{
    ll n ; 
    cin>>n;
    vector<ll>ans(n);
    for(ll i =0;i<n;i++)cin>>ans[i];
    sort(ans.begin() , ans.end());

    if(n%2==1)
    {
        ll sumy = 0;
         ll ele = ans[(n-1)/2];
         for(ll i = 0;i<n;i++)
         {
            sumy+=abs(ans[i] - ele);
         }
         cout<<sumy<<endl;
    }
    else{
        
        ll sumy1 = 0;
        ll sumy2 = 0;
        ll ele1 = ans[(n)/2];
        ll ele2 = ans[n/2 - 1];
         for(ll i = 0;i<n;i++)
         {
            sumy1+=abs(ans[i] - ele1);
         }
         for(ll i = 0;i<n;i++)
         {
            sumy2+=abs(ans[i] - ele2);
         }
         cout<<min(sumy1 , sumy2)<<endl;
         

    }

    return 0 ;
}