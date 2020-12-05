#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int findTrees(vector<string> course, int right, int down);

int main() {

  // vector of strings to represent course
  vector<string> courseVec;
  string line;
  ifstream inputFile("aocday3_1data.txt");

  // build the course in the vector
  while(getline(inputFile, line)) {
    courseVec.push_back(line);
  }

  inputFile.close();

  int first = findTrees(courseVec, 1, 1);
  int second = findTrees(courseVec, 3, 1);
  int third = findTrees(courseVec, 5, 1);
  int fourth = findTrees(courseVec, 7, 1);
  int fifth = findTrees(courseVec, 1, 2);

  int multiTotal = first * second * third * fourth * fifth;

  cout << "The number of trees in the course is (Right 1, Down 1): " << first << endl;
  cout << "The number of trees in the course is (Right 3, Down 1): " << second << endl;
  cout << "The number of trees in the course is (Right 5, Down 1): " << third << endl;
  cout << "The number of trees in the course is (Right 7, Down 1): " << fourth << endl;
  cout << "The number of trees in the course is (Right 1, Down 2): " << fifth << endl;
  cout << endl;
  cout << "Multiplied together that is: " << multiTotal << endl;

  return 0;
}

// find number of trees on a given path of right and down coordinates
int findTrees(vector<string> course, int right, int down) {
  // check every row, but traverse certain num columns every iteration
  unsigned int row = down % course.size();
  unsigned int column = right % course[row].size();
  // keep track of how many trees we hit
  int trees = 0;

  // until we hit the bottom of the course
  while(row < course.size()) {
    // if the current index is a tree
    if(course[row][column] == '#') {
      trees++;
    }
    // traverse along the path
    row += down;
    // because the course repeats, we can use the mod function to wrap around to the beginning
    column = (column + right) % course[row].size();
  }
  // return our total
  return trees;
}