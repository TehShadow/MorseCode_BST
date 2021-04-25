#include<iostream>
using namespace std;
using std::string;


class BST
{
private:
    struct Node
    {
        string letter;
        string code;
        Node *left;
        Node *right;
    };
    Node *root;

public:
    BST()
    {
        root = new Node;
    }
    void Insert(Node *r, string Letter, string Code)
    {
            r->letter = Letter;
            r->code = Code;
            r->left = nullptr;
            r->right = nullptr;

    }
    void Insert(string letter, string code)
    {
        Node *r = root;
        if(r == root && r->letter == ""){
            Insert(r, letter, code);
        }else{
            for(char i : code)
            {
                if(i=='.'){
                    if (r->left == nullptr){
                        r->left = new Node;
                    }
                    r = r->left;
                }

                else if (i=='-'){
                    if(r->right == nullptr){
                        r->right = new Node;
                    }
                    r = r->right;
                }

            }
            Insert(r,letter,code);
        }
    }
    string decode(string Code){
         Node *current = root;
        std::cout<<"Visiting nodes:\n";
        int i=0;
        while (current->code != Code)
        { 
            if(current != nullptr){
                std::cout<<"Letter:"<<current->code<<"\n";

                //go to left tree
                if(Code[i] == '.'){
                    current = current->left;
                }//else go to right
                else{
                    current = current->right;
                } 
                //not found
                if(current ==nullptr){
                    return "not in the tree(A-Z)";
                }
               
            }
             i++; 
        }
        std::cout<<"Letter found:"<<current->letter<<"\n";
        return current->letter;
    }
};

int main(){
    struct alphaTree
    {
        string letter;
        string code;
    };

    BST morse;

    alphaTree tree[] = {
            {"ROOT", ""},  {"E", "."},    {"T", "-"},    {"I", ".."},   {"A", ".-"},   {"N", "-."},
            {"M", "--"},   {"S", "..."},  {"U", "..-"},  {"R", ".-."},  {"W", ".--"},  {"D", "-.."},
            {"K", "-.-"},  {"G", "--."},  {"O", "---"},  {"H", "...."}, {"V", "...-"}, {"F", "..-."},
            {"L", ".-.."}, {"P", ".--."}, {"J", ".---"}, {"B", "-..."}, {"X", "-..-"}, {"C", "-.-."},
            {"Y", "-.--"}, {"Z", "--.."}, {"Q", "--.-"}
    };

    for(int i = 0; i < 27; i++)
    {
        morse.Insert(tree[i].letter, tree[i].code);
    }
    string letter;
    letter = morse.decode("--..-..");
    std::cout<<letter;
}