#include "iostream"
using namespace std;

void solve_discs(int discs, int from = 1, int to = 3){
  if (discs == 1)
    cout<<from<<"->"<<to<<endl;
  else{
    solve_discs(discs-1, from, 6-from-to);
    solve_discs(1, from, to);
    solve_discs(discs-1, 6-from-to, to);
  }
}

int main(){
  int discs = 3;
  solve_discs(discs);
  return 0;
}
