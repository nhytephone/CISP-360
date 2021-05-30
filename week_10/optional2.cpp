#include <iostream>

using namespace std;
int doSomething(int *x, int *y);

int main()
{

  int x=5;
  int y=2;

int z = doSomething(&x,&y);
cout << z << endl;
}

int doSomething(int *x, int *y)
{
   int temp = *x;
   *x = *y * 10;
   *y = temp * 10;
   return *x + *y;
}
