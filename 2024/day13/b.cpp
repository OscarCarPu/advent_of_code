#include <bits/stdc++.h>

using namespace std;

#define int long long 

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  freopen("input.txt","r",stdin);
  
  int ax, ay, bx, by, px, py;
  string s;
  int ans = 0;
  while(getline(cin, s)) {
    if(s.empty()) continue;
    stringstream ss(s);
    string tmp;
    ss >> tmp >> tmp >> tmp;
    tmp = tmp.substr(2);
    ax = stoll(tmp);
    ss >> tmp;
    ay = stoll(tmp.substr(2));
    getline(cin, s);
    ss = stringstream(s);
    ss >> tmp >> tmp >> tmp;
    tmp = tmp.substr(2);
    bx = stoll(tmp);
    ss >> tmp;
    by = stoll(tmp.substr(2));
    getline(cin, s);
    ss = stringstream(s);
    ss >> tmp >> tmp;
    tmp = tmp.substr(2);
    px = stoll(tmp);
    ss >> tmp;
    py = stoll(tmp.substr(2));
    px+=10000000000000L;
    py+=10000000000000L;

    int s = (px * by - py * bx) / (ax * by - ay * bx);
    int t = (px - ax * s) / bx;

    if(s >= 0 and t >= 0 and (px*by-py*bx)%(ax*by-ay*bx) == 0 and (px-ax*s)%(bx) == 0){
      ans += s*3+t;
      cout<<s<<" "<<t<<endl;
    }

  }

  cout << ans << "\n";
  
  return 0;
}