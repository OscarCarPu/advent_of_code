#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  
  string line;
  int sol=0;
  while (getline(cin, line)) {
    istringstream iss(line);
    vector<int> numbers;
    int n, bef_n = -1;
    int order = 0;
    bool safe = true;
    while (iss >> n) {
      if (bef_n == -1) {
        bef_n = n;
        continue;
      }
      if (order == 0) {
        order = n > bef_n ? 1 : -1;
      }
      if (order != (n > bef_n ? 1 : -1) || abs(n-bef_n)<1 || abs(n-bef_n)>3) {
        safe = false;
      }
      bef_n = n;
    }
    if (safe) {
      sol++;
    }
  
  }
  
  cout<<sol;
}