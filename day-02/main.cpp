#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <sstream>
#include <cstdio>

using namespace std;

vector<string> buffer;

int part1() {
  int sum = 0;
  
  for (int i = 0; i < buffer.size(); i++) {
    string s = buffer[i];
    if (s == "") break;

    int start = 0;
    while (s[start] != ':') start++;
    start++;
    
    // Remove "Game x:" from string
    string s1 = s.substr(start, s.size() - start);
    string round;
    stringstream ss1(s1);

    bool possible = true;
    while (getline(ss1, round, ';')) {
      if (!possible) break;

      string cube;
      stringstream ssround(round);
      while (getline(ssround, cube, ',')) {
        // Remove whitespace at beginning of string 
        cube = cube.substr(1, cube.size() - 1);
        int n = 0;
        char color[5];
        sscanf(cube.c_str(), "%d %s", &n, color);
        string color1(color);

        if (color1 == "red"   && n > 12 ||
            color1 == "green" && n > 13 ||
            color1 == "blue"  && n > 14) {
          possible = false; break;
        }
      }
    }
    if (possible) sum += i + 1;
  }
  return sum;
}
 
int part2() {
  int sum = 0;
  
  for (int i = 0; i < buffer.size(); i++) {
    string s = buffer[i];
    if (s == "") break;

    int start = 0;
    while (s[start] != ':') start++;
    start++;
    
    // Remove "Game x:" from string
    string s1 = s.substr(start, s.size() - start);
    string round;
    stringstream ss1(s1);

    int maxRed = 0, maxGreen = 0, maxBlue = 0;
    while (getline(ss1, round, ';')) {
      string cube;
      stringstream ssround(round);
      while (getline(ssround, cube, ',')) {
        // Remove whitespace at beginning of string 
        cube = cube.substr(1, cube.size() - 1);
        int n = 0;
        char color[5];
        sscanf(cube.c_str(), "%d %s", &n, color);
        string color1(color);
        if (color1 == "red") maxRed = max(n, maxRed);
        if (color1 == "green") maxGreen = max(n, maxGreen);
        if (color1 == "blue") maxBlue = max(n, maxBlue);
      }
    }
    sum += maxRed * maxGreen * maxBlue;
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
