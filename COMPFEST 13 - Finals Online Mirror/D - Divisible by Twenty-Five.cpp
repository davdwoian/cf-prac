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
#define fi first
#define se second
#define pq priority_queue
#define bcnt __builtin_popcount

#define l0r(a, b) for (int a = 0; a < (b); ++ a)
#define lor(a, b, c) for (int a = (b); a < (c); ++ a)
#define r0r(a, b) for (int a = (b) - 1; a >= 0; -- a)
#define ror(a, b, c) for (int a = (c) - 1; a >= b; -- a)

int a[10];

int pow(int b, int p) {
    return p == 0 ? 1 : (b * pow(b, p - 1));
}

void solve() {
    string s; cin >> s;

    int n = s.length();

    if (n > 1 && s[0] == '0') {
        cout << 0 << '\n'; return;
    }

    if (n == 1) {
        cout << (s[0] == '0' || s[0] == '_' || s[0] == 'X') << '\n'; return;
    }

    int cnt = 0, hx = 0;
    l0r(i, n - 2) cnt += s[i] == '_';
    l0r(i, n) hx += s[i] == 'X';

    int res = 0;
    l0r(d, hx ? 10 : 1) {
        l0r(i, n) {
            switch (s[i]) {
                case 'X': a[i] = d; break;
                case '_': a[i] = 100; break;
                default: a[i] = s[i] - '0'; break;
            }
        }

        if (a[0] == 0) continue;

        for (int x : { 0, 25, 50, 75 }) {
            if (a[n - 2] >= 100) a[n - 2] = 100 + x / 10;
            if (a[n - 1] >= 100) a[n - 1] = 100 + x % 10;

            if (n == 2 && x == 0) continue;

            int val = (a[n - 2] % 100 * 10 + a[n - 1] % 100);
            if (val == x) {
                if (cnt == 0) res ++;
                else res += s[0] == '_' ? 9 * pow(10, cnt - 1) : pow(10, cnt);
            }
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