#include <iostream>
#include <cmath>
using namespace std;

double der(double (*f)(double), int n, double x0, double dx){
    if (n == 1){
        return (f(x0+dx) - f(x0-dx)) / (2*dx);
    }
    return (der(f, n - 1, x0 + dx, dx) - der(f, n - 1, x0 - dx, dx)) / (2*dx);
}

int main(){
    cout << der(sin, 16, 1, 1e-3) << endl;
    return 0;
}