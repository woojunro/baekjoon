#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int H[9];

bool check_prime(int num)
{
  if (num == 1)
  {
    return false;
  }

  for (int i = 2; i * i <= num; i++)
  {
    if (num % i == 0)
    {
      return false;
    }
  }

  return true;
}

void solve()
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    cin >> H[i];
  }

  vector<int> ans;

  vector<bool> comb(N, false);
  for (int i = 0; i < M; i++)
  {
    comb[i] = true;
  }

  do
  {
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
      if (comb[i])
      {
        sum += H[i];
      }
    }

    if (check_prime(sum))
    {
      ans.push_back(sum);
    }
  } while (prev_permutation(comb.begin(), comb.end()));

  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());

  if (ans.size() < 1)
  {
    cout << -1;
    return;
  }

  for (int a : ans)
  {
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