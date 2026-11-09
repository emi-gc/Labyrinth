#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    pair<int, int> value;
    Node *parent;
    vector<Node*> children;

    Node(pair<int, int> v) {
        parent = nullptr;
        value = v;
    }

    Node *add_child(Node* n) {
        n->parent = this;
        children.push_back(n);
        return n;
    }

    vector<Node*>* ancestros(Node* root) {
        vector<Node*>* r = new vector<Node*>;
        Node *dora = this;
        while (dora != root) {
            r->push_back(dora);
            dora = dora->parent;
            if (dora == nullptr) {
                return nullptr;
            }
        }
        r->push_back(dora);
        return r;
    }


    int depth(Node* root) {
        vector<Node*> r; 
        Node* dora = this;
        while (dora != root) {
            r.push_back(dora);
            dora = dora->parent;
            if (dora == nullptr) {
                return -1; 
            }
        }
        r.push_back(dora);
        return (r.size() - 1);
    }


     int size() {
        int r=1;
    for (auto c: children) {
        r+=c->size();
    }
    return r;
    }

    int height() {
    int r=0;
    for (auto x: children) {
        r = max(r, x->height() + 1);
    }
    return r;
}

};


int rows, cols;
vector<pair<int, int>> resultsDFS;
vector<pair<int, int>> resultsPost;
vector<pair<int, int>> resultsBFS;
vector<pair<int, int>> solutionBFS;
vector<pair<int, int>> solutionDFS;
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
  resultsDFS.push_back(pos);

  dfs(down(pos), maze, visited);
  dfs(left(pos), maze, visited);
  dfs(up(pos), maze, visited);
  dfs(right(pos), maze, visited);

  resultsPost.push_back(pos);
}

void bfs(pair<int, int> pos, vector<string> &maze, set<pair<int, int>> &visited) {
  queue<pair<int, int>> q;
  q.push(pos);
  while (!q.empty()) {
    pair<int, int> current = q.front();
    q.pop();

    if (!pQ(current)) {
      continue;
    }
    if (!pT(current, maze)) {
      continue;
    }
    if (pC(current, visited)) {
      continue;
    }

    visited.insert(current);
    resultsBFS.push_back(current);

    q.push(down(current));
    q.push(left(current));
    q.push(up(current));
    q.push(right(current));
  }
}

void pD() { // pynamic drogramming
  string fileName = "laberintos/laberinto_1.in";
  ifstream fin(fileName);

  if (!fin.is_open()) {
    cout << "Error: Could not open " << fileName << endl;
    return;
  }
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



int main () {
  //implementation of pynamic drogramming (🔥)

  set<pair<int, int>> visited;
  pD();

  dfs(posA, maze, visited);
  cout << "DFS:" << endl;
  for (auto pos : resultsDFS) {
    cout << "(" << pos.first << ", " << pos.second << ")" << endl;
  };
  cout << "Postorder:" << endl;
    for (auto pos : resultsPost) {
    cout << "(" << pos.first << ", " << pos.second << ")" << endl;
  };
  cout << "BFS:" << endl;
  visited.clear();
  bfs(posA, maze, visited);
  for (auto pos : resultsBFS) {
    cout << "(" << pos.first << ", " << pos.second << ")" << endl;
  };
}