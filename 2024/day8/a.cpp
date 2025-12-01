#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  vector<string> Map;
  string s;
  while(getline(cin, s)){
    Map.push_back(s);
  }
  int n = Map.size();
  map<char,vector<pair<int,int>>> Antenas;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(Map[i][j] != '.'){
        Antenas[Map[i][j]].push_back({i,j});
      }
    }
  }
  vector<vector<bool>> Visited(n,vector<bool>(n,false));
  int sol = 0;
  for(auto it : Antenas){
    for(int i=0;i<it.second.size();i++){
      int x = it.second[i].first;
      int y = it.second[i].second;
      for(int j=i+1;j<it.second.size();j++){
        int x2 = it.second[j].first;
        int y2 = it.second[j].second;
        int xdist = x-x2;
        int ydist = y-y2;
        if(xdist+x>=0 and xdist+x<n and ydist+y>=0 and ydist+y<n and !Visited[xdist+x][ydist+y]){
          Visited[xdist+x][ydist+y] = true;
          sol++;
        }
        if(x2-xdist>=0 and x2-xdist<n and y2-ydist>=0 and y2-ydist<n and !Visited[x2-xdist][y2-ydist]){
          Visited[x2-xdist][y2-ydist] = true;
          sol++;
        }
      }
    }
  }
  cout<<sol;
}