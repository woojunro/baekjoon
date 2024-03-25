#include <iostream>

using namespace std;

void solve()
{
  int N;
  cin >> N;

  int ans = 0;
  int day = 0;
  bool freeze = true;
  int day_used = -999;

  for (int i = 1; i <= N; i++)
  {
    int P;
    cin >> P;

    if (!freeze && day_used + 2 == i)
    {
      freeze = true;
    }

    if (P > 0)
    {
      day++;
      if (day > ans)
      {
        ans = day;
      }
    }
    else
    {
      if (freeze)
      {
        freeze = false;
        day_used = i;
      }
      else
      {
        day = 0;
      }
    }
  }

  cout << ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}