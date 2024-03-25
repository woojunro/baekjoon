#include <iostream>

using namespace std;

void solve()
{
  int score = 0;

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      char c;
      cin >> c;

      if (c == 'P')
        score += 1;
      if (c == 'p')
        score -= 1;
      if (c == 'N')
        score += 3;
      if (c == 'n')
        score -= 3;
      if (c == 'B')
        score += 3;
      if (c == 'b')
        score -= 3;
      if (c == 'R')
        score += 5;
      if (c == 'r')
        score -= 5;
      if (c == 'Q')
        score += 9;
      if (c == 'q')
        score -= 9;
    }
  }

  cout << score;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}