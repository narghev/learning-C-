#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void chart01(double (*f)(double), double x1, double x2, int rows, int cols){
  double dx = (x2-x1)/rows;
  for (double x = x1; x <= x2; x += dx)
    cout<< setw(1 + cols*f(x)) << '*' << endl;
}

int main(){
  chart01(sin, 0, 6, 100, 100);
  return 0;
}
