#include<bits/stdc++.h>
using namespace std ; 

typedef long long ll;
#define endl "\n"

int main()
{
    ll n = 5;
   
     
    ll test;
    cin>>test;
    while(test--)
    {
      ll x ,y;
      cin>>x>>y;
      if(x<y)
      {
        ll ans = 0;
        if(y%2!=0)
        {
            ans = y*y - x+1;
        }
        else{
            ans = (y-1)*(y-1) + x;
        }
        cout<<ans<<endl;
      }
      else{
           
           ll ans = 0;
           if(x%2!=0)
           {
            ans = (x-1)*(x-1) + y;

           }
           else{
            ans = x*x -y+1;
           }
           cout<<ans<<endl;

      }
    }
    return 0;
}