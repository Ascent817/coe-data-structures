#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  char inChar;
  ifstream inFile;
  ofstream dashes1;
  ofstream dashes2;
  ofstream dashes3;

  inFile.open("miscBa.txt");
  dashes1.open("dashes1.txt");
  dashes2.open("dashes2.txt");
  dashes3.open("dashes3.txt");

  if (!inFile) {
    cout << "Unable to open file";
    return 1;
  }

  // // Replace spaces with dashes in the first line
  // while (inChar != '\n') {
  //   if (inChar == ' ') {
  //     dashes1 << '-';
  //   } else {
  //     dashes1 << inChar;
  //   }
  //   inFile.get(inChar);
  // }

  // // Replace spaces with dashes in the file
  // inFile.get(inChar);
  // while (!inFile.eof()) {
  //   while (inChar != '\n') {
  //     if (inChar == ' ') {
  //       dashes2 << '-';
  //     } else {
  //       dashes2 << inChar;
  //     }
  //     inFile.get(inChar);
  //   }
  //   inFile.get(inChar);
  //   dashes2 << endl;
  // }

  // Replace spaces with dashes in the first sentence
  while (inChar != '.' && inChar != '?' && inChar != '!') {
    if (inChar == ' ') {
      dashes3 << '-';
    } else {
      dashes3 << inChar;
    }
    inFile.get(inChar);
  }
  dashes3 << '.';

  return 0;
}