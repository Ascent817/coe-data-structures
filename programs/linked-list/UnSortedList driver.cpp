#include <iostream>

#include "UnSorted.h"

using namespace std;

int main() {
  UnSortedType<int> list;
  int x;
  bool found;

  for (int i = 0; i < 10; i++) {
    list.InsertItem(i);
  }

  return 0;
}
