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
  string s;
  cin >> s;
  map <int,int> crabs;
  int sum =0, count=0;
  for (auto sn : split(s, ",")) {
    int crab=stoi(sn);
    auto it = crabs.find(crab);
    if (it == crabs.end()) {
      crabs.insert(pair<int,int>(crab, 1));
    }
      else {++(crabs[crab]);}
    sum += crab;
    ++count;
  }
  int bestcost=INT_MAX;
  for (int pos = crabs.begin()->first; pos <= crabs.rbegin()->first; ++ pos){
      int cost=0;
  for (auto c : crabs) {
    cost += abs(c.first - pos)*c.second;
  }
  bestcost=min(bestcost,cost);
  }
  cout << "= " << bestcost << endl;
}


