// Test driver
#include <iostream>
#include "frac plus.h"

int main()
{
  using namespace std;

  FractionType f1, f2, f3; 

  f1.Initialize(2,3);
  cout << "f1 = ";
  f1.Write();

  f2.Initialize(-6,8);
  cout << "f2 = ";
  f2.Write();
  //f2.Simplify();
  //cout << "f2 (Simplified)= ";
  //f2.Write();

  //f3 = f1.Add( f2 );
  //f3 = f1 + f2;     // overloaded operator -- must be defined before used
  //cout << "f3 (Add) = ";
  //f3.Write();
  //cout << f3 << ", & in float form = " << (float) f3 << endl;

  //f3 = f1.Sub( f2 );
  //cout << "f3 (Sub) = " << endl;
  //f3.Write();

  //f3 = f1.Mult( f2 );
  //cout << "f3 (Mult) = " << endl;
  //f3.Write();

  //f3 = f1.Div( f2 );
  //cout << "f3 (Div) = " << endl;
  //f3.Write();

  return 0;
}