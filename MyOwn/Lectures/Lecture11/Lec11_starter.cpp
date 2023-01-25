#include <iostream>
using namespace std;

void passByValue( int pbvX ) {
  cout << "Value of pbvX:    " << pbvX << endl;
  cout << "Address of pbvX:  " << &pbvX << endl;
  
  pbvX++;
  cout << "Value of pbvX:    " << pbvX << endl;
}

void passByReference( int& pbrX ) {
  cout << "Value of pbrX:    " << pbrX << endl;
  cout << "Address of pbrX:  " << &pbrX << endl;

  pbrX++;
  cout << "Value of pbrX:    " << pbrX << endl;
}

int main() {
  int mainX = 4;
  cout << "Value of mainX:   " << mainX << endl;
  cout << "Address of mainX: " << &mainX << endl << endl;

  int mainY = mainX;
  cout << "Value of mainY:   " << mainY << endl;
  cout << "Address of mainY: " << &mainY << endl << endl;

  int& mainZ = mainX;
  cout << "Value of mainZ:   " << mainZ << endl;
  cout << "Address of mainZ: " << &mainZ << endl << endl;

  mainY++;
  cout << "Value of mainX:   " << mainX << endl;
  cout << "Value of mainY:   " << mainY << endl;
  cout << "Value of mainZ:   " << mainZ << endl << endl;

  mainZ++;
  cout << "Value of mainX:   " << mainX << endl;
  cout << "Value of mainY:   " << mainY << endl;
  cout << "Value of mainZ:   " << mainZ << endl << endl;

  passByValue( mainX );
  cout << "Value of mainX:   " << mainX << endl << endl;

  passByReference( mainX );
  cout << "Value of mainX:   " << mainX << endl << endl;

  return 0;
}
