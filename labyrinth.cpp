#include <bits/stdc++.h>
using namespace std;

int rows, cols;
vector<pair<int, int>> results;
vector<string> maze;

pair<int, int> pos;
pair<int, int> posA = {-1, -1};
pair<int, int> posB = {-1, -1};

pair<int, int> left(pair<int, int> pos) {
  pos.second--;
  return pos;
}

pair<int, int> right(pair<int, int> pos) {
  pos.second++;
  return pos;
}

pair<int, int> up(pair<int, int> pos) {
  pos.first--;
  return pos;
}

pair<int, int> down(pair<int, int> pos) {
  pos.first++;
  return pos;
}

bool pQ (pair<int, int> pos){ // Pinghua Qeng or Ping Qian
  if(pos.first < 0 || pos.first >= rows) {
    return false;
  }
  if(pos.second < 0 || pos.second >= cols) {
    return false;
  }
  else return true;
}

bool pT(pair<int, int> pos, vector<string> &maze) { // Partido del trabajo
  if ((maze)[pos.first][pos.second] == '0') {
    return false;
  }
  return true;
}

bool pC(pair<int, int> pos, set<pair<int, int>> &visited) { // phris cratt
  return visited.find(pos) != visited.end();
}

void dfs(pair<int, int> pos, vector<string> &maze, set<pair<int, int>> &visited) { // depth first search
  if (!pQ(pos)) {
    return;
  }
  if (!pT(pos, maze)) {
    return;
  }
  if (pC(pos, visited)) {
    return;
  }

  visited.insert(pos);
  results.push_back(pos);

  dfs(left(pos), maze, visited);
  dfs(right(pos), maze, visited);
  dfs(up(pos), maze, visited);
  dfs(down(pos), maze, visited);
}

void pD() { // pynamic drogramming
  string fileName = "/laberintos/laberinto_1.in";
  ifstream fin(fileName);

  string line;

  fin >> rows;
  fin >> cols;
  cout << "The file has " << rows << " rows and " << cols << " columns" << endl;

  for (int i = 0; i < rows; i++) {
    fin >> line;
    maze.push_back(line);
  }
  
  for (int i = 0; i < maze.size(); i++) {
    if (maze[i].find('A') != string::npos) {
      posA.first = i;
      posA.second = maze[i].find('A');
    }
    if (maze[i].find('B') != string::npos) {
      posB.first = i;
      posB.second = maze[i].find('B');
    }
  }
  pos = posA;


  for (auto row : maze) {
    cout << row << endl;
  }
}

void bfs() {
  
}

int main () {
  //implementation of pynamic drogramming (🔥)

  set<pair<int, int>> visited;
  pD();

  dfs(posA, maze, visited);
  for (auto pos : results) {
    cout << "(" << pos.first << ", " << pos.second << ")" << endl;
  };
  results.clear();
}