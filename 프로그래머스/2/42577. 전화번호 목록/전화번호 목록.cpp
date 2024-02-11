#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a.length() > b.length();
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), cmp);
    
    unordered_map<string, bool> m;
    
    for (string phone: phone_book) {
        if (m[phone]) {
            return false;
        }
        for (int i = 0; i < phone.length(); i++) {
            string s;
            for (int j = 0; j <= i; j++) {
                s.push_back(phone[j]);
            }
            m[s] = true;
        }
    }
    
    return true;
}