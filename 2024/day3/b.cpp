#include<bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  int sol = 0;
  string l;
  bool active = true;
  while(cin>>l){
    int n = l.size();
    int a=-1,b=-1;
    bool read = false,second=false;
    for(int i=0;i<n;i++){
      if(i<n-3 and l.substr(i,4) == "do()"){
        active = true;
        i+=3;
        continue;
      }
      if(i<n-6 and l.substr(i,7) == "don't()"){
        active = false;
        i+=6;
        continue;
      }
      if(!active){
        if(read){
          read = false;
          a = -1;
          b = -1;
          second = false;
        }
        continue;
      }
      if(read and l[i]==')'){
        if(second==false or l[i-1]==','){
          a = -1;
          b = -1;
          read = false;
          second=false;
          continue;
        }
        sol+=a*b;
        read = false;
        a=-1;
        second=false;
        b=-1;
        continue;
      }
      if(read and l[i]==','){
        second = true;
        b = 0;
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
        i += 3;
      }
    }
  }
  cout<<sol;
}