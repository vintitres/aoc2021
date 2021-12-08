#include<iostream>
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
  int cnt =0;
  vector<string> patt(10), value(4);
  while (cin >> patt[0]){
    for (int i=1; i<10; ++i) cin >> patt[i];
    string sep;
    cin >> sep;
    for (int i=0; i<4; ++i) {
      string digit;
      cin >> digit;
      switch (digit.size()) {
        case 2:
        case 3:
        case 4:
        case 7:
          ++cnt;
          break;
        default:
          break;
      }
    }
  }
  cout << cnt << endl;
}


