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


int main(){
  string s;
  vector <long long int> scores;
  while(cin >> s) {
    stack<char> st;
    bool good = true;
    for (char c : s) {
      if (c == '(' || c == '[' || c == '{' || c == '<') {
        st.push(c);
      } else {
        char cc = st.top();
        st.pop();
        if (c == ')' && cc != '(') {
          good = false;
          break;
        } else if (c == ']' && cc != '[') {
          good = false;
          break;
        } else if (c == '}' && cc != '{') {
          good = false;
          break;
        } else if (c == '>' && cc != '<') {
          good = false;
          break;
        }
      }
    }
    if (good) {
      long long int score = 0;
      while(!st.empty()) {
        char c = st.top();
        st.pop();
        score *=5;
        switch (c) {
          case '(':
            score +=1;
            break;
          case '[':
            score +=2;
            break;
          case '{':
            score +=3;
            break;
          case '<':
            score +=4;
            break;
          default:
            break;
        }
      }
      cout << score << endl;
      scores.push_back(score);
    }
  }
  sort(scores.begin(), scores.end());
  cout << scores[scores.size()/2] << endl;
}


