#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (left.empty() || x <= left.top())
            left.push(x);
        else
            right.push(x);

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }

        if (left.size() == right.size()) {
            double median = (left.top() + right.top()) / 2.0;
            cout << fixed << setprecision(1) << median << " ";
        }
        else {
            cout << left.top() << " ";
        }
    }

    cout << endl;

    return 0;
}
