#include<iostream>
#include<set>
#include<vector>
using namespace std;



void f(const string &s, vector<int> &v, set<int>&ss) {
  int vv=0,i=0;
  for (auto it=s.begin(); it != s.end(); ++it){
    vv=vv<<1;
    if (*it=='1'){++vv;++v[i];}
    else --v[i];
    ++i;
  }
  ss.insert(vv);
}

void ff(set<int> &vals, vector<int> &bit_sums, int p, bool b) {

  cout << (1<<p) << "p " << b << "b ";
  for (auto it =vals.begin();it!=vals.end();) {
    cout << *it;
    if(((bool)((*it)&(1<<p))) == b) {
      cout << "k";
      ++it;
    }
    else {
      int v =*it;
      for (auto itt = bit_sums.rbegin(); itt != bit_sums.rend(); ++itt){
        if (v %2) --*itt;
        else ++*itt;
        v/=2;
      }
      it =vals.erase(it); 
    }
    cout << ' ';
  }
}

int fff(set<int> vals, vector<int> bit_sums, bool a, bool b) {
  int i = bit_sums.size() -1;
  for (auto it=bit_sums.begin(); it!=bit_sums.end(); ++it){
    cout << *it << endl;
    ff(vals, bit_sums, i,*it>=0?a:b);
    if(vals.size()==1)return *(vals.begin());
    cout << endl;
    --i;
  }

}
int main(){
  string s;
  cin>>s;
  vector<int> x(s.size());
  set<int>ss;
  f(s,x,ss);
  while (cin >> s) {
    f(s, x,ss);
  }
  int ssv = fff(ss, x, 1, 0);
  int sssv = fff(ss, x, 0, 1);
    cout << ssv << " " <<sssv<< endl;
  cout << ssv*sssv<< endl;
}

