#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pii pair<int , int>
#define pp push_back
#define M 1000000007
const int N = 200005;

int parent[N], sz[N];

void reset(int n) {
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int f(int x) {
    if (parent[x] == x) return x;
    return parent[x] = f(parent[x]);
}

void un(int a, int b) {
    a = f(a);
    b = f(b);

    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] = sz[b];
    }
}

struct Edge {
    int u, v, c;

    bool operator<(Edge const &other) const {
        return c > other.c;
    }
};

////////////////////////////////////////////////////////
vector<vector<int>> up, mx;
vector<pii > adj[N];
vector<int> depth;
bitset<N> vis;
int LOG;

int KthAncestor(int node, int k) {
    int ans = 1e9;
    if (k > depth[node]) return 1;
    while (k)
        for (int i = LOG - 1; i >= 0; --i)
            if (k & (1 << i)) {
                ans = min(ans, mx[node][i]);
                node = up[node][i];
                k -= (1 << i);
            }
    return ans;
}

void dfs(int x) {
    vis[x] = true;
    for (auto i: adj[x])
        if (!vis[i.first]) {
            up[i.first][0] = x;
            depth[i.first] = depth[x] + 1;
            mx[i.first][0] = i.second;
            dfs(i.first);
        }
}


int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    int k = depth[a] - depth[b];

    for (int j = LOG - 1; j >= 0; --j) {
        if (k & (1 << j)) {
            a = up[a][j];
        }
    }
    if (a == b) return a;

    for (int j = LOG - 1; j >= 0; --j) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0];
}


void Achilles1() {
    //MST
    int n, m;
    cin >> n >> m;
    reset(n);
    vector<Edge> mst;
    vector<Edge> edges(m);
    int u, v, c;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        edges[i].u = u;
        edges[i].v = v;
        edges[i].c = c;
    }

    sort(edges.begin(), edges.end());

    for (Edge e: edges) {
        if (f(e.u) != f(e.v)) {
            mst.pp(e);
            un(e.u, e.v);
        }
    }

    //LCA
    LOG = __lg(n) + 2;
    up.resize(n + 1);
    mx.resize(n + 1);
    for (auto &i: up) i.resize(LOG);
    for (auto &i: mx) i.resize(LOG, 1e9);
    depth.resize(n + 1);

    for (auto &i: mst) {
        adj[i.u].pp({i.v, i.c});
        adj[i.v].pp({i.u, i.c});
    }

    // root
    dfs(1);

    // up[v][j] is 2^j -th ancestor of node v
    for (int j = 1; j < LOG; ++j)
        for (int i = 0; i <= n; ++i) {
            up[i][j] = up[up[i][j - 1]][j - 1];
            if ((1 << j) <= depth[i])
                mx[i][j] = min(mx[up[i][j - 1]][j - 1], mx[i][j - 1]);
        }

    int q;
    cin >> q;
    while (q--) {
        cin >> u >> v;
        int lca = LCA(u, v);
        int dis1 = abs(depth[u] - depth[lca]);
        int dis2 = abs(depth[v] - depth[lca]);
        cout << min(KthAncestor(u, dis1), KthAncestor(v, dis2)) << '\n';
    }
}


int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
