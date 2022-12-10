#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define endl "\n";
ll n , m ;
vector<vector<pair<ll, ll>>>path;
vector<vector<bool>>vis ;
ll sx ,sy ,ex , ey;

bool isvalid(ll i , ll j)
{
    if(i<0 or i>=n or j<0 or j>=m)return false;
    if(vis[i][j]==true)return false;
    return true;

}
vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
void bfs()
{
    queue<pair<ll, ll>>q;
    q.push({sx ,sy});
    while(!q.empty())
    {
        ll cx = q.front().first;
        ll cy = q.front().second;
        q.pop();
        for(auto x : dirs)
        {
            ll mvx = x.first;
            ll mvy = x.second;
            if(isvalid(cx + mvx , cy+mvy))
            {
                q.push({cx+ mvx , cy+mvy});
                vis[cx+ mvx][cy+mvy] = true;
                path[cx+ mvx][cy+mvy] = {mvx , mvy};
            }
        }
    }
}

int main()
{

    cin>>n>>m;
    path.resize(n);
    vis.resize(n);
    for(ll i=0;i<n;i++)
    {
        path[i].resize(m);
        vis[i].resize(m);
    }

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            path[i][j] = {-1,-1};
            char c;
            cin>>c;
            if(c=='#')
            {
                vis[i][j] = true;
            }
            if(c=='A')
            {
                sx = i;
                sy = j;
            }
            if(c=='B')
            {
                ex = i;
                ey = j;
            }
        }
    }

    bfs();

    if(!vis[ex][ey])
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    vector<pair<ll,ll>>ans;
    pair<ll,ll> end = {ex, ey};

    while(end.first!=sx or end.second!=sy)
    {
        ans.push_back(path[end.first][end.second]);
        cout<<path[end.first][end.second].first<<" "<<path[end.first][end.second].second<<endl;
       // cout<<end.first<<" "<<end.second<<endl;
        end.first -=ans.back().first;
        end.second-=ans.back().second;
    }

    reverse(ans.begin() , ans.end());
    cout<<ans.size()<<endl;
    for(auto c :ans)
    {
        if(c.first==1 and c.second==0)
        {
            cout<<'D';
        
        }
        else if(c.first == -1 and c.second ==0)
		{
			cout << 'U';
		}
		else if(c.first == 0 and c.second == 1)
		{
			cout << 'R';
		}
		else if(c.first == 0 and c.second == -1)
		{
			cout << 'L';
		}
    }



}