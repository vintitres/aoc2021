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
  string polymer;
  cin >> polymer;
  string pair, sep, ins;
  map<string,char> pairs;
  while(cin >> pair >> sep >> ins) {
    pairs[pair] = ins[0];
  }

  for (int i = 1; i <= 10; ++i) {
    for (auto it = polymer.begin(); it + 1 != polymer.end(); ) {
      string pair{*it, *(it + 1)};
      it = polymer.insert(it + 1, pairs[pair]) + 1; 
    }
  }

  map<char,int> count;
  for (char c : polymer) {
    if (count.find(c) == count.end()) count[c] = 0;
    ++count[c];
  }
  int maxcount, mincount;
  maxcount = mincount = count.begin()->second;
  for (auto p : count) {
    cout << p.first << " " << p.second << endl;
    int cc = p.second;
    maxcount = cc > maxcount ? cc : maxcount;
    mincount = cc < mincount ? cc : mincount;
  }
  cout << maxcount - mincount << endl;
}

