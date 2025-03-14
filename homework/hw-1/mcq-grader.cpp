// Student: Varun Pradeep
// Class: CS135 Data Structures, Spring 2025
// Instructor: Terry Hostetler
// TODO: Email to Tyler Van Atta

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Result {
  double score;
  int correct;
  int incorrect;
  int blank;
};

struct Student {
  string name;
  string ans;
  Result result;
};

Student getStudentData(ifstream &ansFile, vector<Student> &students);
Result scoreTest(string ans, string key);
int printTable(vector<string> headers, vector<vector<string>> data, ostream &out);

int main() {
  // Open the key and answer files
  ifstream keyFile;
  ifstream ansFile;

  keyFile.open("hw1Key.txt");
  ansFile.open("hw1Ans.txt");

  string key;
  keyFile >> key;

  // Read student data
  vector<Student> students;

  while (!ansFile.eof()) {
    students.push_back(getStudentData(ansFile, students));
  }

  // Score the test
  for (int i = 0; i < students.size(); i++) {
    students[i].result = scoreTest(students[i].ans, key);
  }

  // Calculate the total score and percentage for each student and convert the data to strings
  vector<vector<string>> studentData;

  for (int i = 0; i < students.size(); i++) {
    int total = students[i].result.correct + students[i].result.incorrect + students[i].result.blank;

    studentData.push_back({
        students[i].name,
        to_string(students[i].result.correct),
        to_string(students[i].result.incorrect),
        to_string(students[i].result.blank),
        to_string(students[i].result.score).substr(0, 5),
        to_string(((students[i].result.score / total * 100))).substr(0, 5),
    });
  }

  // Open the output file and print the table
  ofstream out;
  out.open("hw1Out.txt");

  printTable({"Name", "Correct", "Incorrect", "Blank", "Total Score", "%"}, studentData, out);
  printTable({"Name", "Correct", "Incorrect", "Blank", "Total Score", "%"}, studentData, cout);  // TODO: Remove for final submission

  return 0;
}

Student getStudentData(ifstream &ansFile, vector<Student> &students) {
  string name, ans;
  ansFile >> name >> ans;
  return {name, ans, {0.0, 0, 0, 0}};
}

Result scoreTest(string ans, string key) {
  double score = 0.0;
  int correct = 0;
  int incorrect = 0;
  int blank = 0;

  for (int i = 0; i < key.length(); i++) {
    if (ans[i] == '#') {
      blank++;
      continue;
    }

    if (ans[i] == key[i]) {
      correct++;
      score += 1.0;
    } else {
      incorrect++;
      score -= 0.25;
    }
  }
  return {score, correct, incorrect, blank};
}

int printTable(vector<string> headers, vector<vector<string>> data, ostream &out) {
  int n = headers.size();

  // Check if data is empty
  if (data.empty()) {
    return -1;
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