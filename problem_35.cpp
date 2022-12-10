#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

ll n, m;
vector<pair<ll, ll>> monster;
vector<vector<ll>> grid;
map<pair<ll, ll>, pair<ll, ll>> par_mp;
pair<ll, ll> si, se;
vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isvalid(ll x, ll y, ll timer)
{
    if (x < 0 or y < 0 or x >= n or y >= m)
    {
        return false;
    }

    if (grid[x][y] <= timer)
    {
        return false;
    }

    return true;
}

bool isescape(ll x, ll y, ll timer)
{
    if (!isvalid(x, y, timer))
        return false;
    if (x == 0 or y == 0 or x == n - 1 or y == m - 1)
        return true;

    return false;
}

bool bfs_escape()
{

    queue<pair<pair<ll, ll>, ll>> q;
    q.push({si, 0});
    par_mp[si] = {-1, -1};
    while (!q.empty())
    {
        ll cx = q.front().first.first;
        ll cy = q.front().first.second;

        ll timer = q.front().second;
        timer++;
        q.pop();
        for (auto x : dirs)
        {
            ll tx = cx + x.first;
            ll ty = cy + x.second;
            if (isescape(tx, ty, timer))
            {
                par_mp[{tx, ty}] = {cx, cy};
                se = {tx, ty};
                return true;
            }
            if (isvalid(tx, ty, timer))
            {
                par_mp[{tx, ty}] = {cx, cy};
                grid[tx][ty] = timer;
                q.push({{tx, ty}, timer});
            }
        }
    }

    return false;
}

void preprocess_lava_flow()
{
    queue<pair<pair<ll, ll>, ll>> q;
    for (auto m : monster)
    {
        q.push({m, 0});
    }

    while (!q.empty())
    {
        ll cx = q.front().first.first;
        ll cy = q.front().first.second;
        ll timer = q.front().second;
        timer++;
        q.pop();

        for (auto x : dirs)
        {
            ll tx = cx + x.first;
            ll ty = cy + x.second;
            if (isvalid(tx, ty, timer))
            {
                grid[tx][ty] = timer;
                q.push({{tx, ty}, timer});
            }
        }
    }
}

int main()
{

    cin >> n >> m;
    grid.resize(n);
    for (ll i = 0; i < n; i++)
    {
        grid[i].resize(m);
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            grid[i][j] = INT_MAX;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                grid[i][j] = 0;
            }
            else if (c == 'M')
            {
                grid[i][j] = 0;
                monster.push_back({i,j});
            }
            else if(c=='A')
            {
                grid[i][j] = 0;
                si = {i,j};
            }
            else{
                grid[i][j] = INT_MAX;
            }
        }
    }

    if (si.first == 0 or si.second == 0 or si.first == n - 1 or si.second == m - 1)
    {
        cout << "YES" << endl;
        cout << 0;
        return 0;
    }

    preprocess_lava_flow();

    if (!bfs_escape())
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    pair<ll, ll> tmp = se;
    pair<ll, ll> tmp1 = par_mp[se];
    pair<ll, ll> ed = {-1, -1};
    vector<char> ans;
    while (tmp1 != ed)
    {
        if ((tmp.second - tmp1.second) == 1 and (tmp.first - tmp1.first) == 0)
        {
            ans.push_back('R');
        }
        if ((tmp.second - tmp1.second) == -1 and (tmp.first - tmp1.first) == 0)
        {
            ans.push_back('L');
        }
        if ((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == 1)
        {
            ans.push_back('D');
        }
        if ((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == -1)
        {
            ans.push_back('U');
        }
        tmp = par_mp[tmp];
        tmp1 = par_mp[tmp];
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto c : ans)
    {
        cout << c;
    }

    return 0;
}