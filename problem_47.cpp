#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl "\n";

void solve()
{
    ll n  , q;
    cin>>n ;
    int a[n];
    int mn = INT_MAX;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        if(mn>a[i])
        {
            mn = a[i];
        }
    }

    ll ans = 0;
    ll temp = 0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]!=mn)
        {
            if(a[i]%mn==0)
            {
                ans++;
            }
            else{
                temp = 1;
                break;
            }

        }
    }

    if(temp)
    {
        cout<<n<<endl;
    }
    else{
        cout<<ans<<endl;
    }
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