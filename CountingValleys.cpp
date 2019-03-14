#include <bits/stdc++.h>

using namespace std;

//My code
//My score for this challenge is 9/15.
int countingValleys(int n, string s) {
int level = 0;
int valley = 0;
bool prev;
bool curn;


if (n > 1000000) {
    return 0;
}
if (s[0] == 'D') {
    level--;
    }
if (s[0] == 'U') {
  level++;
}
if (level > 0) {
    prev = true;
}
if (level < 0) {
    prev = false;
}
s = s.substr(1, s.length()-1);

    while (!s.empty()) {
      if (s[0] == 'D') {
        level--;
      }
      if (s[0] == 'U') {
        level++;
      }
      if (level >= 0) {
          curn = true;
      }
      if (level < 0) {
          curn = false;
      }
      if (prev == false && curn == true) {
          valley++;
      }
      prev = curn;
      s = s.substr(1);
      if (level > n/2 || level*(-1) > n/2) {
          return 0;
      }
    }


return valley;
}

//HakerRank's code
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
