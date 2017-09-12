#include <iostream>
#include <vector>
using namespace std;

class Queue {
    vector<char> elements;
    
    public:
    char get() {
        return elements[0];
    }
    void push(char _last) {
        elements.push_back(_last);
    }
    bool empty() {
        return elements.size() == 0;
    }
    char pop() {
        char first = elements[0];
        elements.erase(elements.begin());
        return first;
    }
};

int main(){
    Queue test;
    test.push('g');
    cout << test.get() << endl;
    return 0;
}