#include<bits/stdc++.h>
using namespace std ;

typedef long long ll;
#define endl "\n"

int main()
{
    
    ll n ;
    cin>>n;
    vector<ll>ans(n);
    for(ll i=0;i<n;i++)
    {
        cin>>ans[i];
    }

    ll final = 0;
    for(ll i=1;i<n;i++)
    {
        if(ans[i-1]>ans[i])
        {
            final+=ans[i-1]-ans[i];
            ans[i] = ans[i-1];
        }


    }

    cout<<final<<endl;


    return 0;
}
