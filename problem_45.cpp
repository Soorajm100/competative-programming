#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl "\n";

ll mod = 998244353;

void solve()
{
    ll  n ;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll prod1 = 1;
    ll prod2 = 1;
    ll count = 0;
    vector<ll>even;
    vector<ll>odd;
    for(ll i=0;i<n;i++)
    {
        if(a[i]==1)count++;
        if(a[i]%2==1)
        {
            odd.push_back(a[i]);
        }
        else{
            even.push_back(a[i]);
        }
    }

    for(ll i=0;i<count and i<even.size();i++)
    {
        even[i]++;
    }

    for(ll i=0;i<even.size();i++)
    {
        prod1 = (prod1*even[i])%mod;
    }

    for(ll i=0;i<odd.size();i++)
    {
        prod2 = (prod2*odd[i])%mod;
    }

    cout<<(prod1*prod2)%mod<<endl;


 
}

int main()
{
    
    ll test ;
    cin>>test;
    while(test--)
    {
        solve();
    }
    
    return 0;
}