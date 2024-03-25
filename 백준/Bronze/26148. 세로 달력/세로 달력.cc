#include <iostream>

using namespace std;

int days_lunar[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days_not_lunar[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_lunar_year(int year)
{
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

void solve()
{
  int N, day;
  cin >> N >> day;

  int ans = 0;

  for (int i = 0; i <= 11; i++)
  {
    int cnt[7] = {0};

    if (is_lunar_year(N))
    {
      for (int j = 0; j < days_lunar[i]; j++)
      {
        cnt[day - 1]++;
        day++;
        if (day > 7)
          day = 1;
      }
    }
    else
    {
      for (int j = 0; j < days_not_lunar[i]; j++)
      {
        cnt[day - 1]++;
        day++;
        if (day > 7)
          day = 1;
      }
    }

    for (int j = 0; j < 7; j++)
    {
      if (cnt[j] >= 5)
        ans++;
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