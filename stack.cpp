#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<char> elements;

    public:
    char get() {
        return elements[elements.size() - 1];
    }
    void push(char _last) {
        elements.push_back(_last);
    }
    bool empty() {
        return elements.size() == 0;
    }
    void pop() {
        return elements.pop_back();
    }
};

int main(){
    Stack test;
    test.push('g');
    cout << test.get() << endl;
    return 0;
}