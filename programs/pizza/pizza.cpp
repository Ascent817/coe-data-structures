#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

enum Size {
  SMALL,
  MEDIUM,
  LARGE
};

enum Topping {
  ANCHOVIES,
  MUSHROOMS,
  SAUSAGE,
  PEPPERONI,
  ONIONS
};

enum Crust {
  THIN,
  THICK,
  STUFFED
};

struct Pizza {
  Size size;
  Topping topping;
  Crust crust;
  double price;
};

void GetPizzaOrder(Pizza &pizza);
void PrintPizzaOrder(Pizza pizza);

int main() {
  Pizza pizza;

  GetPizzaOrder(pizza);
  PrintPizzaOrder(pizza);
}

void GetPizzaOrder(Pizza &pizza) {
  char choice;

  cout << "What size pizza would you like (S=Small, M=Medium, L=Large)? ";
  cin >> choice;
  switch (choice) {
    case 'S':
      pizza.size = SMALL;
      pizza.price = 10.95;
      break;
    case 'L':
      pizza.size = LARGE;
      pizza.price = 14.10;
      break;
    default:
      pizza.size = MEDIUM;
      pizza.price = 12.45;
  }

  cout << "What topping would you like (A=Anchovies, M=Mushrooms, S=Sausage, P=Pepperoni, O=Onions)? ";
  cin >> choice;
  switch (choice) {
    case 'A':
      pizza.topping = ANCHOVIES;
      break;
    case 'M':
      pizza.topping = MUSHROOMS;
      break;
    case 'S':
      pizza.topping = SAUSAGE;
      break;
    case 'P':
      pizza.topping = PEPPERONI;
      break;
    default:
      pizza.topping = ONIONS;
  }

  cout << "What crust would you like (T=Thin, H=Thick, S=Stuffed)? ";
  cin >> choice;
  switch (choice) {
    case 'T':
      pizza.crust = THIN;
      break;
    case 'H':
      pizza.crust = THICK;
      pizza.price += 1.00;
      break;
    default:
      pizza.crust = STUFFED;
      pizza.price += 2.00;
  }

  cout << endl;
  return;
}

void PrintPizzaOrder(Pizza pizza) {
  cout << "You ordered a ";

  switch (pizza.size) {
    case SMALL:
      cout << "small ";
      break;
    case MEDIUM:
      cout << "medium ";
      break;
    case LARGE:
      cout << "large ";
      break;
  }

  cout << "pizza with ";

  switch (pizza.topping) {
    case ANCHOVIES:
      cout << "anchovies ";
      break;
    case MUSHROOMS:
      cout << "mushrooms ";
      break;
    case SAUSAGE:
      cout << "sausage ";
      break;
    case PEPPERONI:
      cout << "pepperoni ";
      break;
    case ONIONS:
      cout << "onions ";
      break;
  }

  cout << "on ";

  switch (pizza.crust) {
    case THIN:
      cout << "thin ";
      break;
    case THICK:
      cout << "thick ";
      break;
    case STUFFED:
      cout << "stuffed ";
      break;
  }

  cout << "crust." << endl;

  cout << "The price is $" << fixed << setprecision(2) << pizza.price << endl;
  return;
}