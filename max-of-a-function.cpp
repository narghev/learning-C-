#include <cmath>
#include <iostream>

using namespace std;

double max(double (*f)(double), double x1, double x2, double dx);

int main(){
  cout<< max(sin, -1, 1, 0.01) <<endl;
  return 0;
}

double max(double (*f)(double), double x1, double x2, double dx){
  if (x2 <= x1)
    return f(x1);
  double prev_max = max(f, x1, x2 - dx, dx);
  double last_max = f(x2);
  return last_max < prev_max ? prev_max : last_max;
}
