#include <iostream>
#include <vector>

using namespace std;

int nodes[100000];
vector<int> children[100000];

long long doit(int node)
{
  long long ret = nodes[node];

  for (int child : children[node])
  {
    long long tmp = doit(child);
    if (tmp > 0)
      ret += tmp;
  }

  return ret;
}

void solve()
{
  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++)
  {
    int p, c;
    cin >> p >> c;
    children[p].push_back(c);
  }

  for (int i = 0; i < n; i++)
  {
    cin >> nodes[i];
  }

  cout << doit(0);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}