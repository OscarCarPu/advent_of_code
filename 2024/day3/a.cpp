#include<bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  int sol = 0;
  string l;
  while(cin>>l){
    int n = l.size();
    int a=-1,b=-1;
    bool read = false,second=false;
    for(int i=0;i<n;i++){
      if(read and l[i]==')'){
        sol+=a*b;
        read = false;
        a=-1;
        second=false;
        b=-1;
        continue;
      }
      if(read and l[i]==','){
        second = true;
        continue;
      }
      if(read and (l[i]<'0' or l[i]>'9')){
        read = false;
        a=-1;
        second=false;
        b=-1;
      }
      if(read and !second){
        a*=10;
        a+=l[i]-'0';
        continue;
      }
      if(read and second){
        b*=10;
        b+=l[i]-'0';
        continue;
      }
      if(i<n-3 and l.substr(i,4) == "mul("){
        read = true;
        a = 0;
        b = 0;
        i += 3;
      }
    }
  }
  cout<<sol;
}