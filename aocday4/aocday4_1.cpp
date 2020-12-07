#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  // use a map to store passport entries
  unordered_map<string, string> passportEntries;
  string key;
  string value;

  ifstream inputFile("aocday4_1data.txt");
  string currentLine;
  int validPassports = 0;

  while(getline(inputFile, currentLine)) {
    // if we read a newline only
    if(currentLine == "") {
      // no data is on this line, start of new passport
      // if there are 7 valid fields (CID is irrelevant)
      if(passportEntries.find("byr") != passportEntries.end() && passportEntries.find("iyr") != passportEntries.end()
        && passportEntries.find("eyr") != passportEntries.end() && passportEntries.find("hgt") != passportEntries.end()
        && passportEntries.find("hcl") != passportEntries.end() && passportEntries.find("ecl") != passportEntries.end()
        && passportEntries.find("pid") != passportEntries.end()) {
        // increment validPassports
        validPassports++;
      }
      // reset passport entry
      passportEntries.clear();
    }
    else {
      unsigned endKey = 0;
      unsigned valueChar = 0;
      while(valueChar < currentLine.length()) {
        // get the key (delimited by :)
        for(unsigned i = valueChar; currentLine[i] != ':'; i++) {
          key += currentLine[i];
          // start the value at i + 2 (skip the :)
          endKey = i + 2;
        }
        valueChar = endKey;
        // get the value with this key (space/line seperated from next entry)
        while(currentLine[valueChar] != '\0') {
          if(currentLine[valueChar] == ' ') {
            valueChar++;
            break;
          }
          value += currentLine[valueChar];
          valueChar++;
        }
        // put this key/value into the map
        passportEntries[key] = value;
        // reset key and value
        key = "";
        value = "";
      }
    }
  }

  inputFile.close();

  cout << "The number of valid passports is: " << validPassports << endl;

  return 0;
}