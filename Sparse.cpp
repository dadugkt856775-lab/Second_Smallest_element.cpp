#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    int LOG = log2(n) + 1;

    vector<vector<int>> st(LOG, vector<int>(n));

    st[0] = a;

    for (int j = 1; j < LOG; j++) {
        for (int i = 0;
             i + (1 << j) <= n;
             i++) {

            st[j][i] = min(
                st[j - 1][i],
                st[j - 1][i + (1 << (j - 1))]
            );
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int left, right;
        cin >> left >> right;

        int length = right - left + 1;
        int k = log2(length);

        int answer = min(
            st[k][left],
            st[k][right - (1 << k) + 1]
        );

        cout << "Minimum: " << answer << endl;
    }

    return 0;
}
