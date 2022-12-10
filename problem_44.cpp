#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl "\n";

void solve()
{
    ll n , x,c; 
    cin>>n>>x>>c;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll sum = 0;
    ll count=  0;
    for(ll i=0;i<n;i++)
    {
        if(x-a[i]>c)
        {
            sum+=x;
            count+=c;
        }
        else{
            sum+=a[i];
        }
       
    }

    cout<<sum-count<<endl;
    
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