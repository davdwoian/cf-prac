#include "bits/stdc++.h"

using db = long double;
using ll = long long;
using namespace std;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;

#define INF 0x3f3f3f3f
#define LNF 0x3f3f3f3f3f3f3f3fll
#define MOD (int) (1e9+7)

#define eb emplace_back
#define pb pop_back
#define is insert
#define fn front
#define bk back
#define bg begin
#define ed end
#define fi first
#define se second
#define pq priority_queue
#define bcnt __builtin_popcount

#define l0r(a, b) for (int a = 0; a < (b); ++ a)
#define lor(a, b, c) for (int a = (b); a < (c); ++ a)
#define r0r(a, b) for (int a = (b) - 1; a >= 0; -- a)
#define ror(a, b, c) for (int a = (c) - 1; a >= b; -- a)

#define maxn 100010

int np[maxn], pr[maxn], phi[maxn], pi;

void sieve() {
    phi[0] = 0, phi[1] = 1;

    lor (i, 2, maxn) {
        if (!np[i]) pr[pi ++] = i, phi[i] = i - 1;
        l0r(j, pi) {
            if (1ll * i * pr[j] >= maxn) break;

            np[i * pr[j]] = 1;
            if (i % pr[j] == 0) {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            } else {
                phi[i * pr[j]] = phi[i] * phi[pr[j]];
            }
        }
    }
}

vector<int> fac[maxn];

void pre() {
    lor(i, 1, maxn) {
        for (int j = i; j < maxn; j += i) {
            fac[j].eb(i);
        }
    }
}

int a[maxn];
int cnt[maxn];

int f(vector<int> v) {
    for (auto& x : v) {
        for (auto& y : fac[x]) {
            cnt[y] = 0;
        }
    }

    ll res = 0;
    for (auto& x : v) {
        for (auto& y : fac[x]) {
            // (k+1)^2 - k^2 = 2k + 1
            res = (res + 1ll * phi[y] * (2ll * cnt[y] + 1) % MOD) % MOD;
            cnt[y] ++;
        }
    }

    return res;
}

void solve() {
    sieve();
    pre();

    int n; cin >> n;
    lor(i, 1, n+1) cin >> a[i];

    ll res = 0;

    lor(i, 1, n+1) {
        vector<int> v;
        for (int j = 1; j <= n / i; ++ j) v.eb(a[i * j]);
        res = (res + 1ll * phi[i] * f(v) % MOD) % MOD;
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