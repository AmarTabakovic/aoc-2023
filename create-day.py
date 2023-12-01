import os
import sys

MAKEFILE_CONTENT = 'all:\n\tg++ -std=c++14 main.cpp -o main -Ofast\n'
MAIN_CONTENT = """#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

vector<string> buffer;

int part1() {
  return 0;
}

int part2() {
  return 0;
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
"""
GITIGNORE_CONTENT = 'main\n'

if len(sys.argv) != 2:
    print('Please enter the day.')
    exit(1)

day_nr = None

try:
    day_nr = int(sys.argv[1])
except ValueError:
    print('Not a number.')
    exit(1)

# Day exceeds 25
if (day_nr > 25):
    print('Cannot go beyond the 25th day.')
    exit(1)

# Create the day directory
try:
    day_dir = f'day-{day_nr:02d}'
    os.mkdir(day_dir)
except OSError as error:
    print(error)
    exit(1)

# Create main.cpp
with open(f'{day_dir}/main.cpp', 'w') as file:
    file.write(MAIN_CONTENT)

# Create Makefile
with open(f'{day_dir}/Makefile', 'w') as file:
    file.write(MAKEFILE_CONTENT)

# Create .gitignore
with open(f'{day_dir}/.gitignore', 'w') as file:
    file.write(GITIGNORE_CONTENT)

print(f'Successfully created day {day_nr}')
