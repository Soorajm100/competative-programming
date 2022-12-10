#include<bits/stdc++.h>
using namespace std ; 

typedef long long ll ;
#define endl "\n"
int main()
{
   ll n ; 
   cin>>n;
   vector<ll>ans(n);

   for(ll i=0;i<n;i++)
   {
    cin>>ans[i];
   }
   bool flag = false;

   sort(ans.begin() , ans.end());

   for(ll i=0;i<ans.size();i++)
   {
      if( i+1<ans.size() and ans[i+1] - ans[i]>1)
      {
        cout<<ans[i+1]-1<<endl;
        flag = true;
        break;
      }
   }

   if(flag==false)
   {
    cout<<n<<endl;
   }

    
    return 0;
}