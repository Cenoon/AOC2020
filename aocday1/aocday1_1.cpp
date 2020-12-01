#include <iostream>
#include <unordered_set>
using namespace std;

void printPairs(int arr[], int arr_size, int sum) {
  unordered_set<int> s;
  for (int i = 0; i < arr_size; i++) {
      int temp = sum - arr[i];

      if (s.find(temp) != s.end()) {
        cout << "Pair with given sum " << sum << " is (" << arr[i] << ", " << temp << ")" << endl;
        cout << "Multiplying them gives us: " << arr[i] * temp << endl;
      }
      s.insert(arr[i]);
  }
}

int main() {
  // insert dataset here
  int dataSet[] = { 1, 4, 45, 6, 10, 8 };
  // sum size here
  int n = 2020;
  int arr_size = sizeof(dataSet) / sizeof(dataSet[0]);

  // Function calling
  printPairs(dataSet, arr_size, n);

  return 0;
}