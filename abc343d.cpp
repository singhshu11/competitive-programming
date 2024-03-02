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
	long long n, k;
	cin >> n >> k;
	map<long long, long long> score;
	set<long long> already;
	map<long long, long long> count;
	long long cur = 1;
	for (long long i = 1; i <= n; i++) {
		score[i] = 0;
		already.insert(0);
		count[0] = n;
	}
	for (long long i = 0; i < k; i++) {
		long long id, val;
		cin >> id >> val;
		long long old_val = score[id];
		long long new_val = score[id] + val;
		score[id] = new_val;
		count[new_val]++;
		if (already.find(new_val) != already.end()) {
			if (count[old_val] == 1) {
				cur--;
				already.erase(already.find(old_val));
			}
		} else {
			cur++;
			already.insert(new_val);
			if (count[old_val] == 1) {
				cur--;
				already.erase(already.find(old_val));
			}
		}
		count[old_val]--;
		cout << cur << endl;
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