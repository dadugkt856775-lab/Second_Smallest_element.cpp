#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float>& a) {
    int n = a.size();

    vector<vector<float>> buckets(n);

    for (float x : a) {
        int index = min((int)(x * n), n - 1);
        buckets[index].push_back(x);
    }

    for (auto& bucket : buckets)
        sort(bucket.begin(), bucket.end());

    int index = 0;

    for (auto& bucket : buckets) {
        for (float x : bucket)
            a[index++] = x;
    }
}

int main() {
    int n;
    cin >> n;

    vector<float> a(n);

    for (float& x : a)
        cin >> x;

    bucketSort(a);

    cout << fixed << setprecision(2);
    cout << "Sorted Array: ";

    for (float x : a)
        cout << x << " ";

    cout << endl;

    return 0;
}
