#include<iostream>
using namespace std;


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
}