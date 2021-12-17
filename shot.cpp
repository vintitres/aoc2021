#include<iostream>
#include<queue>
#include<numeric>
#include<algorithm>
#include<cmath>
#include<map>
#include<list>
#include<climits>
#include<set>
#include<sstream>
#include<vector>
#include<stack>
using namespace std;

vector<string> split (string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  vector<string> res;
  while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
    res.push_back(s.substr (pos_start, pos_end - pos_start));
    pos_start = pos_end + delim_len;
  }
  res.push_back (s.substr (pos_start));
  return res;
}
int main(){
  string s;
  cin >> s;
  cin >> s;
  cin >> s;
  auto ss = split(s, "=");
  ss = split(ss[1], "..");
  int xl = stoi(ss[0]), xr = stoi(ss[1]);
  cin >> s;
  ss = split(s, "=");
  ss = split(ss[1], "..");
  int yd = stoi(ss[0]), yu = stoi(ss[1]);
  int cnt = 0;
  for (int xv = sqrt(xl * 2) - 1; xv <= xr; ++xv) {
    for (int yv = -yd; yv >= yd; --yv) {
      int x = 0, y = 0, xx = xv, yy = yv;
      while (x <= xr && y >= yd) {
        x += xx;
        if (xx > 0) --xx;
        y += yy--;
        if (x >= xl && x <= xr && y >= yd &&  y <= yu) { 
          ++cnt;
          break;
        }
      }
    }
  }

  cout << cnt << endl;
}

