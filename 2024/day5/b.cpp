#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  freopen("input.txt", "r", stdin);
  map<int,set<int>> M;
  string s;
  cin>>s;
  while(s.size()==5){
    int a = (s[0]-'0')*10+(s[1]-'0');
    int b = (s[3]-'0')*10+(s[4]-'0');
    M[a].insert(b);
    cin>>s;
  }
  int sol = 0;
  do {
    if(s=="") continue;
    istringstream iss(s);
    vector<int> v;
    string num;
    while(getline(iss, num, ',')) {
      v.push_back(stoi(num));
    }
    bool can = true;
    int n = v.size();    
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(M[v[j]].count(v[i])){
          can = false;
        }
      }
    }
    if(!can){
      while(!can){
        can=true;
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
            if(M[v[j]].count(v[i])){
              can = false;
              swap(v[i],v[j]);
              break;
            }
          }
          if(!can)break;
        }
        if(!can)continue;   
      }
      sol+=v[n/2];
    }
  } while(getline(cin,s));
  cout<<sol;
}