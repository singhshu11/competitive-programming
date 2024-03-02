#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugger.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define multitest 0
void file();
void solve() {
	long long n;
	cin >> n;
	long long k = cbrt(n) + 10;
	auto is = [&](long long id) {
		string s = to_string(id);
		long long l = 0, r = s.size() - 1;
		while (r >= l) {
			if (s[r] != s[l]) return false;
			r--;
			l++;
		}
		return true;
	};
	for (long long i = k; ; i--) {
		long long val = i * i * i;
		if (is(val) && val <= n) {
			cout << val << endl;
			return;
		}
	}
}
int main() {
	file();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#if multitest
	long long test_case;
	cin >> test_case;
	for (long long i = 0; i < test_case; i++) {
		solve();
	}
#else
	solve();
#endif
}

void file() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}