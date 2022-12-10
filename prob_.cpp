#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define endl "\n";

bool  possible(vector<ll>arr , ll n , ll mid , ll k)
{
    ll add= 0;
    for(ll i=n/2 - (n+1)%2 ;i<n;i++)
    {
        if(mid - arr[i]>0)
        {
            add+=mid -arr[i];

            if(add>k)return false;
        }
    }

    if(add<=k)return true;
    else{
        return false;
    }

}


int solve(vector<ll>&arr, ll n , ll k)
{
    ll low = 1;
    ll maxi = 0;
    maxi = *max_element(arr.begin() , arr.end());
    ll high = k + maxi ; 

    while(low<=high)
    {
        ll mid = (high + low)/2;
        if(possible(arr , n , mid , k))
        {
            low = mid+1;
        }
        else{
           high = mid-1;
        }
    }

    if(n%2==0)
    {
        if(low-1< arr[n/2])
        {
            return (arr[n/2] + low - 1)/2;
        }
    }

    return low-1;

}

int  main()
{

    vector<ll>arr;
    ll n ;
    cin>>n;

    ll k ;
    cin>>k;

    for(ll i=0;i<n;i++)
    {
        ll t;
        cin>>t;
        arr.push_back(t);
    }

    sort(arr.begin() , arr.end());
    cout<<solve(arr , n , k);


    return 0;
}