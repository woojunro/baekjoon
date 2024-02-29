#include <iostream>
#include <vector>

#define MAX 987654321

using namespace std;

int N, mp, mf, ms, mv;
int p[16], f[16], s[16], v[16], c[16];
int min_cost = MAX;
vector<int> ans, cur;

void doit(int cur_p, int cur_f, int cur_s, int cur_v, int cur_c, int pos)
{
  if (cur_p >= mp && cur_f >= mf && cur_s >= ms && cur_v >= mv)
  {
    if (cur_c < min_cost)
    {
      min_cost = cur_c;
      ans = cur;
    }
    return;
  }

  for (int i = pos; i <= N; i++)
  {
    cur.push_back(i);
    doit(cur_p + p[i], cur_f + f[i], cur_s + s[i], cur_v + v[i], cur_c + c[i], i + 1);
    cur.pop_back();
  }
}

void solve()
{
  cin >> N >> mp >> mf >> ms >> mv;
  for (int i = 1; i <= N; i++)
    cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];

  doit(0, 0, 0, 0, 0, 1);

  if (min_cost == MAX)
    cout << -1;
  else
  {
    cout << min_cost << "\n";
    for (int a : ans)
      cout << a << " ";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}