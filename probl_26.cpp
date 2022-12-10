#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll;
#define endl "\n"

int main()
{
    ll n ;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)cin>>arr[i];
    ll ans= 1;
    sort(arr.begin() , arr.end());
    for(ll i=0;i<n;i++)
    {
        if(ans<arr[i])
        { 
            break;
        }
        else{
            ans+=arr[i];
        }
    }

    cout<<ans<<endl;
    return 0;
}