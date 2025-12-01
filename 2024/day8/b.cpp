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
        if(!Visited[x][y])Visited[x][y] = true,sol++;
        if(!Visited[x2][y2])Visited[x2][y2] = true,sol++;
        int xdist = x-x2;
        int ydist = y-y2;
        int auxx = x, auxy = y,auxx2 = x2, auxy2 = y2;
        while(xdist+auxx>=0 and xdist+auxx<n and ydist+auxy>=0 and ydist+auxy<n ){
          if(!Visited[xdist+auxx][ydist+auxy])Visited[xdist+auxx][ydist+auxy] = true,sol++;
          auxx+=xdist;
          auxy+=ydist;
        }
        while(auxx2-xdist>=0 and auxx2-xdist<n and auxy2-ydist>=0 and auxy2-ydist<n){
          if(!Visited[auxx2-xdist][auxy2-ydist])Visited[auxx2-xdist][auxy2-ydist] = true,sol++;
          auxx2-=xdist;
          auxy2-=ydist;
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(Visited[i][j])cout<<"#";
      else cout<<Map[i][j];
    }
    cout<<endl;
  }
  cout<<sol;
}