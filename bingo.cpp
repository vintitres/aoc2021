#include<iostream>
#include<map>
#include<set>
#include<sstream>
#include<vector>
using namespace std;

class BingoBoard {
  map<int, int> nums;
  int rows[5], cols[5];
  
  public:
  BingoBoard(vector<int> &n) {
    for (int i =0; i  < n.size(); ++i){ 
      nums[n[i]]=i;
    }
    for (int i =0; i  < 5 ; ++i){ 
      rows[i]=cols[i]=0;
    }
  }

  int hit(int x) {
    cout << x<<" ";
    auto it = nums.find(x);
    if (it != nums.end()){
      int p = it->second;
    cout << p<<endl;
      nums.erase(it);
      bool a =++rows[p/5] == 5, b =++cols[p%5] == 5;
    for (int i =0; i  < 5 ; ++i){ 
      cout << rows[i];
    }
    cout << endl;
    for (int i =0; i  < 5 ; ++i){ 
      cout << cols[i];
    }
    cout << endl;
      
      if( a|| b) {
      int sum =0;
      for (auto itt = nums.begin(); itt != nums.end(); ++itt){
        sum+=itt->first;
      }
      return x*sum;
      }
    }
    cout << endl;
    return -1;
  }
};
    
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
  string hits;
  cin >> hits;
    vector<BingoBoard*> boards;
  vector <int> board(25);
  int x, i;
  while(cin >> x){
    board[i++] = x;
    if (i == 25) {
      i = 0;
      boards.push_back(new BingoBoard(board));
    }
  }
  
  vector<string> h = split(hits, ",");
  for (auto it : h) {
    int hit = stoi(it);
    for (auto itt : boards){
      int s = itt->hit(hit);
      if (s!=-1){ cout << s<<",!" << endl; return 0;}
    }

  }

}
