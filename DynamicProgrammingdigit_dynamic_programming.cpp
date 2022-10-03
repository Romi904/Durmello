*
Find the number of integers between 1 and K (inclusive) satisfying The sum of the digits in base 10 is a multiple of D
, modulo 10e9+7
*/



#include<bits/stdc++.h>

using namespace std;
namespace Acc {
  const int N = 10009,
    M = 109,
    P = 1e9 + 7;
  int f[N][M][2];
  void work() {
    int n, m, i, j, k, l, h;
    string s;
    cin >> s >> m, n = s.size(), ( ** f)[1] = 1;
    auto up = [ & ](int & x, int y) {
      x = x + y < P ? x + y : x + y - P;
    };
    for (i = 1; h = s[i - 1] ^ 48, i <= n; ++i)
      for (j = 0; j < m; ++j)
        for (k = 0; k < 2; ++k)
          for (l = 0; l < 10 && (!k || l <= h); ++l)
            up(f[i][(j + l) % m][k && l == h], f[i - 1][j][k]);
    cout << (f[n][0][0] + f[n][0][1] - 1 + P) % P << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  return Acc::work(), 0;
}
