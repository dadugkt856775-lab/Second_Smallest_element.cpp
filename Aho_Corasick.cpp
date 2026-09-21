#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[26];
    int link;
    vector<int> output;

    Node() {
        fill(next, next + 26, -1);
        link = 0;
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> patterns(n);
    vector<Node> trie(1);

    for (int i = 0; i < n; i++) {
        cin >> patterns[i];

        int node = 0;

        for (char c : patterns[i]) {
            int x = c - 'a';

            if (trie[node].next[x] == -1) {
                trie[node].next[x] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].next[x];
        }

        trie[node].output.push_back(i);
    }

    queue<int> q;

    for (int c = 0; c < 26; c++) {
        int child = trie[0].next[c];

        if (child != -1) {
            q.push(child);
            trie[child].link = 0;
        }
        else {
            trie[0].next[c] = 0;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int link = trie[u].link;

        for (int id : trie[link].output)
            trie[u].output.push_back(id);

        for (int c = 0; c < 26; c++) {
            int v = trie[u].next[c];

            if (v != -1) {
                trie[v].link = trie[link].next[c];
                q.push(v);
            }
            else {
                trie[u].next[c] = trie[link].next[c];
            }
        }
    }

    string text;
    cin >> text;

    int node = 0;

    cout << "Matches:\n";

    for (int i = 0; i < text.size(); i++) {
        node = trie[node].next[text[i] - 'a'];

        for (int id : trie[node].output) {
            int start = i - patterns[id].size() + 1;

            cout << patterns[id]
                 << " found at index "
                 << start << endl;
        }
    }

    return 0;
}
