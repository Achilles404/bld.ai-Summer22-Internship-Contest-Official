#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pp push_back

class Trie {
private:
    struct Node {
        int k = 0;
        bool isLeaf = true;
        vector<Node *> child = {};

        Node(int _sz) : child(vector<Node *>(_sz, NULL)) {}
    };

    int sz;
    char st;
    Node *root;

public:
    Trie(int _sz, char _st) {
        sz = _sz;
        st = _st;
        root = new Node(sz);
    }

    void add(string &s) {
        Node *node = root;
        for (auto &ch: s) {
            if (node->child[ch - st] == NULL) {
                node->isLeaf = false;
                node->child[ch - st] = new Node(sz);
            }
            node = node->child[ch - st];
            node->k++;
        }
    }

    void f(string &s) {
        Node *node = root;
        for (auto &c: s) {
            if (node->child[c - st] != NULL)
                node = node->child[c - st];
            else {
                cout << 0 << '\n';
                return;
            }
        }
        cout << node->k << '\n';
    }

};

void Achilles1() {
    Trie trie = Trie(26, 'a');
    int n, q;
    string s;
    cin >> n >> q;
    while (n--) {
        cin >> s;
        trie.add(s);
    }
    while (q--) {
        cin >> s;
        trie.f(s);
    }

}



int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();

}
