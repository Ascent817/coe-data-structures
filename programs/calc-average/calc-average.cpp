#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  freopen("numbersIn.txt", "r", stdin);

  vector<float> numbers;

  while (!cin.eof()) {
    float number;
    cin >> number;
    numbers.push_back(number);
  }

  float sum = 0;
  for (float number : numbers) {
    sum += number;
  }
  float average = sum / numbers.size();

  cout << "The average is: " << average << endl;
  
  return 0;
}