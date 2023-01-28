#include<bits/stdc++.h>
using namespace std;
#define uint            unsigned int
#define int             long long
#define f(i,a,b)        for(int i=a;i<b;i++)
#define rv(i,a,b)       for(int i=a;i>=b;i--)    
#define via(n)          vector<int> a(n) 
#define all(a)          (a).begin(),(a).end()
#define clr(x)          memset(x, 0, sizeof(x))
#define printl(a)       cout<<a<<endl
#define print(a)        cout<<a<<" "
#define pnx             cout<<endl
#define ufill(a,n)      f(i,0,n)cin>>a[i]
#define pii             pair<int,int>
#define pdd             pair<double,double>
#define fr              first
#define sc              second
#define pb              push_back
#define pob             pop_back
#define pm(a,b)         make_pair(a,b)
#define ushow(v,n)      f(i,0,n)print(v[i])
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
const int M=1e9+7;
const int N=1e6+7;
int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return((a*b)/gcd(a,b));
}
bool comp(int a,int b){
    if(a<=b)return false;
    return true;
}
