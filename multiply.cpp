#include<iostream>
#include<map>
#include<list>
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
  vector <long long int> fish(9, 0);
  long long int fishc=0;
  for (auto sn : split(s, ",")) {
    ++fish[stoi(sn)];
    ++fishc;
  }
  for (int i = 1; i <=256; ++i){
    fish[(i + 6) % 9] += fish[(i - 1) % 9];
    fishc += fish[(i - 1) % 9];
    /*
    for (int j = i; j < i +9; ++j) {
      cout << fish[j%9] << " ";
    }
      */
    cout << "= " << fishc << endl;
  }
}


