#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define endl "\n";

int main()
{ 

    ll n ,x; 
    cin>>n>>x;
    vector<ll>ans;
    for(ll i=0;i<n;i++)
    {
        ll t;
        cin>>t;
        ans.push_back(t);
    }

    sort(ans.begin() , ans.end());
   
    ll start = 0;
    ll end = ans.size() - 1;
    ll gondola = 0;
    while(start<=end)
    {
        if(ans[start] +ans[end] <=x)
        {
            start++;
            end--;
            gondola++;
        }
        else{
            end--;
            gondola++;
        }

    }
    cout<<gondola<<endl;

 return 0;


}