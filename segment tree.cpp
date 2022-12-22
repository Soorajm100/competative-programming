#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";
struct segmenttree {
	ll n;
	vector<ll> st;

	void init(ll _n) {
		this->n = _n;
		st.resize(4 * n, 0);
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

	void update(ll start, ll ending, ll node, ll index, ll value) {
		// base case
		if (start == ending) {
			st[node] = value;
			return;
		}

		ll mid = (start + ending) / 2;
		if (index <= mid) {
			// left subtree
			update(start, mid, 2 * node + 1, index, value);
		}
		else {
			// right
			update(mid + 1, ending, 2 * node + 2, index, value);
		}

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];

		return;
	}

	void build(vector<ll> &v) {
		build(0, n - 1, 0, v);
	}

	int query(ll l, ll r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(ll x, ll y) {
		update(0, n - 1, 0, x, y);
	}
};


int main()
{
    vector<ll>v = {1,2,3,4,5,6,7,8};
    segmenttree tree;
    tree.init(v.size());
    tree.build(v);
    tree.query(0,4);
    cout<<tree.st[0];
    




    return 0;
}
