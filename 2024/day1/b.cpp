#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  int a,b;
  vector<int> A;
  multiset<int> B;
  while(cin>>a>>b) {
    A.push_back(a);
    B.insert(b);
  }
  int sol = 0;
  for(int i : A){
    sol+=i*B.count(i);
  }

  cout<<sol;

}