#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int dualOutput(ofstream &file, string outputs[]) {
  for (int i = 0; i < 3; i++) {
    file << outputs[i] << '\n';
    cout << outputs[i] << '\n';
  }
  return 0;
}

int main() {
  freopen("Name3xIn.txt", "r", stdin);
  ofstream file("nameOut.txt");
  
  for (int i = 0; i < 3; i++) {
    string f, m, l;
    string mi;

    cin >> f >> m >> l;

    mi = m.substr(0, 1) + '.';

    string outputs[] = {f + ' ' + m + ' ' + l, l + ", " + f + ' ' + m, f + ' ' + mi + ' ' + l};
    dualOutput(file, outputs);
  }
  
  return 0;
}