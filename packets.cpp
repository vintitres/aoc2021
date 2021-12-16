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
#include<stack>
using namespace std;

void append(vector<bool> &packet, int x) {
  int d = 1<<3;
  while(d > 0) {
    packet.push_back(x & d);
    d>>=1;
  }
  cout << endl;
}

void append(vector<bool> &packet, char c) {
  append(packet, (int)(c >= '0' && c <= '9' ? c - '0' : c - 'A' + 10));
}

int main(){
  string s;
  cin >> s;
  vector<bool> packet;
  for (char c : s) {
    append(packet, c);
  }
  for (bool b : packet) {
    cout << (b ? 1 : 0);
  }
  cout << endl;
}

