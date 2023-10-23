#include "bits/stdc++.h"

using db = long double;
using ll = long long;
using namespace std;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;

#define INF 0x3f3f3f3f
#define LNF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007

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

#define maxn 1000010

char s[maxn];
int n, x, y, a[maxn], dp[maxn][2];
set<char> ev{ 'a', 'e', 'i', 'o', 'u' };

int solve() {
    cin >> s >> x >> y;
    n = 0; while (s[n]) ++ n;
    lor(i, 1, n+1) a[i] = s[i-1] == '?' ? -1 : (ev.find(s[i-1]) == ev.ed());
    
    int mx[2] { 0, 0 };
    lor(i, 1, n+1) {
        dp[i][0] = a[i] == 1 ? 0 : (dp[i-1][0] + 1);
        dp[i][1] = a[i] == 0 ? 0 : (dp[i-1][1] + 1);
        mx[0] = max(mx[0], dp[i][0]);
        mx[1] = max(mx[1], dp[i][1]);
    }
    if (mx[0] < x && mx[1] < y) return 1;

    lor(i, 1, n+1) {
        if (a[i] == -1) {
            bool c0 = dp[i-1][0] < x - 1, c1 = dp[i-1][1] < y - 1;
            dp[i][0] = c1 ? 0 : dp[i-1][0] + 1;
            dp[i][1] = c0 ? 0 : dp[i-1][1] + 1;
        } else {
            dp[i][0] = a[i] == 1 ? 0 : (dp[i-1][0] + 1);
            dp[i][1] = a[i] == 0 ? 0 : (dp[i-1][1] + 1);
        }
        if (dp[i][0] >= x || dp[i][1] >= y) return -1;
    }

    return 0;
}

int main()
{
    #ifdef LC
        freopen("zz.in", "r+", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;  
    lor(i, 1, t+1) {
        cout << "Case #" << i << ": ";
        int res = solve();
        if (res == 1) cout << "LIKE" << '\n';
        if (res == 0) cout << "SURPRISE" << '\n';
        if (res == -1) cout << "DISLIKE" << '\n';
    }

    return 0;
}