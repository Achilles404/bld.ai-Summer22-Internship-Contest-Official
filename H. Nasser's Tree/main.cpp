#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pii pair<int , int>
#define pp push_back
#define M 1000000007
const int N = 200005;

ll a, b, h;
ll pw[62];

pair<ll, ll> f(ll x) {
    ll level = 1, ind = 1;

    for (ll i = 1; i <= 60; ++i) {
        ll val = x, power = pw[h - i];
        if (x % power) continue;
        val /= power;
        if ((val + 1) % 2) continue;
        ll cur = (val + 1) / 2;
        level = i;
        ind = cur;
        break;
    }

    return {level, ind};
}

ll calc(ll l, ll i) {
    return pw[h - l] * (2 * i - 1);
}

void Achilles1() {
    cin >> h >> a >> b;
    pair<ll, ll> p1 = f(a);
    pair<ll, ll> p2 = f(b);
    while (calc(p1.first, p1.second) != calc(p2.first, p2.second)) {
        if (p1.first > p2.first) {
            p1.first--;
            p1.second = (p1.second + 1) / 2;
        } else if (p1.first < p2.first) {
            p2.first--;
            p2.second = (p2.second + 1) / 2;
        } else {
            p1.first--;
            p1.second = (p1.second + 1) / 2;
            p2.first--;
            p2.second = (p2.second + 1) / 2;
        }
    }
    cout << calc(p1.first, p1.second) << '\n';
}


int main() {
    Achilles
    pw[0] = 1;
    for (int i = 1; i <= 61; ++i) {
        pw[i] = pw[i - 1] * 2;
    }
    int tt = 1;
    cin >> tt;
    while (tt--) Achilles1();
}
