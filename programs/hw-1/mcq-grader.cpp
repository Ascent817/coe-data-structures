// Student: Varun Pradeep
// Class: CS135 Data Structures, Spring 2025
// Instructor: Terry Hostetler
// TODO: Email to Tyler Van Atta

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "./table.cpp"

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

struct Student {
  string name;
  string ans;
  double score;
  int correct;
  int incorrect;
  int blank;
};

struct Result {
  double score;
  int correct;
  int incorrect;
  int blank;
};

Student getStudentData(ifstream &ansFile, vector<Student> &students);
Result scoreTest(string ans, string key);
void printResults(vector<Student> students);

int main() {
  ifstream keyFile;
  ifstream ansFile;

  keyFile.open("hw1Key.txt");
  ansFile.open("hw1Ans.txt");

  string key;
  keyFile >> key;

  vector<Student> students;

  while (!ansFile.eof()) {
    students.push_back(getStudentData(ansFile, students));
  }

  for (int i = 0; i < students.size(); i++) {
    Result result = scoreTest(students[i].ans, key);
    students[i].score = result.score;
    students[i].correct = result.correct;
    students[i].incorrect = result.incorrect;
    students[i].blank = result.blank;
  }

  printResults(students);

  vector<vector<string>> studentData;

  for (int i = 0; i < students.size(); i++) {
    int total = students[i].correct + students[i].incorrect + students[i].blank;

    studentData.push_back({
        students[i].name,
        to_string(students[i].correct),
        to_string(students[i].incorrect),
        to_string(students[i].blank),
        to_string((students[i].score * 100) / 100.0).substr(0, 4),
        to_string(((students[i].score / total * 100))).substr(0, 4),
    });
  }

  ofstream out;
  out.open("hw1Out.txt");

  printTable({"Name", "Correct", "Incorrect", "Blank", "Total Score", "%"}, studentData, out);

  return 0;
}

Student getStudentData(ifstream &ansFile, vector<Student> &students) {
  string name, ans;
  ansFile >> name >> ans;
  return {name, ans, 0.0, 0, 0, 0};
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

void printResults(vector<Student> students) {
  ofstream out;
  out.open("hw1Out.txt");

  out << "   Name      Correct   Incorrect   Blank   Total Score     %  \n";
  out << "----------   -------   ---------   -----   -----------   -----\n";

  // 2 decimal places
  out << fixed;
  out.precision(2);

  for (int i = 0; i < students.size(); i++) {
    out << students[i].name << " " << students[i].score << "\n";
  }
}