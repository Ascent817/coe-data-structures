#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

namespace util {

/**
 * @brief Prints a formatted table to the given output stream.
 *
 * This function takes a vector of headers and a 2D vector of data, and prints
 * a formatted table to the specified output stream. The table includes borders
 * and aligns the text within each column.
 *
 * @param headers A vector of strings representing the column headers.
 * @param data A 2D vector of strings representing the table data.
 * @param out The output stream to which the table will be printed.
 * @return Returns 0 on success, 1 if the data is empty or if the number of columns
 *         in the headers and data do not match.
 */
int printTable(vector<string> headers, vector<vector<string>> data, ostream &out) {
  int n = headers.size();

  // Check if data is empty
  if (data.empty()) {
    return 1;
  }

  // Check if the number of columns in the header and data match
  if (n != data[0].size()) {
    return 1;
  }

  vector<int> colWidths;
  colWidths.reserve(n);
  colWidths.assign(n, 0);

  // Find the maximum width of each column
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
}  // namespace util