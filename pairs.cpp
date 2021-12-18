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

enum RAction { explode, split, none };
class RResult {
public:
  RAction action;
  int lexplode, rexplode;
  RResult(RAction _action, int _lexplode = 0, int _rexplode = 0) {
    action = _action;
    lexplode = _lexplode;
    rexplode = _rexplode;
  }
};

class Pair {
  public:
  int x;
  Pair *l;
  Pair *r;
  Pair(int _x) {
    x = _x;
    l = NULL;
    r = NULL;
  }
  Pair(Pair *_l, Pair *_r) {
    x = -1;
    l = _l;
    r = _r;
  }
  ~Pair() {
    if (x == -1) {
      delete l;
      delete r;
    }
  }
  static Pair* parse(string::iterator &it) {
    Pair *l, *r;
    char c = *(it++);
    while (c == ',' || c == ']') c = *(it++);
    if (c == '[') {
      l = Pair::parse(it);
      r = Pair::parse(it);
      return new Pair(l, r);
    } else {
      int x = 0;
      while (true) {
        if (c == ',' || c == ']') {
          return new Pair(x);
        }
        x *= 10;
        x += c - '0';
        c = *(it++);
      }
    }
  }
  void addr(int xx) {
    if (x != -1) x += xx;
    else r->addr(xx);
  }
  void addl(int xx) {
    if (x != -1) x += xx;
    else l->addl(xx);
  }
  void reduce() {
    RAction a = RAction::explode;
    while(a != RAction::none) {
      a = reducestep().action;
      if (a == RAction::none) {
        a = reducestep(4, true).action;
      }
      print();
      cout<< endl;
    }
  }
  RResult reducestep(int lv = 4, bool allowsplit = false) {
    if (x != -1) {
      if (x >= 10 && allowsplit) {
        l = new Pair(x / 2);
        r = new Pair(x / 2 + x % 2);
        x = -1;
        return RResult(RAction::split);
      }
      return RResult(RAction::none);
    } else {
      if (lv == 0) {
        cout << "expl: ";
        print();
        cout<< endl;
        int lx = l->x, rx = r->x;
        delete l;
        l = NULL;
        delete r;
        r = NULL;
        x = 0;
        return RResult(RAction::explode, lx, rx);
      } 
      auto res = l->reducestep(lv - 1, allowsplit);
      if (res.action == RAction::split) {
        return res;
      } else if (res.action == RAction::explode) {
        if(res.rexplode != 0) r->addl(res.rexplode);
        res.rexplode = 0;
        return res;
      } else {
        res = r->reducestep(lv - 1, allowsplit);
        if (res.action == RAction::explode){
          if (res.lexplode != 0) l->addr(res.lexplode);
          res.lexplode = 0;
        }
        return res;
      }
    }
  }
  long long int mag() {
    if (x != -1) return x;
    return l->mag() * 3LL + r->mag() * 2LL;
  }
  void print() {
    if (x != -1) cout << x;
    else {
      cout << "[";
      l->print();
      cout<< ",";
      r->print();
      cout<< "]";
    }
  }
};

int main(){
  string s;
  cin >> s;
  auto it = s.begin();
  Pair *p = Pair::parse(it);
  p->print();
  cout << endl;
  cout << endl;
  while(cin >> s) {
    it = s.begin();
    p = new Pair(p, Pair::parse(it));
    p->print();
    cout << endl;
    p->reduce();
    p->print();
    cout << endl;
    cout << endl;
  }
  cout << p->mag() << endl;
  delete p;
}

