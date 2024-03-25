#include <iostream>

#define MAX 987654321

using namespace std;

bool apple[5][5];
bool visited[5][5];

int ans = MAX;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void doit(int r, int c, int m_cnt, int a_cnt)
{
  if (apple[r][c])
  {
    a_cnt++;
    if (a_cnt >= 3 && m_cnt < ans)
    {
      ans = m_cnt;
      return;
    }
  }

  for (int i = 0; i < 4; i++)
  {
    int nr = r + dx[i];
    int nc = c + dy[i];

    if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5)
      continue;

    if (!visited[nr][nc])
    {
      visited[nr][nc] = true;
      doit(nr, nc, m_cnt + 1, a_cnt);
      visited[nr][nc] = false;
    }
  }
}

void solve()
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      int val;
      cin >> val;

      if (val == 1)
        apple[i][j] = true;
      if (val == -1)
        visited[i][j] = true;
    }
  }

  int r, c;
  cin >> r >> c;
  visited[r][c] = true;
  doit(r, c, 0, 0);

  if (ans == MAX)
    cout << -1;
  else
    cout << ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}