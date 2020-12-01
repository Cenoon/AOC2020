#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;

void findPairs(vector<double> data, int vec_size, int sum) {
  unordered_set<double> s;
  for (int i = 0; i < vec_size; i++) {
      int temp = sum - data[i];

      if (s.find(temp) != s.end()) {
        cout << "Pair with given sum " << sum << " is (" << data[i] << ", " << temp << ")" << endl;
        cout << "Multiplying them gives us: " << data[i] * temp << endl;
      }
      s.insert(data[i]);
  }
}

int main() {
  // insert dataset to vector here
  vector<double> dataSet;
  ifstream inputFile("aocday1_1data.txt");

  double currNum;
  while(inputFile >> currNum) {
    dataSet.push_back(currNum);
  }

  inputFile.close();

  // sum size here
  int n = 2020;
  int vec_size = dataSet.size();

  // call findPairs to get our pairs
  findPairs(dataSet, vec_size, n);

  return 0;
}