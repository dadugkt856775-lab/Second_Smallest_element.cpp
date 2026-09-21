#include <bits/stdc++.h>
using namespace std;

int partitionArray(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low >= high)
        return;

    int pivot = partitionArray(a, low, high);

    quickSort(a, low, pivot - 1);
    quickSort(a, pivot + 1, high);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    quickSort(a, 0, n - 1);

    cout << "Sorted Array: ";

    for (int x : a)
        cout << x << " ";

    cout << endl;

    return 0;
}
