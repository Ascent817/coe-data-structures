#include <time.h>

#include <iostream>

#include "UnSorted.h"

using namespace std;

int main() {
  srand((unsigned int)time(0));  // set the random number generator seed
  // srand(1);    // set the random number generator seed

  UnSortedType<int> list;
  int x;
  bool found = true;

  for (int i = 1; i <= 100; i++) {
    list.InsertItem(1 + rand() % 100);  // generate a random number
  }

  int maximum = -INT32_MAX;
  list.ResetList();
  while (list.AtEnd() == false) {
    list.GetNextItem(x);
    maximum = max(maximum, x);
  }

  cout << "Maximum: " << maximum << endl;

  list.DeleteItem(maximum);

  list.ResetList();
  while (list.AtEnd() == false) {
    list.GetNextItem(x);
    cout << x << " ";
  }

  return 0;
}