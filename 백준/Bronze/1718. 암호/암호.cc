#include <iostream>
#include <string>

using namespace std;

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string key, str, ans;
    getline(cin, str);
    getline(cin, key);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            ans.push_back(' ');
            continue;
        }

        int k = key[i % key.length()] - 'a';
        int n = str[i] - 'a' - k;
        if (n <= 0) {
            n += 26;
        }

        ans.push_back('a' + n - 1);
    }

    cout << ans;

    return 0;
}