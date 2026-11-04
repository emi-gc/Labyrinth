#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void left(pair<int, int>* pos) {
  pos->second-1;
}
void right(pair<int, int>* pos) {
  pos->second+1;
}
void up(pair<int, int>* pos) {
  pos->first+1;
}
void down(pair<int, int>* pos) {
  pos->first-1;
}

int main () {
  string fileName = "/laberintos/laberinto_1.in";
  ifstream fin(fileName);

  int rows, cols;
  string line;

  fin >> rows;
  fin >> cols;
  cout << "The file has " << rows << " rows and " << cols << " columns" << endl;

  vector<string> maze;

  pair<int, int> posA, posB, pos;
  
  for (int i = 0; i < rows; i++) {
    fin >> line;
    maze.push_back(line);
  }
  
  for (int i = 0; i < maze.size(); i++) {
    if (maze[i].find('A')) {
      posA.first = i;
      posA.second = maze[i].find('A');
    }
    if (maze[i].find('B')) {
      posB.first = i;
      posB.second = maze[i].find('B');
    }
  }
  pos = posA;


  for (auto row : maze) {
    cout << row << endl;
  }



}