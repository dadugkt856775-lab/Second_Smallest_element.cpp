#include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<int>& a, int left, int mid, int right) {
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while (i <= mid)
        temp.push_back(a[i++]);

    while (j <= right)
        temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
        a[left + k] = temp[k];
}

void mergeSort(vector<int>& a, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    mergeArray(a, left, mid, right);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    mergeSort(a, 0, n - 1);

    cout << "Sorted Array: ";

    for (int x : a)
        cout << x << " ";

    cout << endl;

    return 0;
}
