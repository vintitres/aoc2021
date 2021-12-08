#include<iostream>
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

bool subset(string s1, string s2) {
  for (char c : s1) {
    bool f = false;
    for (char cc : s2) {
      if (c == cc) {
        f = true;
        break;
      }
    }
    if (!f) return false;
  }
  return true;
}


int main(){
  int cnt =0;
  vector<string> patt(10), p(10);
  while (cin >> patt[0]){
    p[0]="";
    for (int i=1; i<10; ++i){
      p[i]="";
      cin >> patt[i];
    }
    for (int i=0; i<10; ++i){
      sort(patt[i].begin(), patt[i].end());
      switch (patt[i].size()) {
        case 2:
          p[1] = patt[i];
          break;
        case 3:
          p[7] = patt[i];
          break;
        case 4:
          p[4] = patt[i];
          break;
        case 7:
          p[8] = patt[i];
          break;
        default:
          break;
      }
    }
    for (int i=0; i<10; ++i){
      switch (patt[i].size()) {
        case 5:
          // 2 or 3 or 5
          if (subset(p[1],patt[i])) {
            p[3] = patt[i];
            patt[i]="";
          } 
          break;
        case 6:
          // 0 or 6 or 9
          if (subset(p[4],patt[i])) {
            p[9] = patt[i];
          } else if (subset(p[1], patt[i])) {
            p[0]=patt[i];
          } else {
            p[6]=patt[i];
          }
          break;
        default:
          break;
      }
    }
    for (int i=0; i<10; ++i){
      switch (patt[i].size()) {
        case 5:
          // 2 or 5
          if (subset(patt[i],p[6])) {
            p[5] = patt[i];
          } else {
            p[2] = patt[i];
          }
          break;
        default:
          break;
      }
    }
    map<string,int>pp;
    for (int i=0; i<10; ++i){
      cout << i << ": " << p[i] << endl;
      pp[p[i]]=i;
    }
    string sep;
    cin >> sep;
    int d=1000;
    for (int i=0; i<4; ++i) {
      string digit;
      cin >> digit;
      sort(digit.begin(), digit.end());
      cnt += d*pp[digit];
      d/=10;
    }
  }
  cout << cnt << endl;
}


