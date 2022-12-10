#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define endl "\n"
#define For(i,j,n) for(ll i=j;i<n;i++)
#define read(i) cin>>i;
#define  pb push_back();

ll getleft(ll  ele  , vector<ll>&towers)
{
    ll start = 0 ;
    ll end = towers.size()-1;
    ll ans = -1;
    while(start<=end)
    {
        ll mid = start + (end-start)/2;

        if(towers[mid]<=ele)
        {
            if(towers[mid]==ele)
            {
                return ele;
            }
            ans = towers[mid];
            start = mid+1;
            

        }
        else{
            end = mid-1;
        }

    }

    return ans ; 

}
int main()
{

    ll  n , m ;
    cin>>n>>m;
    vector<ll>cities;
    vector<ll>towers;
    for(ll i=0;i<n;i++)
    {
        ll  t;
        cin>>t;
        cities.push_back(t);
    }

    for(ll j=0;j<m;j++)
    {
        ll t;
        cin>>t;
        towers.push_back(t);
    }

    ll mini = INT_MAX;
    ll maxy = INT_MIN;
    for(ll i=0;i<cities.size();i++)
    {
        //cout<<i<<endl;
        ll right = lower_bound(towers.begin(), towers.end() , cities[i]+1) - towers.begin();
       // cout<<right<<endl;
        ll left = getleft(cities[i]+1 , towers);
         cout<<left<<" "<<right<<endl;
        right =  towers[right] - cities[i];
        left =   cities[i] - left;
       
        mini = min(right, left);
        maxy = max(mini, maxy);
        
    }

    cout<<maxy<<endl;


    return 0;

}