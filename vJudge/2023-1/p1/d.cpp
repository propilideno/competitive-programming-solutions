#include <array>
#include <bits/stdc++.h>

#define DEBUG false
#define OJ_DEBUG

#define $(x)                                                                   \
  {                                                                            \
    if (DEBUG) {                                                               \
      cout << __LINE__ << ": ";                                                \
      {x} cout << endl;                                                        \
    }                                                                          \
  }
#define _(x)                                                                   \
  { cout << #x << " = " << x << " "; }

const double E = 1e-8;
const double PI = acos(-1);

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int j = n;
  vector<int> k;
  int temp;
  while (n--) {
    cin >> temp;
    k.push_back(temp);
  }
  sort(k.begin(), k.end());
  int p = k[0];
  int q = k[n - 1];
  for (int i = 0; i < n / 2; p = k[i]) {
  }
}
