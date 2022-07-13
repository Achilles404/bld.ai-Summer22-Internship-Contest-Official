#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pii pair<int , int>
#define pp push_back
#define M 1000000007
const int N = 200005;

int a[N], n, k;

ll f() {
    unordered_map<ll, ll> um;

    ll max_len = 0, curr_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += a[i];

        ll mod = ((curr_sum % k) + k) % k;

        if (mod == 0)
            max_len = i + 1;
        else if (um.find(mod) == um.end())
            um[mod] = i;

        else if (max_len < (i - um[mod]))
            max_len = i - um[mod];
    }
    return max_len;
}

void Achilles1() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << f();
}


int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
