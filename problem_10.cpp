#include<bits/stdc++.h>
using namespace std ;
 
typedef long long ll;
#define  endl "\n";
 
int main()
{
    ll n , m ,k ;
    cin>>n>>m>>k;
    vector<ll>applicants(n);
    vector<ll>apartmets(m);
    for(ll i=0;i<n;i++)cin>>applicants[i];
    for(ll i=0;i<m;i++)cin>>apartmets[i];
    sort(applicants.begin(), applicants.end());
    sort(apartmets.begin() , apartmets.end());
    ll i=0;
    ll j=0;
    ll matches = 0;
    while(i<n)
    {
        while(j<m and apartmets[j]<applicants[i]-k)
        {
            j++;
        }
        if(abs(apartmets[j] - applicants[i])<=k)
        {
            matches++;
            i++;
            j++;
        }
        else{
            i++;
        }
    }

    cout<<matches<<endl;

    return 0;
}