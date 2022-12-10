#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n";

int main()
{

    ll n , m;
    cin>>n>>m;
    vector<vector<ll> >adj(n+1);
    for(ll i=0;i<m;i++)
    {
        ll u ,v; 
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>vis(n+1 , false);
    queue<ll>q;
    q.push(1);
    vis[1] = true;
    vector<ll>par(n+1);
    for(int i = 0; i<=n; ++i)
	{
		par[i] = -1;
	}


    while(!q.empty())
    {
        ll node = q.front();
        q.pop();

        for(auto x :adj[node])
        {
            if(!vis[x])
            {
                vis[x]  = true;
                par[x] = node;
                q.push(x);
            }
        }
    }

     
	if(par[n] == -1)
	{
		cout <<  "IMPOSSIBLE";
		return 0;
	}

    ll curr_node = n;
    par[1] = -1;
    stack<ll>stk;
    vector<ll>res;
    while(curr_node!=-1)
    {
        stk.push(curr_node);
        res.push_back(curr_node);
        curr_node = par[curr_node];
       // cout<<curr_node<<" ";
    }

    reverse(res.begin() , res.end());
    cout<<stk.size()<<endl;
   
   for(ll i =0;i<res.size();i++)
   {
    cout<<res[i]<<" ";
   }
   cout<<endl;
    return 0;
}
