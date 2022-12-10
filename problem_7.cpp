#include<bits/stdc++.h>
using namespace std ;

typedef long long ll;
#define endl "\n";

int main()
{

    ll n ;
    cin>>n;

     deque<int> number;
     
     if(n==1)
     {
        cout<<1<<endl;

     }
     if(n<=3 and n>=2)
     {
        cout<<"NO  SOLUTION"<<endl;
    
     }
     if(n==4)
     {
        number.push_back(2);
        number.push_back(4);
        number.push_back(1);
        number.push_back(3);
        for(auto x : number)
        {
            cout<<x<<" ";
        }
        cout<<endl;
       

     }
     else if(n==5){
        number.push_back(4);
        number.push_back(2);
        number.push_back(5);
        number.push_back(3);
        number.push_back(1);
        for(auto x : number)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    

     }
     else{

        number.push_back(4);
        number.push_back(2);
        number.push_back(5);
        number.push_back(3);
        number.push_back(1);

        for(ll i=6;i<=n;i++)
        {
            if(i%2==0)
            {
                number.push_back(i);
            }
            else{
                number.push_front(i);
            }
        }

        for(auto x : number)
        {
            cout<<x<<" ";
        }
        cout<<endl;

     }
     


    return 0;
}