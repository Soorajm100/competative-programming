#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n"

int main()
{
    ll n; 
    cin>>n;
    vector<pair<ll  ,ll>>v;
    for(ll i=0;i<n;i++)
    {
        ll a , b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    map<ll, ll>mp;
    set<ll>st;
    for(ll i=0;i<v.size();i++)
    {
        mp[v[i].first] = 1;
        mp[v[i].second] = -1;
        st.insert(v[i].first);
        st.insert(v[i].second);
    }

    ll count = 0;
    ll maxy = INT_MIN;
    for(auto x : st)
    {
        count+=mp[x];
        maxy = max(maxy , count);
    }
    cout<<maxy<<endl;




    return 0;
}