#include "bits/stdc++.h"

using db = long double;
using ll = long long;
using namespace std;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;

#define INF 0x3f3f3f3f
#define LNF 0x3f3f3f3f3f3f3f3fll
#define MOD 998244353

#define eb emplace_back
#define pb pop_back
#define is insert
#define fn front
#define bk back
#define bg begin
#define ed end
#define pq priority_queue
#define bcnt __builtin_popcount

#define l0r(a, b) for (int a = 0; a < (b); ++ a)
#define lor(a, b, c) for (int a = (b); a < (c); ++ a)
#define r0r(a, b) for (int a = (b) - 1; a >= 0; -- a)
#define ror(a, b, c) for (int a = (c) - 1; a >= b; -- a)

#define maxm 2020

bool v[maxm];

void solve() {
    int n, m; cin >> n >> m;

    ll res = 1, mx = 0;
    lor(k, 2, m+1) {
        ll i = 0, j = (k - 1) % n;
        memset(v, 0, sizeof v);

        ll cur = 0;
        while (i < n) {
            if (i >= j) {
                ll stp = (i - j) / (k - 1) + 1;
                i = i + stp, j = (j + k * stp) % n;
            }

            if (v[j % k]) break;

            if (j > i) {
                v[j % k] = 1;
                ll cnt = (n - j - 1) / k;
                cur += ((j+1) + ((j+1) + k*cnt)) * (cnt + 1) / 2;
                i = i + cnt + 1, j = (j + k * (cnt + 1)) % n;
            }
        }

        if (cur > mx) {
            res = k;
            mx = cur;
        }
    }

    cout << res << '\n';
}

int main()
{
    #ifdef LC
        freopen("zz.in", "r+", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; t = 1;
    while (t --) solve();

    return 0;
}