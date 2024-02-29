#include <iostream>
#include <vector>

using namespace std;

int N, rnd, cnt;
int ans[10];

bool doit(int depth, int pos)
{
  if (depth == rnd)
  {
    cnt++;

    if (cnt == N)
      return true;

    return false;
  }

  bool done = false;

  for (int i = 0; i < pos; i++)
  {
    ans[depth] = i;
    done = doit(depth + 1, i);
    if (done)
      break;
  }

  return done;
}

void solve()
{
  cnt = 0;
  cin >> N;

  bool done;

  for (rnd = 1; rnd <= 10; rnd++)
  {
    done = doit(0, 10);
    if (done)
      break;
  }

  if (done)
  {
    for (int i = 0; i < rnd; i++)
      cout << ans[i];
  }
  else
  {
    cout << -1;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}