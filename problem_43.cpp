#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl "\n";

void solve()
{

    ll exp , x ;
    cin>>exp>>x;
    ll salary = pow(2,x);
    ll temp = salary;
    ll sumy = 0;
    ll sum = 0;
    while(exp--)
    {
        sum = 0.5*temp;
        temp = temp- sum ;
    }
    cout<<temp<<endl;


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