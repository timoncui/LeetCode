/*
Author: Timon Cui, timonbaby@163.com

Title: Simplify Path

Description:

Difficulty rating: Easy

Notes:

*/

class Solution {
public:
  string simplifyPath(string path) {
    deque<string> Q;
    int pos = path.find('/');
    while (pos + 1 < path.size()) {
      int new_pos = path.find('/', pos + 1);
      if (new_pos == string::npos) new_pos = path.size();
      string p = path.substr(pos + 1, new_pos - pos - 1);
      pos = new_pos;
      if (p.size()) {
	if (p == "..") {
	  if (!Q.empty()) Q.pop_back();
	}
	else if (p == ".") continue;
	else Q.push_back(p);
      }
    }
    string res = "";
    while (!Q.empty()) {
      res += "/" + Q.front();
      Q.pop_front();
    }
    return res.size() ? res : "/";
  }
};
