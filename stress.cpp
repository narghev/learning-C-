#include <iostream>
#include <string>
using namespace std;
string stress (string word){
  for (int i=0;i<word.size();i++){
    if (int(word[i])==39){
      word[i-1] = toupper(word[i-1]);
      word.erase((i),1);
    }
  }
  return word;
}
int main(){
  string a;
  cin>>a;
  cout<<stress(a)<<endl;
  return 0;
}
