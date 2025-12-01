#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt","r",stdin);
  string s;
  cin>>s;
  vector<pair<int,int>> free;
  vector<tuple<int,int,int>> ocuppied;
  int p =0;
  int n = s.length();
  for(int i=0;i<n;i++){
    if(i%2==0){
      ocuppied.push_back(make_tuple(s[i]-'0',p,i/2));
    }
    else free.push_back({s[i]-'0',p});
    p+=(s[i]-'0');
  }
  for(int i=ocuppied.size()-1;i>=0;i--){
    for(int j=0;j<free.size() and free[j].second < (get<1>(ocuppied[i]));j++){
      if(free[j].first>=get<0>(ocuppied[i])){
        free[j].first-=get<0>(ocuppied[i]);
        get<1>(ocuppied[i]) = free[j].second;
        free[j].second+=get<0>(ocuppied[i]);
      }
    }
  }
  int sol = 0;
  p=0;
  sort(ocuppied.begin(), ocuppied.end(), 
       [](const auto& a, const auto& b) { return get<1>(a) < get<1>(b); });
  for(int i = 0;i<ocuppied.size();i++){
    p = get<1>(ocuppied[i]);
    int len = get<0>(ocuppied[i]) -1;
    sol += ((2*p*len + len*len+2*p+len)/2)*get<2>(ocuppied[i]);
    cout<<p<<" "<<get<0>(ocuppied[i])<<" "<<get<1>(ocuppied[i])<<" "<<get<2>(ocuppied[i])<<endl;
  }
  cout<<sol<<endl;
}
















