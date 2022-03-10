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
#define MP make_pair
#define MT make_tuple
using namespace std;

class State {
  public:
  long long int w, x, y, z, inp;
  State (long long int i) {
    x = 0;
    y = 0;
    z = 0;
    inp = i;
  }
  void input(char d) {
    //cout << inp << endl;
    //cout << inp % 10 << endl;
    //cout << inp / 10 << endl;
    set(d, inp % 10);
    inp /= 10;
  }
  long long int get(char d) {
    if (d == 'x') {
      return x;
    } else if (d == 'y') {
      return y;
    } else if (d == 'z') {
      return z;
    } else if (d == 'w') {
      return w;
    }
  }
  void set(char d, long long int i) {
    if (d == 'x') {
      x = i;
    } else if (d == 'y') {
      y = i;
    } else if (d == 'z') {
      z = i;
    } else if (d == 'w') {
      w = i;
    }
  }
};
//typedef long long int[] State;

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

State exe(State st, string cmd) {
  //cout << cmd << endl;
  auto ss = split(cmd, " ");
  char d = ss[1][0];
  if (ss[0] == "inp") {
    st.input(d);
    //cout << st.get(d) << endl;
      return st;
  }
  int w;
  if (ss[2][0] >= 'w' && ss[2][0] <= 'z') w = st.get(ss[2][0]);
  else w = stoi(ss[2]);
  if (ss[0]  == "add") {
    st.set(d, st.get(d) + w);
    return st;
  }
  if (ss[0] == "mul") {
    st.set(d, st.get(d) * w);
    return st;
  }
  if (ss[0] == "div") {
    st.set(d, st.get(d) / w);
    return st;
  }
  if (ss[0] == "mod") {
    st.set(d, st.get(d) % w);
    return st;
  }
  if (ss[0] == "eql") {
    st.set(d, st.get(d) == w ? 1 : 0);
    return st;
  }
  //cout << "bad"  << endl;
}


int main() {
  vector<string> cmds;
  string s;
  while(getline(cin, s)) {
    cmds.push_back(s);
  }
  for (long long int i = 99999999999999; i > 11111111111111; --i) {
    long long int ri = 0;
    for (long long int ii = i; ii > 0; ii /= 10) {
      ri *= 10;
      int r = ii % 10;
      if (r == 0) {
        ri = 0;
        break;
      }
      ri += r;
    }
    if (ri == 0) continue;
    State st(ri);
    //cout << ri << endl;
    for (auto s : cmds) {
      st = exe(st, s);
      //cout << "!" << endl;

    }
    if (st.get('z') == 0) {
      cout << i << endl;
    }
  }
}

