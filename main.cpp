#include <bits/stdc++.h>
using namespace std;

const string types[18] = {"normal",  "fire",     "water",  "electric", "grass",
                          "ice",     "fighting", "poison", "ground",   "flying",
                          "psychic", "bug",      "rock",   "ghost",    "dragon",
                          "dark",    "steel",    "fairy"};

vector<float> effect(18, 1);

float chart[18][18];

int ttoi(string type) {

  for (int i = 0; i < 18; ++i) {
    if (type.substr(0, 3) == types[i].substr(0, 3)) {
      return i;
    }
  }

  return -1;
}

void mutate(int type, vector<float> &curr) {

  for (int i = 0; i < 18; ++i) {
    curr[i] *= chart[type][i];
  }
}

void mut(vector<int> type, vector<float> &out) {

  for (int i = 0; i < type.size(); ++i) {
    for (int j = 0; j < 15; ++j) {
      out[j] *= chart[type[i]][j];
    }
  }
}

int main() {

  ifstream f;
  f.open("typechartgen1.txt");
  for (int i = 0; i < 15; ++i) {
    for (int j = 0; j < 15; ++j) {
      f >> chart[i][j]; // def, atk
    }
  }

  vector<int> combo;

  string temp;
  int curr;

  while (true) {
    cin >> temp;
    curr = ttoi(temp);
    if (curr < 0)
      break;
    combo.push_back(curr);
  }

  for (int i = 0; i < combo.size(); ++i) {
    mutate(combo[i], effect);
  }

  for (int i = 0; i < 18; ++i) {
    cout << types[i] << ' ' << effect[i] << '\n';
  }
}
