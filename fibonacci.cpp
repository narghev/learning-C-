#include "iostream"
using namespace std;

int fib_rec(int n, int &prev);

int main(){
  int initial;
  cout<< fib_rec(10, initial) <<endl;
  return 0;
}

int fib_rec(int n, int &prev){
  if (n < 2){
    prev = 0;
    return n;
  }
  int prev0;
  prev = fib_rec(n-1, prev0);
  return prev0 + prev;
}
