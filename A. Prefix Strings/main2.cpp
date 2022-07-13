#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pii pair<int , int>
#define pp push_back
#define M 1000000007
const int N = 200005;


void Achilles1() {
    int n, q;
    string s, t;
    map<string, int> f;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int m = (int) s.size();
        for (int j = 0; j < min(10, m); ++j) {
            t += s[j];
            f[t]++;
        }
        t = "";
    }
    while (q--) {
        cin >> s;
        cout << f[s] << '\n';
    }
}


int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
