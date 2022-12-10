#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl "\n";

void solve()
{
    ll n ;
    cin>>n;
    string s; 
    cin>>s;
    map<pair<char , ll> , ll>fr ;
    char curr = s[0] ;
    ll len = 1;
    fr[{curr , len}]++;
    for(ll i=1;i<n;i++)
    {
        if(curr!=s[i])
        {
            len = 1;
            curr = s[i];
        }
        else{
            len++;
           
        }
         fr[{curr , len}]++;
    }

    ll maxi = 0;
    for(auto x : fr)
    {
        if(x.second==1)
        {
            maxi = max(maxi , x.first.second-1);
            continue;
        }
        maxi = max(maxi , x.first.second);
    }
    cout<<maxi<<endl;
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