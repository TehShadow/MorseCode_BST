#include<iostream>
#include<list>
#include<queue>
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
        int i=0;
        while (current->code != Code)
        { 
            if(current != nullptr){

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
    string encode(string Letter){
         queue<Node*> q;
        Node *r = root;
         q.push(r);
         while(!q.empty()){
             Node *current = q.front();
             if (current->letter==Letter) return current->code;
             
            //  cout<<current->code<<"//";

             q.pop();
             if(current->left) q.push(current->left);
             if(current->right) q.push(current->right);
         }
         return "Not in the tree\n";
    }
};


int getInput();
string encode(BST x);
string decode(BST x);


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
    //setting vertexes
    for(int i = 0; i < 27; i++)
    {
        morse.Insert(tree[i].letter, tree[i].code);
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////Input//Output///////////////////////////////////////////////////
    bool exit = false;
    while(exit != true){
        int choice = getInput();
        if(choice == 1){
           encode(morse);
           
           getchar();
           getchar();
        }
        else if(choice == 2){
            decode(morse);

            getchar();
            getchar();
        }
        else if(choice == 0) exit = true;
    }
}


    // spliting the string on "/"

int getInput(){
    int choice;
    string logo = R"(

 _    _        _                                    _           
| |  | |      | |                                  | |          
| |  | |  ___ | |  ___   ___   _ __ ___    ___     | |_   ___   
| |/\| | / _ \| | / __| / _ \ | '_ ` _ \  / _ \    | __| / _ \  
\  /\  /|  __/| || (__ | (_) || | | | | ||  __/ _  | |_ | (_) | 
 \/  \/  \___||_| \___| \___/ |_| |_| |_| \___|( )  \__| \___/  
                                               |/               
                                                                
___  ___                          _____             _           
|  \/  |                         /  __ \           | |          
| .  . |  ___   _ __  ___   ___  | /  \/  ___    __| |  ___     
| |\/| | / _ \ | '__|/ __| / _ \ | |     / _ \  / _` | / _ \    
| |  | || (_) || |   \__ \|  __/ | \__/\| (_) || (_| ||  __/    
\_|  |_/ \___/ |_|   |___/ \___|  \____/ \___/  \__,_| \___|    
                                                                
                                                                
---------------------------------------------------------------------------
)";
    cout<<logo;
    cout<<"#1 Encode Morse\n";
    cout<<"#2 Decode Morse\n";
    cout<<"#0 Exit\n";
    cin>>choice;
    return choice;
}






string encode(BST x){
    // spliting the string on "/"
    cout<<"Enter a string to be turned to morse(letter/letter/letter):";
    string word;
    cin>>word;

    std::string s = word;
    std::string delimiter = "/";

    size_t pos = 0;
    std::string token;

    while ((pos = s.find(delimiter)) != std::string::npos) {

        token = s.substr(0, pos);
        string yo = x.encode(token);
        cout<<yo;
        s.erase(0, pos + delimiter.length());

}

    string sup = x.encode(s);
    cout<<sup;
}






string decode(BST x){
        cout<<"Enter a string to be decoded from morse to letters(code/code/code):";
    string word;
    cin>>word;

    std::string s = word;
    std::string delimiter = "/";

    size_t pos = 0;
    std::string token;

    while ((pos = s.find(delimiter)) != std::string::npos) {

        token = s.substr(0, pos);
        string yo = x.decode(token);
        s.erase(0, pos + delimiter.length());

}

    string sup = x.decode(s);
}

