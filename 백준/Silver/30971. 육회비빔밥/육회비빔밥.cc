#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int A[10], B[10], C[10];

void solve()
{
  cin >> N >> K;
  for (int i = 0; i < N; i++)
    cin >> A[i];
  for (int i = 0; i < N; i++)
    cin >> B[i];
  for (int i = 0; i < N; i++)
    cin >> C[i];

  vector<int> perm;
  for (int i = 0; i < N; i++)
    perm.push_back(i);

  int ans = -1;

  do
  {
    int sum = 0;
    bool complete = true;

    for (int i = 1; i < N; i++)
    {
      int prev = perm[i - 1];
      int cur = perm[i];

      if (C[prev] * C[cur] > K)
      {
        complete = false;
        break;
      }

      sum += A[prev] * B[cur];
    }

    if (complete && sum > ans)
    {
      ans = sum;
    }
  } while (next_permutation(perm.begin(), perm.end()));

  cout << ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}