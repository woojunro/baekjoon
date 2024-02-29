#include <iostream>
#include <stack>

using namespace std;

int N;
int ans[10];
stack<int> s;

void doit(int num, int depth)
{
  if (depth == N)
  {
    for (int i = 0; i < N; i++)
      cout << ans[i] << " ";
    cout << "\n";
    return;
  }

  if (!s.empty())
  {
    int val = s.top();
    ans[depth] = val;
    s.pop();
    doit(num, depth + 1);
    s.push(val);
  }

  if (num <= N)
  {
    s.push(num);
    doit(num + 1, depth);
    s.pop();
  }
}

void solve()
{
  cin >> N;
  doit(1, 0);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}