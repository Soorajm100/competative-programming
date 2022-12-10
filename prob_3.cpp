#include<bits/stdc++.h>
using namespace std ;

typedef long long ll;
#define endl "\n";
int main()
{
    ll n, m ;
    cin>>n>>m;
    vector<ll>machines(n);

    for(ll i=0;i<n;i++){
        cin>>machines[i];
    }

    ll start = 0;
    ll end = 1e18;
    ll ans = 1e18;
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
         ll products = 0 ;
        for(ll i=0;i<n;i++)
        {
            products+= min(mid/machines[i] , (ll)1e9);
        }
        
        if(products>=m)
        {

            if(mid<ans)
            {
                ans = mid;
            }

            end = mid-1;

        }
        else{

            start = mid+1;

        }

    }

    cout<<ans<<endl;

    return 0;
}
