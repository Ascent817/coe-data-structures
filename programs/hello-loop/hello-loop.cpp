#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

const int MAX = 3;

int main() {
  // Sum the first 10 integers
  int isum = 0;
  for (int i = 1; i <= 10; i++) {
    isum += i;
  }

  cout << "Sum: " << isum << '\n';

  // Use different loops, receive n, number of user defined floats, output sum and average
  int n;
  cin >> n;
  float arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  float fsum = accumulate(arr, arr + n, 0.0f);

  cout << "Sum: " << fsum << '\n';
  cout << "Average: " << fsum / n << '\n';
}