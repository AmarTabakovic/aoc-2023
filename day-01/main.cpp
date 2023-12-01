#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

vector<string> buffer;

int part1() {
  int sum = 0;

  for (auto s : buffer) {
    int first = -1, last = -1;
    for (auto c : s) {
      if (c >= '0' && c <= '9') {
        if (first == -1) first = c - '0';
        last = c - '0'; 
      }
    }
    if (first == -1) continue; // Skip lines without digits
    if (last == -1) last = first; // Line with single digit
    sum += 10 * first + last;
  } 
  return sum;
}

int part2 () { 
  int sum = 0;
  vector<string> nums = {"one", "two", "three", "four", "five", 
                         "six", "seven", "eight", "nine"};

  for (auto s : buffer) {
    int first = -1, last = -1;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (c >= '0' && c <= '9') {
        if (first == -1) first = c - '0';
        last = c - '0'; 
      } else {
        int toSet = -1;
        // pretty inefficient but I don't care at the moment
        for (int j = 1; j <= 9; j++) {
          string currN = nums[j - 1];
          if (i + currN.size() <= s.size() && s.substr(i, currN.size()) == currN) {
            toSet = j;
            break;
          }
        }
        if (toSet != -1) {
          if (first == -1) first = toSet;
          last = toSet;
        }
      }
    }
    if (first == -1) continue; // Skip lines without digits
    sum += 10 * first + last;
  } 
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  
  ifstream myfile("input");
  string line;

  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      buffer.push_back(line);
    }
    myfile.close();
  }

  cout << part1() << endl;
  cout << part2() << endl;

  return 0;
}
