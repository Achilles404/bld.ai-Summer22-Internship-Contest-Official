#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pii pair<int , int>
#define pp push_back
#define M 1000000007
const int N = 200005;


void Achilles1() {
    string s, t;
    cin >> s >> t;
  
    int n = (int) s.size(), m = (int) t.size();
  
    for (int i = 0; i < min(n, m); ++i) {
        cout << s[i] << t[i];
    }
  
    for (int i = min(n, m); i < max(n, m); ++i) {
        if (n > m) cout << s[i];
        else cout << t[i];
    }
  
}


int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
