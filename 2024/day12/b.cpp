#include <bits/stdc++.h>

using namespace std;

#define int long long 

int n,m;
vector<string> Map;
vector<vector<bool>> Visited;

pair<int,int> check(int x,int y, char c){
  if(Visited[x][y]) return {0,0};
  Visited[x][y] = true;
  int f = 1;
  int sec = 0;
  if(x-1>=0 and Map[x-1][y]==c){
    auto p = check(x-1,y,c);
    sec += p.second;
    f+= p.first;
  }
  if(x+1<m and Map[x+1][y]==c){
    auto p = check(x+1,y,c);
    sec += p.second;
    f+= p.first;
  }
  if(y-1>=0 and Map[x][y-1]==c){
    auto p = check(x,y-1,c);
    sec += p.second;
    f+= p.first;
  }
  if(y+1<n and Map[x][y+1]==c){
    auto p = check(x,y+1,c);
    sec += p.second;
    f+= p.first;
  }

  if((x-1<0 or Map[x-1][y]!=c) and (y-1<0 or Map[x][y-1]!=c)){
    sec+=2;
  }
  if((x+1>=m or Map[x+1][y]!=c) and (y+1>=n or Map[x][y+1]!=c)){
    sec+=2;
  }
  if((y-1>=0 and Map[x][y-1]==c) and (x+1<m and Map[x+1][y]==c) and Map[x+1][y-1]!=c){
    sec+=2;
  }
  if((y+1<n and Map[x][y+1]==c) and (x-1>=0 and Map[x-1][y]==c) and Map[x-1][y+1]!=c){
    sec+=2;
  }
  return {f,sec};
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  freopen("input.txt","r",stdin);
  string s;
  while(cin>>s){
    Map.push_back(s);
  }
  m = Map.size();
  n = Map[0].size();
  Visited = vector<vector<bool>>(m,vector<bool>(n,false));
  int sol = 0;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(!Visited[i][j]){
        auto p = check(i,j,Map[i][j]);
        sol+=p.first*p.second;
        cout<<Map[i][j]<<" "<<p.first<<" "<<p.second<<endl;
      }
    }
  }
  cout<<sol;
}