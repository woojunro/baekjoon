#include <iostream>

using namespace std;

int board[6][7];

int check_winner()
{
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      // down
      if (j <= 3 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1)
        return 1;
      if (j <= 3 && board[i][j] == -1 && board[i][j + 1] == -1 && board[i][j + 2] == -1 && board[i][j + 3] == -1)
        return -1;
      // right
      if (i <= 2 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1)
        return 1;
      if (i <= 2 && board[i][j] == -1 && board[i + 1][j] == -1 && board[i + 2][j] == -1 && board[i + 3][j] == -1)
        return -1;
      // left down
      if (i >= 3 && j <= 3 && board[i][j] == 1 && board[i - 1][j + 1] == 1 && board[i - 2][j + 2] == 1 && board[i - 3][j + 3] == 1)
        return 1;
      if (i >= 3 && j <= 3 && board[i][j] == -1 && board[i - 1][j + 1] == -1 && board[i - 2][j + 2] == -1 && board[i - 3][j + 3] == -1)
        return -1;
      // right down
      if (i <= 2 && j <= 3 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1)
        return 1;
      if (i <= 2 && j <= 3 && board[i][j] == -1 && board[i + 1][j + 1] == -1 && board[i + 2][j + 2] == -1 && board[i + 3][j + 3] == -1)
        return -1;
    }
  }

  return 0;
}

void solve()
{
  bool winner_chosen = false;

  for (int i = 0; i < 21; i++)
  {
    int S, J;
    cin >> S >> J;

    int j = 0;
    while (j < 6 && board[S - 1][j + 1] == 0)
      j++;
    board[S - 1][j] = 1;

    j = 0;
    while (j < 6 && board[J - 1][j + 1] == 0)
      j++;
    board[J - 1][j] = -1;

    int winner = check_winner();

    if (winner == 1)
    {
      winner_chosen = true;
      cout << "sk " << i + 1;
      break;
    }

    if (winner == -1)
    {
      winner_chosen = true;
      cout << "ji " << i + 1;
      break;
    }
  }

  if (!winner_chosen)
  {
    cout << "ss";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}