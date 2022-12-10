#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n"
vector<vector<ll>>res;
void solve(vector<ll>&set1 , ll target , ll ind , vector<ll>&numbers)
{
    
    if(ind>=numbers.size())return ;
    if(target==0)
    {
        res.push_back(set1);
        return ;
    }

    if(target>=numbers[ind])
    {
        set1.push_back(numbers[ind]);
        solve(set1 , target-numbers[ind] , ind+1 , numbers );
        solve(set1 , target , ind+1 , numbers);
         set1.pop_back();
      
    
    }

   solve(set1 , target , ind+1 , numbers);
   // set1.pop_back();
}

int main()
{
  
   ll n;
   cin>>n;

   ll sum = n*(n+1)/2;

   vector<ll>numbers;
   for(ll i=1;i<=n;i++)
   {
    numbers.push_back(i);
   }

   if(sum%2==0)
   {
      
      ll target = sum/2;
       vector<ll>set1;
       vector<ll>set2;
      solve(set1 , target , 0 , numbers);

     for(auto x :res)
     {
        for(auto m :x)
        {
            cout<<m<<" ";

        }
        cout<<endl;
     }


   }
   else{
    cout<<"NO"<<endl;
   }


    return 0;
}