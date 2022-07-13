#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pii pair<int , int>
#define pp push_back
#define M 1000000007
const int N = 200005;


void Achilles1() {
    map<int, int> f;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        f[a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << f.begin()->second << ' ';
        f[a[i]]--;
        if (f[a[i]] == 0) {
            f.erase(a[i]);
        }
    }
}


int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
