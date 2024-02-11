#include <vector>
#include <map>

using namespace std;

map<int, bool> m;
vector<int> v;

int min(int a, int b) {
    return a < b ? a : b;
}

int solution(vector<int> nums)
{
    for (int num: nums) {
        if (!m[num]) {
            m[num] = true;
            v.push_back(num);
        }
    }
    
    int answer = min(nums.size() / 2, v.size());
    return answer;
}