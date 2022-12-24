#include<bits/stdc++.h>

using namespace std;
typedef long long ll ;

// summation
ll n ,q;
struct segmenttree {
	ll n;
	vector<ll> st, lazy;

	void init(ll _n) {
		this->n = _n;
		st.resize(4 * n, 0);
		lazy.resize(4 * n, 0);
	}

	void build(ll start, ll ending, ll node, vector<ll> &v) {
		// leaf node base case
		if (start == ending) {
			st[node] = v[start];
			return;
		}

		ll mid = (start + ending) / 2;

		// left subtree is (start,mid)
		build(start, mid, 2 * node + 1, v);

		// right subtree is (mid+1,ending)
		build(mid + 1, ending, 2 * node + 2, v);

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}

	ll query(ll start, ll ending, ll l, ll r, ll node) {
		// non overlapping case
		if (start > r || ending < l) {
			return 0;
		}

		// lazy propagation / clear the lazy update
		if (lazy[node] != 0) {
			// pending updates
			// update the segment tree node
			st[node] += lazy[node] * (ending - start + 1);
			if (start != ending) {
				// propagate the updated value
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
			lazy[node] = 0;
		}

		// complete overlap
		if (start >= l && ending <= r) {
			return st[node];
		}

		// partial case
		ll mid = (start + ending) / 2;

		ll q1 = query(start, mid, l, r, 2 * node + 1);
		ll q2 = query(mid + 1, ending, l, r, 2 * node + 2);

		return q1 + q2;
	}

	void update(ll start, ll ending, ll node, ll l, ll r, ll value) {
		// non overlapping case
		if (start > r || ending < l) {
			return ;
		}

		// lazy propagation / clear the lazy update
		if (lazy[node] != 0) {
			// pending updates
			// update the segment tree node
			st[node] += lazy[node] * (ending - start + 1);
			if (start != ending) {
				// propagate the updated value
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
			lazy[node] = 0;
		}

		// complete overlap
		if (start >= l && ending <= r) {
			st[node] += value * (ending - start + 1);
			if (start != ending) {
				lazy[2 * node + 1] += value;
				lazy[2 * node + 2] += value;
			}
			return;
		}

		// partial case
		ll mid = (start + ending) / 2;

		update(start, mid, 2 * node + 1, l, r, value);

		update(mid + 1, ending, 2 * node + 2, l, r, value);

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];

		return;
	}

	void build(vector<ll> &v) {
		build(0, n - 1, 0, v);
	}

	ll query(ll l, ll r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(ll l, ll r, ll x) {
		update(0, n - 1, 0, l, r, x);
	}
};

int main()
{

	vector<ll> v = {1, 2, 3, 4, 5, 6, 7, 8};
	// cout << v.size();

	segmenttree tree;

	

    cin>>n>>q;
    vector<ll>ans(n);
    for(ll i=0;i<n;i++)cin>>ans[i];

    tree.init(ans.size());
    tree.build(ans);

    while(q--)
    {
        ll k ; 
        cin>>k;
        if(k==1)
        {
            ll a , b,u;
            cin>>a>>b>>u;
            a--;
            b--;
            tree.update(a ,b, u);
        }
        else{
            ll b ;
            cin>>b;

            cout<<tree.query(b-1 , b-1)<<endl;
        }

    }

	return 0;
}
