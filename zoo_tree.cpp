#include <iostream>
#include <string>

using namespace std;

class zoo_tree {
    public:
        zoo_tree() : root(NULL){};
        ~zoo_tree(){
            remove(root);
        }

        void play(){
            char replay = 'y';

            while (replay == 'y') {
                traverse(root);
                cout << "Play again? (y/n)\n";
                cin >> replay;
            }
        }

    private:
        struct node
        {
            string question;
            node *yes, *no;
            node(string new_q) : question(new_q), yes(NULL), no(NULL) {};
        };

        node *root;

        void traverse(node* &start){   
            if (start == NULL) {
                cout << "You win:(\nEnter the animal and its question, please\n";
                string a, q;
                cin >> a;
                cin >> q;
                start = new node(q);
                start->yes = new node("Is_it_a_" + a + "?");
            }
            else {
                cout << start->question << endl;
                char reply;
                cin >> reply;
                if (reply == 'n') traverse(start->no);
                else if (start->yes != NULL) traverse(start->yes);
                else cout << "I win :)\n";
            }
        }

        void remove(node* start){
            if (start != NULL) {
                remove(start->no);
                remove(start->yes);
                delete start;
            }
        }

        int leaves(node* start){
            if (start != NULL){
                if (start->yes == NULL && start->no == NULL){
                    return 1;
                }
                return (leaves(start->yes) + leaves(start->no));
            }
            return 0;
        }

        int halves(node* start){
            if (start == NULL){
                return 0;
            }
            return (((start->yes == NULL) + (start->yes == NULL) % 2) + halves(start->yes) + halves(start->no));
        }
};


int main(){
	zoo_tree game;
	game.play();

    return 0;
}