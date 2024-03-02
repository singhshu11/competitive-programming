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
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < 10; i++) {
		if (i != (a + b)) {
			cout << i << endl;
			return;
		}
	}
}
int main() {
	file();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#if multitest
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
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