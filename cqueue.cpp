#include <iostream>
using namespace std;

class cqueue
{
public:
	cqueue() : head(NULL){};
	cqueue(const cqueue &that) : head(NULL){
		for (node *that_current = that.head; that_current != NULL; that_current = that_current->next)
			insert(that_current->value);
	};
	~cqueue(){
		for (node *curr = head; remove(); curr = curr->next);
	};
	bool is_empty(){
		return (head == NULL);
	};
	void insert(int new_value)
	{
		node *new_node = new node(new_value, NULL);
		if (is_empty()){
			head = new_node;
			return;
		}
		node *current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	};
	bool remove()
	{
		if (is_empty())
			return false;
		node *node_to_delete = head;
		head = head->next;
		delete node_to_delete;
		return true;
	};
	int retrieve()
	{
		if (is_empty())
			return 0;
		else
			return head->value;
	};
private:
	struct node
	{
		int value;
		node *next;
		node(int new_value, node *new_next) : value(new_value), next(new_next){};
	};
	node *head;
};

int main()
{
	cqueue test0;
	test0.insert(2);
	test0.insert(86);
	test0.remove();
	cqueue test1 = cqueue(test0);
	cout << test1.retrieve() << endl;
	return 0;
}