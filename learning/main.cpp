#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n = 5;
  float sum = 0;

  float minGrade, maxGrade;
  minGrade = INT32_MAX;
  maxGrade = -INT32_MAX;

  for (int i = 0; i < n; i++) {
    float grade;
    cin >> grade;
    minGrade = min(grade, minGrade);
    maxGrade = max(grade, maxGrade);
    sum += grade;
  }

  cout << "Average: " << sum / n << endl;
  cout << "Min: " << minGrade << endl;
  cout << "Max: " << maxGrade << endl;
}