#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b) {
    string a_str = to_string(a);
    string b_str = to_string(b);
    
    return stoi(a_str + b_str) > stoi(b_str + a_str);
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), cmp);
    
    string answer = "";
    
    for (int i: numbers) {
        answer += to_string(i);
    }
    
    if (answer[0] == '0') answer = "0";
    
    return answer;
}