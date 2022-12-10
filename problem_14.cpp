#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n";

int main()
{  
    ll n ;
    cin>>n;
    vector<ll>ans(n);
    for(ll i=0;i<n;i++)cin>>ans[i];

   ll sum = 0;
   ll maxy = INT_MIN;
    for(ll i=0;i<n;i++)
    {
         if(sum<0)
        {
            sum = 0;
        }
        sum +=ans[i];
       
        maxy = max(maxy , sum);
    }
    cout<<maxy<<endl;

    return 0 ;
}