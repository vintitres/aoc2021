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
#define PAD 55
using namespace std;

tuple<char, int> enh(vector<string> &img, const string &alg, char space = '.') {
  int cnt = 0;
  char space2;
  if (space == '.') space2 = alg[0];
  else space2 = alg[511];
  int sizi = img.size(), sizj = img[0].size();
  vector<string> img2(img);
  for (int i = 0; i < sizi; ++i) {
    for (int j = 0; j < sizj; ++j) {
      int x = 0;
      for (int ii = i - 1; ii <= i + 1; ++ii) {
        for (int jj = j - 1; jj <= j + 1; ++jj) {
          x <<= 1;
          char c = (ii < 0 || ii >= sizi || jj < 0 || jj >= sizj) ? space : img[ii][jj];
          if (c == '#') ++x;
        }
      }
      img2[i][j] = alg[x];
      if(alg[x] == '#') ++cnt;
    }
  }
  img = img2;
  return make_tuple(space2, cnt);
}

int main(){
  string alg;
  cin >> alg;
  string s;
  vector<string> img(PAD);
  string lpad(PAD, '.');
  while(cin >> s) {
    img.push_back(lpad + s + lpad);
  }
  string pad(img[PAD].size(), '.');
  for (int i = 0; i < PAD; ++i) {
    img[i] = pad;
    img.push_back(pad);
  }

  for (string l : img) {
    cout << l << endl;
  }
  cout << endl;

  char space = '.';
  int cnt;
  for (int i = 0; i < 50; ++i) {
    tie(space,cnt) = enh(img,alg,space);
  }
  for (string l : img) {
    cout << l << endl;
  }

  if (space == '#') cout << "inf" << endl;
  else cout << cnt << endl;
}

