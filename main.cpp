
#include "BitString.h"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string a = "1010111111111111111111111111111111111111111111111111111111111001";
  string b = "0010111111111111111111111111111111111111111111111111111111111000";

  BitString Test(a);
  BitString Test2(b);
  BitString Res;

  cout << setw(21) << "First 64-bit value: " << Test.toString() << endl << endl;
  cout << setw(21) << "Second 64-bit value: " << Test2.toString() << endl
       << endl;

  Res = Test & Test2;
  cout << setw(21) << "AND: " << Res.toString() << endl << endl;

  Res = Test | Test2;
  cout << setw(21) << "OR: " << Res.toString() << endl << endl;

  Res = Test ^ Test2;
  cout << setw(21) << "XOR: " << Res.toString() << endl << endl;

  Res = !(Test);
  cout << setw(21) << "1-st NOT: " << Res.toString() << endl << endl;

  Res = !(Test2);
  cout << setw(21) << "2-nd NOT: " << Res.toString() << endl << endl;

  Res = Test >> 3;
  cout << setw(21) << "Shift left : " << Res.toString() << endl << endl;

  Res = Test << 3;
  cout << setw(21) << "Shift right: " << Res.toString() << endl;
}
