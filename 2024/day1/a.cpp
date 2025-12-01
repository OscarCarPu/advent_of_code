#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  int a,b;
  vector<int> A,B;
  while(cin>>a>>b) {
    A.push_back(a);
    B.push_back(b);
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  int sol = 0;
  for(int i=0;i<A.size();i++){
    sol+=abs(A[i]-B[i]);
  }
  cout<<sol;
}