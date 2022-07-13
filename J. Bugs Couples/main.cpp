#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pii pair<int , int>
#define pp push_back
#define M 1000000007
const int N = 200005;

int a[21][21];
ll dp[21][(1 << 20) + 1];
int n;

ll f(int i, int mask) {
    if (i == n) return 1;

    ll &ans = dp[i][mask];
    if (~ans) return ans;
  
    ans = 0;
    for (int k = 0; k < n; ++k) {
        if ((1 << k) & mask)continue;
        if (a[i][k] == 1) {
            ans = (ans + f(i + 1, mask | (1 << k))) % M;
        }
    }

    return ans;
}

void Achilles1() {
    memset(dp, -1, sizeof dp);
    cin >> n;
  
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
  
    cout << f(0, 0);
}


int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
