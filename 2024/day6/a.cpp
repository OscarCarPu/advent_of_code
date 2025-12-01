#include <bits/stdc++.h>
using namespace std;

vector<string> Map;
vector<vector<vector<bool>>> V;
vector<char> guard = {'>','v','<','^'};
pair<int,int> start;
int sol = 0;
int n,m;

void check(int x,int y,int g){
  if(V[y][x][g]) return;
  if(!V[y][x][0] and !V[y][x][1] and !V[y][x][2] and !V[y][x][3])sol++;
  V[y][x][g] = true;

  vector<pair<int,int>> direction = {{1,0},{0,1},{-1,0},{0,-1}};

  for(int i=0;i<4;i++){
    int dir = (g+i)%4;
    int nx = x+direction[dir].first;
    int ny = y+direction[dir].second;
    if(nx<0 or nx>=n or ny<0 or ny>=n) return;
    if(Map[ny][nx]!='#'){
      check(nx,ny,dir);
      break;
    }
  }
  return;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  freopen("input.txt","r",stdin);
  int x,y;
  string s;
  do {
    cin>>s;
    for(char c : guard){
      if (s.find(c) != string::npos){
        x = s.find(c);
        y = Map.size();
        break;
      }
    }
    if (s == "") break;
    Map.push_back(s);
  } while (getline(cin, s));
  n = Map.size();
  V = vector<vector<vector<bool>>>(n,vector<vector<bool>>(n,vector<bool>(4,false)));
  int g;
  for (int i=0;i<4;i++){
    if(Map[y][x] == guard[i]){
      g=i;
    }
  }

  check(x,y,g);

  cout<<sol;

}