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
    
    int mn = 1e9;
    int ra = 1e9;
    int rb = 1e9;
    for(int i = 0; i <= 100; i++) {
      for(int j = 0; j <= 100; j++) {
        int tpx = px - ax*i - bx*j;
        int tpy = py - ay*i - by*j;
        if(tpx != 0 || tpy != 0) continue;
        int tokens = i*3 + j;
        if(tokens < mn) {
          mn = tokens;
          ra = i;
          rb = j;
        }
      }
    }
    cout<<px<<" "<<py<<" "<<mn<<" "<<ra<<" "<<rb<<"\n";
    if(mn == 1e9) continue; 
    ans += mn;
  }

  cout << ans << "\n";
  
  return 0;
}