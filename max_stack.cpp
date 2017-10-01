#include <iostream>

using namespace std;

class mstack {
public:
    mstack(){
        head = NULL;
        hair = NULL;
    }
    mstack(const mstack &copy){
        head = copy.head;
        hair = copy.hair;
    }
    ~mstack(){
        while(!is_empty()){
            pop();
        }
    }
    bool is_empty(){
        return head == NULL;
    }
    void push(int new_value){
        node *new_node = new node;
        new_node->next = head;
        new_node->value = new_value;
        head = new_node;
        repoint_hair(head, head->value);
    }
    int get_top(){
        return head->value;
    }
    int get_max(){
        if (hair == head)
            return hair->value;
        return hair->next->value;
    }
    void pop(){
        if (!is_empty()){
            node* node_to_be_deleted = head;
            head = head->next;
            delete node_to_be_deleted;
            if (!is_empty())
                repoint_hair(head, head->value);
        }
    }
    void cut(){
        if (!is_empty()){
            if (hair == head)
                pop();
            else {
                node* node_to_be_deleted = hair->next;
                hair->next = hair->next->next;
                delete node_to_be_deleted;
                if (!is_empty())
                    repoint_hair(head, head->value);
            }
        }
    }
private:
    struct node {
        int value;
        node* next;
    };
    node *head, *hair;
    void repoint_hair(node* &current_node, int max){ 
        if (head == current_node)
            hair = head;       
        if (current_node != NULL && current_node->next != NULL){
            if (current_node->next->value >= max){
                max = current_node->next->value;
                hair = current_node;
            }
            repoint_hair(current_node->next, max);
        }
    }
};

int main(){
    mstack test;

    test.push(1000);
    test.push(500);
    test.push(6);
    test.push(63);
    test.push(1);
    test.push(0);
    test.push(9);
    test.push(1002);
    test.push(1);
    test.push(200);

    cout << "is empty? " << test.is_empty() << endl;
    cout << "top element " << test.get_top() << endl;
    cout << "max " << test.get_max() << endl;
    cout << endl;

    test.pop();
    test.pop();
    test.pop();
    test.pop();
    test.pop();
    test.pop();

    cout << "is empty? " << test.is_empty() << endl;
    cout << "top element " << test.get_top() << endl;
    cout << "max " << test.get_max() << endl;
    cout << endl;

    test.cut();
    test.cut();

    cout << "is empty? " << test.is_empty() << endl;
    cout << "top element " << test.get_top() << endl;
    cout << "max " << test.get_max() << endl;
    cout << endl;

    return 0;
}