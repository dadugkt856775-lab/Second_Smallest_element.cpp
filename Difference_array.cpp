#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> diff(n + 1, 0);

    while (q--) {
        int l, r, value;
        cin >> l >> r >> value;

        diff[l] += value;

        if (r + 1 < n)
            diff[r + 1] -= value;
    }

    vector<int> result(n);
    result[0] = diff[0];

    for (int i = 1; i < n; i++)
        result[i] = result[i - 1] + diff[i];

    cout << "Final Array: ";

    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}
