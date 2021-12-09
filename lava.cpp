#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
#include<list>
#include<climits>
#include<set>
#include<sstream>
#include<vector>
using namespace std;

vector<string> split (string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
    token = s.substr (pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back (token);
  }

  res.push_back (s.substr (pos_start));
  return res;
}

int main(){
  string s;
  vector <string> cave;
  while(cin >> s) {
    cave.push_back(s);
  }
  int n = cave.size(), m = cave[0].size();
  vector<pair<int,int>> lows;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      int h = cave[i][j];
      int l = j > 0 ? cave[i][j-1] : '9';
      int r = j < m - 1 ? cave[i][j+1] : '9';
      int u = i > 0 ? cave[i-1][j] : '9';
      int d = i < n - 1 ? cave[i+1][j] : '9';
      if (h < l && h < r && h < u && h < d) {
        lows.push_back(make_pair(i, j));
      }
    }
  }
  vector <int> sizes;
  for (auto low : lows) {
    int size = 0;
    queue<pair<int, int>> q;
    q.push(low);
    while (!q.empty()) {
      pair<int,int> p=q.front();
      q.pop();
      int i = p.first, j = p.second;
      if (i == -1 || j == -1 || i == n || j == m || cave[i][j]=='9') continue;
      ++size;
      cave[i][j]='9';
      q.push(make_pair(i+1, j));
      q.push(make_pair(i-1, j));
      q.push(make_pair(i, j+1));
      q.push(make_pair(i, j-1));
    }
    sizes.push_back(size);
    cout << size << endl;
  }
  sort(sizes.begin(), sizes.end());
  int ss = sizes.size();
  cout << sizes[ss -1] * sizes[ss-2] * sizes[ss-3]  << endl;
}


