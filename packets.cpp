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

void append(vector<bool> &packet, int x) {
  int d = 1<<3;
  while(d > 0) {
    packet.push_back(x & d);
    d>>=1;
  }
}

void append(vector<bool> &packet, char c) {
  append(packet, (int)(c >= '0' && c <= '9' ? c - '0' : c - 'A' + 10));
}

int readint(vector<bool>::iterator &it, int len) {
  int x = 0;
  for (int i = 0; i < len; ++i) {
    x <<= 1;
    x += *(it++);
  }
  return x;
}

long long int readpacket(vector<bool>::iterator &it) {
  int ver = readint(it, 3);
  int t = readint(it, 3);
  if (t == 4) {
    long long int x = 0;
    while (true) {
      bool cont = *(it++);
      x <<= 4;
      x += readint(it, 4);
      if (!cont) return x;
    }
  } else {
    bool lt = *(it++);
    vector <long long int> vals;
    if (lt == 0) {
      int totlen = readint(it, 15);
      auto endit = it + totlen;
      while (it != endit) {
        vals.push_back(readpacket(it));
      }
    } else {
      int packets = readint(it, 11);
      for (int i = 0; i < packets; ++i) {
        vals.push_back(readpacket(it));
      }
    }
    switch(t) {
      case 0:
        return accumulate(vals.begin(), vals.end(), 0LL);
      case 1:
        return accumulate(vals.begin(), vals.end(), 1LL, multiplies<long long int>());
      case 2:
        return *min_element(vals.begin(), vals.end());
      case 3:
        return *max_element(vals.begin(), vals.end());
      case 5:
        return vals[0] > vals[1] ? 1LL : 0LL;
      case 6:
        return vals[0] < vals[1] ? 1LL : 0LL;
      case 7:
        return vals[0] == vals[1] ? 1LL : 0LL;
    }
  }
}

int main(){
  string s;
  cin >> s;
  vector<bool> packet;
  for (char c : s) {
    append(packet, c);
  }
  vector<bool>::iterator it = packet.begin();
  cout << readpacket(it) << endl;
}

