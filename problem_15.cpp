#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"


int main()
{

    ll n , m ;
    cin>>n>>m;
    vector<ll>tickets(n);
    vector<ll>customers(m);
    set<pair<ll,ll>>sortedtickets;

    for(ll i=0;i<n;i++)
    {
        cin>>tickets[i];
        sortedtickets.insert({tickets[i] , i});
    }
    for(ll i=0;i<m;i++)
    {
        cin>>customers[i];
    }
    for(ll i=0;i<m;i++)
    {
        auto match = sortedtickets.lower_bound({customers[i]+1 , 0});
        if(match==sortedtickets.begin())cout<<-1<<endl;
        else{
            match--;
            cout<<(*match).first<<endl;
            sortedtickets.erase(match);
        }
    }

    return  0;
}