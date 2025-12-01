#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(vector<int> nums){
  bool safe = true;
  int order = nums[1] > nums[0] ? 1 : -1;
  for (int i=1;i<nums.size();i++){
    if (nums[i] < nums[i-1] && order == 1){
      safe = false;
    }
    if (nums[i] > nums[i-1] && order == -1){
      safe = false;
    }
    if (abs(nums[i]-nums[i-1])>3 or abs(nums[i]-nums[i-1])<1)
      safe = false;
  }
  return safe;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  
  string line;
  int sol=0;
  while (getline(cin, line)) {
    istringstream iss(line);
    vector<int> numbers;
    int n;
    while (iss >> n) {
      numbers.push_back(n);
    }
    if (check(numbers)){
      sol++;
      continue;
    }
    for(int i=0;i<numbers.size();i++){
      vector<int> temp = numbers;
      temp.erase(temp.begin()+i);
      if (check(temp)){
        sol++;
        break;
      }
    }
  }
  
  cout<<sol;
}