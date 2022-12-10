#include<bits/stdc++.h>
using namespace std; 

typedef long long ll;
#define endl "\n";

int main()
{
    ll n ,x ; 
    cin>>n>>x;
    vector<ll>ans(n);
    for(ll i=0;i<n;i++)cin>>ans[i];
    bool flag = false;
    map<int, int>mp;
    ll pos1 ; 
    ll pos2 ;
    for(ll  i=0;i<n;i++)
    {
        if(mp.find(x-ans[i])!=mp.end() and i!=mp[x-ans[i]])
        {
            pos1 = i;
            pos2 = mp[x-ans[i]];
            flag = true;
            break;
        }
        else{
         mp[ans[i]]= i;
        }
    }
  if(flag){
    vector<ll>pt;
    pt.push_back(pos1+1);
    pt.push_back(pos2+1);
    sort(pt.begin() , pt.end());

    for(auto x : pt)
    {
        cout<<x<< " ";
    }
    cout<<endl;
  }
  else{
     cout<<"IMPOSSIBLE"<<endl;
  }

    return  0;
}