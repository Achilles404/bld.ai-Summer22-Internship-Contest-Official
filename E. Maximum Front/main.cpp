#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pii pair<int , int>
#define pp push_back
#define M 1000000007
const int N = 200005;


void Achilles1() {
    int n, k, x, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (i < k - 1)
            ans = max(ans, x);
    }
    cout << ans;
}


int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
