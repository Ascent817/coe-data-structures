#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int printTable(vector<string> headers, vector<vector<string>> data, ostream &out) {
  int n = headers.size();

  if (n != data[0].size()) {
    return 1;
  }

  vector<int> colWidths(n, 0);

  for (int i = 0; i < n; i++) {
    colWidths[i] = headers[i].length();
    for (int j = 0; j < data.size(); j++) {
      if (data[j][i].length() > colWidths[i]) {
        colWidths[i] = data[j][i].length();
      }
    }
  }

  // Table header
  out << "┌";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < colWidths[i] + 2; j++) {
      out << "─";
    }
    if (i < n - 1) {
      out << "┬";
    }
  }

  out << "┐" << endl;

  out << "│";

  for (int i = 0; i < n; i++) {
    out << " " << setw(colWidths[i]) << left << headers[i] << " ";
    if (i < n - 1) {
      out << "│";
    }
  }

  out << "│" << endl;

  // Table separator
  string separator = "├";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < colWidths[i] + 2; j++) {
      separator += "─";
    }

    if (i < n - 1) {
      separator += "┼";
    }
  }

  separator += "┤";

  // Table data
  for (int i = 0; i < data.size(); i++) {
    out << separator << endl;

    out << "│";

    for (int j = 0; j < n; j++) {
      out << " " << setw(colWidths[j]) << left << data[i][j] << " ";
      if (j < n - 1) {
        out << "│";
      }
    }

    out << "│" << endl;
  }

  // Table end
  out << "└";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < colWidths[i] + 2; j++) {
      out << "─";
    }
    if (i < n - 1) {
      out << "┴";
    }
  }

  out << "┘" << endl;

  return 0;
}