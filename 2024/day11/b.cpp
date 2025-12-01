#include <bits/stdc++.h>

using namespace std;

#define int long long 


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  freopen("input.txt","r",stdin);
  map<int,int> M;
  int x;
  while(cin>>x){
    M[x]++;
  }
  for(int i=0;i<75;i++){
    cout<<i<<endl;
    map<int,int> nM;
    for(auto it = M.begin();it!=M.end();it++){
      if(it->first==0){
        nM[1] += it->second;
      }
      else if(to_string(it->first).length()%2==0){
        int first_half = stoi(to_string(it->first).substr(0,to_string(it->first).length()/2));
        int second_half = stoi(to_string(it->first).substr(to_string(it->first).length()/2));
        nM[first_half] += it->second;
        nM[second_half] += it->second;
      }
      else{
        nM[it->first*2024] += it->second;
      }
    }
    M = nM;
  }
  int sol = 0;
  for(auto it = M.begin();it!=M.end();it++){
    sol+=it->second;
  }
  cout<<sol;
}