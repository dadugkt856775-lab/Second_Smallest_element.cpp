#include <bits/stdc++.h>
using namespace std;

int expand(string& s, int left, int right) {
    while (left >= 0 &&
           right < s.size() &&
           s[left] == s[right]) {
        left--;
        right++;
    }

    return right - left - 1;
}

int main() {
    string s;
    cin >> s;

    int start = 0;
    int maxLength = 1;

    for (int i = 0; i < s.size(); i++) {
        int odd = expand(s, i, i);
        int even = expand(s, i, i + 1);

        int length = max(odd, even);

        if (length > maxLength) {
            maxLength = length;

            start = i - (length - 1) / 2;
        }
    }

    cout << "Longest Palindromic Substring: "
         << s.substr(start, maxLength) << endl;

    return 0;
}
