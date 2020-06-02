#include <iostream>
using namespace std;

int main() {
  int a = 20;
  cout << "valor de a: " << a << endl;
  int *b = &a;
  cout << "memoria de a: " << &a << endl;
  cout << "memoria de a: " << b << endl;
  int **c = &b;
  cout << "memoria de b: " << c << endl;
  int ***d = &c;
  cout << "memoria de c: " << d << endl;
  int ****e = &d;
  cout << "valor de a: " << ****e << endl;
  cout << " a: " << ***e << endl;
  cout << " a: " << **e << endl;
  cout << " a: " << *e << endl;
  cout << " memoria de d: " << e << endl;
}