#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool balanced_brackets(string text);

int main(){
    string txt = "ccc[bbb{aaa}]>";
    cout<<balanced_brackets(txt)<<endl;
    return 0;
}

bool balanced_brackets(string text){
    stack<char> textStack;
    for (int i = 0; i < text.length(); i++){
        if (text[i] == '[' || text[i] == '{' || text[i] == '<')
            textStack.push(text[i]);
        else if (text[i] == ']' || text[i] == '}' || text[i] == '>'){
            if (textStack.empty() || (char)((int)text[i]-2) != textStack.top())
                return false;
            textStack.pop();
        }
    }
    if (!textStack.empty())
        return false;
    return true;
}
