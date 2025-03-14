// Test driver
#include <iostream>
#include "frac.h"

using namespace std;

int main()
{
  FractionType f1, f2, f3(0,5);

  f1.Initialize(2,3);
  cout << "f1 numerator = " << f1.NumeratorIs() << endl;
  cout << "f1 denominator = " << f1.DenominatorIs() << endl;
  //cout << "f1 = ";
  //f1.Write(); 

  cout << "f2 numerator = " << f2.NumeratorIs() << endl;
  cout << "f2 denominator = " << f2.DenominatorIs() << endl;
  f2.Initialize(9,4);
  cout << "f2 numerator = " << f2.NumeratorIs() << endl;
  cout << "f2 denominator = " << f2.DenominatorIs() << endl;

  cout << "f3 numerator = " << f3.NumeratorIs() << endl;
  cout << "f3 denominator = " << f3.DenominatorIs() << endl;

  if (f1.IsZero())
	  cout << "f1 is zero" << endl;
  else
	  cout << "f1 is NOT zero" << endl;

  if (f3.IsZero())
	  cout << "f3 is zero" << endl;
  else
	  cout << "f3 is NOT zero" << endl;

  if (f1.IsNotProper())
	  cout << "f1 is IsNotProper" << endl;
  else
	  cout << "f1 is Proper" << endl;

  if (f2.IsNotProper())
  {
	  cout << "f2 is IsNotProper" << endl;
	  cout << "after converting, f2 = " << f2.ConvertToProper() << ' ';
	  cout << f2.NumeratorIs() << '/' << f2.DenominatorIs() << endl;
  }
  else
	  cout << "f2 is Proper" << endl;


  return 0;
}
