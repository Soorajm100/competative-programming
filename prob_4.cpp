#include<bits/stdc++.h>
using namespace std ;

typedef long long ll;
#define endl "\n"

bool ispossible(ll mid , vector<ll>&arr , ll k)
{

    ll sum = 0;
    ll count = 0 ;
    for(ll i=0;i<arr.size();i++)
    {
        sum +=arr[i];
        if(sum>mid)
        {
            count++;
            sum = 0;
        }
        if(count>k)
        {
            return  false; 
        }
    }

    return (count==k);

}


int main()
{
    ll n , k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    ll start = *max_element(arr.begin() , arr.end()) ; 
    ll end = 1e18;
    ll ans = 1e18;
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        ll blocks= 1 ;
        ll sum =  0 ;
        for(ll i =0;i<n;i++)
        {
            if(sum + arr[i] > mid)
            {
                sum = 0;
                blocks++;
            }

            sum+= arr[i];
        }

        if(blocks>k)
        {
            start = mid + 1 ;
        }
        else{

            if(mid<ans)
            {
                ans =  mid ;
            }
            end = mid-1;

        }
    }

    cout<<ans<<endl;

    return 0 ;
}