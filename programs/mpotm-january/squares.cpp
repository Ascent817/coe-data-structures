#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

#pragma region Point
struct Point {
  int x, y;
};

Point operator+(const Point& a, const Point& b) {
  return {a.x + b.x, a.y + b.y};
}

Point operator-(const Point& a, const Point& b) {
  return {a.x - b.x, a.y - b.y};
}

bool operator==(const Point& a, const Point& b) {
  return a.x == b.x && a.y == b.y;
}

bool operator!=(const Point& a, const Point& b) {
  return !(a == b);
}
#pragma endregion

struct Square {
  Point a, b, c, d;
};

bool operator==(const Square& s1, const Square& s2) {
  return s1.a == s2.a && s1.b == s2.b && s1.c == s2.c && s1.d == s2.d;
}

int main() {
  const int N = 20;
  Point points[N] = {{0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {4, 2}, {4, 3}, {5, 2}, {5, 3}};

  set<Square> squares;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // Try to create a square given first two points. Squares are constructed clockwise.
      Point a = points[i];
      Point b = points[j];
    }
  }
}