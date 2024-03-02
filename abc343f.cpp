#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugger.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define multitest 1
typedef long long ll;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const ll siz = 2e5 + 7;
struct node {
	ll val1, cnt1, val2, cnt2;
};
vector<node>t(4 * siz);
node merge(node a, node b) {
	map<long long, long long>m;
	m[a.val1] += a.cnt1;
	m[a.val2] += a.cnt2;
	m[b.val1] += b.cnt1;
	m[b.val2] += b.cnt2;
	vector<pair<long long, long long>> x;
	for (auto k : m) {
		x.push_back({k.first, k.second});
	}
	node r;
	sort(x.rbegin(), x.rend());
	if (x.size() == 1) {
		r.val1 = x[0].first;
		r.cnt1 = x[0].second;
		r.val2 = 0;
		r.cnt2 = 0;
	} else {
		r.val1 = x[0].first;
		r.cnt1 = x[0].second;
		r.val2 = x[1].first;
		r.cnt2 = x[1].second;
	}
	return r;
}
node init(ll val) {
	node a;
	a.val1 = val;
	a.cnt1 = 1;
	a.val2 = 0;
	a.cnt2 = 0;
	return a;
}
ll n, q;
void built(ll a[], ll tl , ll tr, ll v) {
	if (tl == tr) {
		t[v] = init(a[tl]);
	}
	else {
		ll tm = (tl + tr) / 2;
		built(a, tl, tm, 2 * v);
		built(a, tm + 1, tr, 2 * v + 1);
		t[v] = merge(t[2 * v] , t[2 * v + 1]);
	}
}

void update(ll v, ll tl, ll tr, ll pos, ll val) {
	if (tl == tr) {
		t[v] = init(val);
	}
	else {
		ll tm = (tl + tr) / 2;
		if (pos <= tm)
			update(2 * v, tl, tm, pos, val);
		else
			update(2 * v + 1, tm + 1, tr, pos, val);
		t[v] = merge(t[2 * v] , t[2 * v + 1]);
	}
}

node query(ll v, ll tl, ll tr , ll l , ll r) {
	if (l > r)return init(0);
	if (l == tl && r == tr) {
		return t[v];
	}
	ll tm = (tr + tl) / 2;
	return merge(query(2 * v, tl, tm, l, min(r, tm)) , query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	built(a, 0, n - 1, 1);
	while (q--) {
		ll t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			l--;
			update(1, 0, n - 1, l, r);
		} else {
			l--; r--;
			node have = query(1, 0, n - 1, l, r);
			if (have.val2 == 0) cout << "0" << endl;
			else cout << have.cnt2 << endl;
		}
	}
}
