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

void add(map<string, long long int> &polymer, string &pair, long long int count) {
    if (polymer.find(pair) == polymer.end()) polymer[pair] = 0;
    polymer[pair] += count;
}

int main(){
  string polymert;
  cin >> polymert;
  string pair, sep, ins;
  map<string,char> rules;
  while(cin >> pair >> sep >> ins) {
    rules[pair] = ins[0];
  }
  map<string,long long int> polymer;
  for (auto it = polymert.begin(); it + 1 != polymert.end(); ++it) {
    string pair{*it, *(it + 1)};
    add(polymer, pair, 1);
  }
  for (int i = 1; i <= 40; ++i) {
    map<string,long long int> nextpolymer;
    for (auto p : polymer) {
      string pair = p.first;
      long long int count = p.second;
      char nc = rules[pair];
      string np1{pair[0], nc};
      string np2{nc, pair[1]};
      add(nextpolymer, np1, count);
      add(nextpolymer, np2, count);
    }
    polymer = nextpolymer;
  }
   
  map<char,long long int> count;
  for (auto p : polymer) {
    char c = p.first[0];
    if (count.find(c) == count.end()) count[c] = 0;
    count[c] += p.second;
  }
  count[*polymert.rbegin()]++;
  long long int maxcount, mincount;
  maxcount = mincount = count.begin()->second;
  for (auto p : count) {
    cout << p.first << " " << p.second << endl;
    long long int cc = p.second;
    maxcount = cc > maxcount ? cc : maxcount;
    mincount = cc < mincount ? cc : mincount;
  }
  cout << maxcount - mincount << endl;
}

