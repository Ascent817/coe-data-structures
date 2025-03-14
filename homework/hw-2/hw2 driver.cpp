#include <fstream>
#include <iostream>

using namespace std;

#include "hw2 unsortedType.h"

int main() {
  int a = 9, b = 5, c = 7, d = 2, e = 6, f = 4, g = 8;
  UnsortedType<int> list1, list2, list3;

  list1.InsertItem(a);
  list1.InsertItem(b);
  list1.InsertItem(c);
  cout << "list1 = ";
  list1.Print(cout);

  list2.InsertItem(d);
  list2.InsertItem(e);
  list2.InsertItem(f);
  list2.InsertItem(g);
  cout << "list2 = ";
  list2.Print(cout);

  list3 = list1.Merge(list2);
  cout << "list1 = ";
  list1.Print(cout);
  cout << "list2 = ";
  list2.Print(cout);
  cout << "list3 = ";
  list3.Print(cout);

  list3.Split(b, list1, list2);
  cout << "list1 = ";
  list1.Print(cout);
  cout << "list2 = ";
  list2.Print(cout);
  cout << "list3 = ";
  list3.Print(cout);

  return 0;
}
