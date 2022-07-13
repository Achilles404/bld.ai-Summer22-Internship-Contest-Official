#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pii pair<int , int>
#define pp push_back
#define M 1000000007
const int N = 200005;

int n, m;
int parent[N], siz[N];

void make_set() {
    for (int i = 1; i <= n; i++)
        parent[i] = i, siz[i] = 1;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b]) swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

struct edge {
    int u, v, c;
};

bool cmp(edge a, edge b) {
    return a.c > b.c;
}

const int LOG = 24;

class LCA {
private:
    vector<vector<int>> up, mn;
    vector<vector<pair<int, int>>> adj;
    vector<int> nodes, vis, depth;
    int n;
public:
    LCA(int _n) {
        n = _n;
        depth.resize(n + 1);
        vis.resize(n + 1);
        adj.resize(n + 1);
        up.resize(n + 1);
        mn.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            up[i].resize(LOG + 1);
            mn[i].resize(LOG + 1);
        }
    }

    void dfs(int u) {
        vis[u] = true;
        for (auto child: adj[u]) {
            if (vis[child.first])continue;
            depth[child.first] = depth[u] + 1;
            up[child.first][0] = u;
            mn[child.first][0] = child.second;
            dfs(child.first);
        }
    }

    pair<int, int> get_lca(int a, int b) {
        if (depth[a] < depth[b])swap(a, b);
        int k = depth[a] - depth[b];
        int ans = 1e9;
        for (int i = LOG - 1; i >= 0; --i) {
            if (k & (1 << i)) {
                ans = min(ans, mn[a][i]);
                a = up[a][i];
            }
        }
        if (a == b) {
            return {a, ans};
        }
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[a][i] != up[b][i]) {
                ans = min({ans, mn[a][i], mn[b][i]});
                a = up[a][i];
                b = up[b][i];
            }
        }
        return {up[a][0], min(ans, mn[a][0])};
    }

    int query(int a, int b) {
        if (depth[a] < depth[b])swap(a, b);
        int k = depth[a] - depth[b];
        int ans = 1e9;
        for (int i = LOG - 1; i >= 0; --i) {
            if (k & (1 << i)) {
                ans = min(ans, mn[a][i]);
                a = up[a][i];
            }
        }
        return ans;
    }

    void preprocess(int root) {
        dfs(root);
        for (int j = 1; j < LOG; ++j) {
            for (int v = 1; v <= n; ++v) {
                up[v][j] = up[up[v][j - 1]][j - 1];
                mn[v][j] = min(mn[v][j - 1], mn[up[v][j - 1]][j - 1]);
            }
        }
    }

    void set(int u, int v, int c) {
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

};

void Achilles1() {
    //MST
    cin >> n >> m;
    vector<edge> edges;
    make_set();
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }
    sort(edges.begin(), edges.end(), cmp);
    vector<edge> take;
    for (int i = 0; i < m; ++i) {
        if (find_set(edges[i].u) != find_set(edges[i].v)) {
            union_sets(edges[i].u, edges[i].v);
            take.push_back(edges[i]);
        }
    }
    //LCA
    LCA lca(n);
    for (auto &i: take) {
        lca.set(i.u, i.v, i.c);
    }
    lca.preprocess(1);
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        pair<int, int> l1 = lca.get_lca(1, a);
        pair<int, int> l2 = lca.get_lca(1, b);
        pair<int, int> l3 = lca.get_lca(a, b);

        if (l1.first == l2.first && l2.first == l3.first) {
            cout << min({l1.second, l2.second, l3.second}) << '\n';
        } else {
            ll x, y;
            if (l1.first == l2.first) {
                x = lca.query(a, l3.first);
                y = lca.query(b, l3.first);
                cout << min(x, y) << '\n';
            } else if (l1.first == l3.first) {
                x = lca.query(a, l2.first);
                y = lca.query(b, l2.first);
                cout << min(x, y) << '\n';
            } else {
                x = lca.query(a, l1.first);
                y = lca.query(b, l1.first);
                cout << min(x, y) << '\n';
            }
        }
    }
}


int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
