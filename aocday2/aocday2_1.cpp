#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// struct to hold password policy data
struct passwordPolicy {
  int lowNum;
  int highNum;
  char character;
  string password;
};

int validPass1(vector<passwordPolicy> passVect);
int validPass2(vector<passwordPolicy> passVect);

int main() {
  // insert dataset to vector here
  vector<passwordPolicy> dataSet;
  ifstream inputFile("aocday2_1data.txt");

  // create temp variables for data components
  int lowNum = 0;
  int highNum = 0;
  char character = ' ';
  string password = "";

  while(inputFile >> lowNum) {

    // parse the input file lines for password policy data, input to data vector
    inputFile.ignore(256, '-');
    inputFile >> highNum;
    inputFile.ignore(256, ' ');
    inputFile >> character;
    inputFile.ignore(256, ' ');
    inputFile >> password;

    passwordPolicy currPassword;
    currPassword.lowNum = lowNum;
    currPassword.highNum = highNum;
    currPassword.character = character;
    currPassword.password = password;

    dataSet.push_back(currPassword);
  }

  inputFile.close();

  // parse the data for num valid passwords
  cout << "The number of valid passwords (Part 1) is: " << validPass1(dataSet) << endl;
  cout << "The number of valid passwords (Part 2) is: " << validPass2(dataSet) << endl;

  return 0;
}

int validPass1(vector<passwordPolicy> passVect) {
  // var for total valid
  int valid = 0;

  for(unsigned int i = 0; i < passVect.size(); i++) {
    // how many times char occurs in password
    int numChar = 0;
    // current password
    string currPass = passVect[i].password;
    // lower and upper bound
    int lowBound = passVect[i].lowNum;
    int upperBound = passVect[i].highNum;

    // iterate over the password
    for (char const &c: currPass) {
      // if the character matches add to numChar
      if(c == passVect[i].character) {
        numChar++;
      }
      // if we go over upperbound, end early
      if(numChar > upperBound) {
        break;
      }
    }
    // if we are within bounds, increment valid
    if(numChar >= lowBound && numChar <= upperBound) {
      valid++;
    }
  }

  return valid;
}

int validPass2(vector<passwordPolicy> passVect) {
  
}