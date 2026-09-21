#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& a, int place) {
    vector<int> output(a.size());
    int count[10] = {};

    for (int x : a)
        count[(x / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = a.size() - 1; i >= 0; i--) {
        int digit = (a[i] / place) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    a = output;
}

void radixSort(vector<int>& a) {
    int maximum = *max_element(a.begin(), a.end());

    for (int place = 1; maximum / place > 0; place *= 10)
        countingSort(a, place);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    radixSort(a);

    cout << "Sorted Array: ";

    for (int x : a)
        cout << x << " ";

    cout << endl;

    return 0;
}
