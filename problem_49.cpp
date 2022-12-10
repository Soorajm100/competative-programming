#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define endl "\n";

stack<ll>recurstack;
vector<vector<ll>>adj;
vector<bool>vis;
vector<bool>resflag;
ll n , m ;
ll ev =-1; 

bool dfs(ll node)
{
    vis[node] = true;
    recurstack.push(node);
    resflag[node] = true;

    for(auto x : adj[node])
    {
        if(!vis[x])
        {
            if(dfs(x))return true;
        }

        if(resflag[x])
        {
            ev = x;
            recurstack.push(x);
            return true;
        }
    }

    recurstack.pop();
    resflag[node] = false;

    return false;

}

bool solve()
{
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i))
            {
                return  true;
            }
        }
    }

return false;

}

int main()
{
   
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1 , false);
    resflag.resize(n+1);
    for(ll i=0;i<m;i++)
    {
        ll u , v ;
        cin>>u>>v;
        adj[u].push_back(v);
    }

     bool ans = solve();
    
    
     if(recurstack.empty())
     {
        cout<<"IMPOSSIBLE"<<endl;
        return 0 ;
     }
     else{

        ll temp = ev ; 
        vector<ll>res;
        while(recurstack.size()>0)
        {
            if(res.size()>0 and recurstack.top()==ev)
            {
                break;
            }
            res.push_back(recurstack.top());
            recurstack.pop();
        }
        res.push_back(ev);

        cout<<res.size()<<endl;
        reverse(res.begin() , res.end());
        for(auto x : res)
        {
            cout<<x<<" ";
        }
        cout<<endl;

     }



   return 0 ;

}