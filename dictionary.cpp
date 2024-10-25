#include "dictionary.h"
#include<vector>

std::vector<char> vec;
void addvec(){
    vec.push_back('.');
    vec.push_back(',');
    vec.push_back('-');
    vec.push_back(':');
    vec.push_back('!');
    vec.push_back('"');
    vec.push_back('(');
    vec.push_back(')');
    vec.push_back('?');
    vec.push_back('[');
    vec.push_back(']');
    vec.push_back(';');
    vec.push_back('@');
    vec.push_back(' ');
}
int calculate_hash(string s){
    int len=1001;
    int ans=0;
    for (char j:s){
        ans= (ans*37) + int(j)*53;
        ans=ans%len;
    }
    return ans;
}

TreeNode::TreeNode(){
    key = "";
    height = 0;
    left = NULL;
    right = NULL;
    par = NULL;
    count=0;
}

TreeNode::~TreeNode(){
    if (left != NULL){
        delete left;
        left = NULL;
    }
    if (right != NULL){
        delete right;
        right = NULL;
    }
}

TreeNode::TreeNode(string k){
    key = k;
    height = 0;
    left = NULL;
    right = NULL;
    par = NULL;
    count=0;
}

TreeNode *TreeNode::LeftLeftRotation(){
    TreeNode *b = new TreeNode(this->key);
    TreeNode *a = new TreeNode(this->left->key);
    b->count=this->count;
    a->count=this->left->count;
    b->right = this->right;
    b->left = this->left->right;
    b->par = a;
    a->right = b;
    a->left = this->left->left;
    if (this->par != NULL){
        if (this->par->left == this){
            par->left = a;
        }
        else{
            par->right = a;
        }
    }
    // height balancing //first Node b then do Node a 
    if (b->left == NULL){
        if (b->right == NULL){
            b->height = 0;
        }
        else{
            b->height = b->right->height + 1;
        }
    }
    else{
        if (b->right == NULL){
            b->height = b->left->height + 1;
        }
        else{
            b->height = max(b->right->height, b->left->height) + 1;
        }
    }
    if (a->left == NULL){
        if (a->right == NULL){
            a->height = 0;
        }
        else{
            a->height = a->right->height + 1;
        }
    }
    else{
        if (a->right == NULL){
            a->height = a->left->height + 1;
        }
        else{
            a->height = max(a->right->height, a->left->height) + 1;
        }
    }

    TreeNode *pa = a->par;
    // if(pa!=NULL){
    //     cout<<"IT IS NOT NULL"<<endl;
    //     cout<<pa->key<<endl;
    // }
    // while (pa != NULL){
    //     if (pa->left == NULL){
    //         if (pa->right == NULL){
    //             pa->height = 0;
    //         }
    //         else{
    //             pa->height = pa->right->height + 1;
    //         }
    //     }
    //     else{
    //         if(pa->right == NULL){
    //             pa->height = pa->left->height + 1;
    //         }
    //         else{
    //             pa->height = max(pa->right->height, pa->left->height) + 1;
    //         }
    //     }
    //     pa = pa->par;
    // }
    return a;
}

TreeNode *TreeNode::RightRightRotation(){
    TreeNode *b = new TreeNode(this->key);
    TreeNode *a = new TreeNode(this->right->key);
    b->count=this->count;
    a->count=this->right->count;
    b->left = this->left;
    b->right = this->right->left;
    b->par = a;
    a->left = b;
    a->right = this->right->right;
    if (this->par != NULL){
        if (this->par->right == this){
            par->right = a;
        }
        else{
            par->left = a;
        }
    }
    // height balance
    if (b->left == NULL){
        if (b->right == NULL){
            b->height = 0;
        }
        else{
            b->height = b->right->height + 1;
        }
    }
    else{
        if (b->right == NULL){
            b->height = b->left->height + 1;
        }
        else{
            b->height = max(b->right->height, b->left->height) + 1;
        }
    }
    if (a->left == NULL){
        if (a->right == NULL){
            a->height = 0;
        }
        else{
            a->height = a->right->height + 1;
        }
    }
    else{
        if (a->right == NULL){
            a->height = a->left->height + 1;
        }
        else{
            a->height = max(a->right->height, a->left->height) + 1;
        }
    }

    TreeNode *pa = a->par;
    // cout<<"Parent: "<<pa->key<<endl;
    // while (pa != NULL){
    //     if (pa->left == NULL){
    //         if (pa->right == NULL){
    //             pa->height = 0;
    //         }
    //         else{
    //             pa->height = pa->right->height + 1;
    //         }
    //     }
    //     else{
    //         if (pa->right == NULL){
    //             pa->height = pa->left->height + 1;
    //         }
    //         else{
    //             pa->height = max(pa->right->height, pa->left->height) + 1;
    //         }
    //     }
    //     pa = pa->par;
    // }
    return a;
}

TreeNode *TreeNode::LeftRightRotation(){
    TreeNode *a = this->left;
    TreeNode *b = this->left->right;
    a->right = b->left;
    b->left = a;
    this->left = b;
    b->par = this;

    // height balance
    if (a->left == NULL){
        if (a->right == NULL){
            a->height = 0;
        }
        else{
            a->height = a->right->height + 1;
        }
    }
    else{
        if (a->right == NULL){
            a->height = a->left->height + 1;
        }
        else{
            a->height = max(a->right->height, a->left->height) + 1;
        }
    }

    if (b->left == NULL){
        if (b->right == NULL){
            b->height = 0;
        }
        else{
            b->height = b->right->height + 1;
        }
    }
    else{
        if (b->right == NULL){
            b->height = b->left->height + 1;
        }
        else{
            b->height = max(b->right->height, b->left->height) + 1;
        }
    }
    return this->LeftLeftRotation();
}

TreeNode *TreeNode::RightLeftRotation(){
    TreeNode *a = this->right;
    TreeNode *b = this->right->left;
    a->left = b->right;
    b->right = a;
    this->right = b;
    b->par = this;
    // height balance
    if (a->left == NULL){
        if (a->right == NULL){
            a->height = 0;
        }
        else{
            a->height = a->right->height + 1;
        }
    }
    else{
        if (a->right == NULL){
            a->height = a->left->height + 1;
        }
        else{
            a->height = max(a->right->height, a->left->height) + 1;
        }
    }

    if (b->left == NULL){
        if (b->right == NULL){
            b->height = 0;
        }
        else{
            b->height = b->right->height + 1;
        }
    }
    else{
        if (b->right == NULL){
            b->height = b->left->height + 1;
        }
        else{
            b->height = max(b->right->height, b->left->height) + 1;
        }
    }
    return this->RightRightRotation();
}

Tree::Tree(){
    size=0;
    root=NULL;
}

int height(TreeNode *node){
    if (node == NULL){
        return -1;
    }
    return node->height;
}

int balance_factor(TreeNode *node){
    if (node == NULL){
        return 0;
    }
    return height(node->left)-height(node->right);
}

TreeNode *helperinsert(string k, TreeNode *node, TreeNode *root){
    if (node == NULL){
        TreeNode *s = new TreeNode();
        s->key = k;
        s->count=1;
        node = s;
        return node;
    }
    else{
        if (k > node->key){
            node->right = helperinsert(k, node->right, root);
            node->right->par=node;
        }
        else if (k<node->key){
            node->left = helperinsert(k, node->left, root);
            node->left->par=node;
        }
        else{
            node->count++;
        }
        node->height = max(height(node->left), height(node->right)) + 1;
  
        int height_difference = balance_factor(node);
        
        if (height_difference > 1 && k < node->left->key){
            return node->LeftLeftRotation();
        }
        if (height_difference < -1 && k > node->right->key){
            return node->RightRightRotation();
        }
        if (height_difference > 1 && k > node->left->key){
            return node->LeftRightRotation();
        }
        if (height_difference < -1 && k < node->right->key){
            return node->RightLeftRotation();
        }
        return node;
    }
}

TreeNode* Tree::search(string k){
    bool found = false;
    TreeNode *Node = root;
    TreeNode *ans=new TreeNode(); 
    while (!found){
        if (Node == NULL){
            found = false;
            break;
        }
        if (Node->key == k){
            found = true;
            ans = Node;
            break;
        }
        else{
            if (Node->key > k){
                Node = Node->left;
            }
            else{
                Node = Node->right;
            }
        }
    }
    return ans;
}

void Tree::insert(string k){
    size++;
    if(k==""){
        return;
    }
    TreeNode *Node = root;
    root = helperinsert(k, Node, root);
}

TreeNode* Tree::get_root(){
    return root;
}

void _delete(TreeNode *node){
    if(node == NULL){
        return;
    }
    if (node->left != NULL){
        _delete(node->left);
    }
    if (node->right != NULL){
        _delete(node->right);
    }
    delete node;
    node = NULL;    
}

Tree::~Tree(){
    _delete(root);
    size = 0;
}

Dictionary::Dictionary(){
    dict_vector.resize(1001,NULL);    
}

Dictionary::~Dictionary(){}

bool present(vector<char>& Vec,char h){
    for(int j=0;j<Vec.size();j++){
        if (Vec[j]==h){
            return true;
        }
    }
    return false;
}

void Dictionary::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    for(int i=0; i<sentence.length(); i++){
        if(sentence[i]>='A' && sentence[i]<='Z'){
            sentence[i]+=32;
        }
    }
    addvec();
    string s="";
    for(int i=0; i<sentence.size(); i++){
        char h=sentence[i];
        
        if(int(h)==39 || present(vec,h) ){
            int ind=calculate_hash(s);
            if(dict_vector[ind]==NULL){
                dict_vector[ind]=new Tree();
            }
            dict_vector[ind]->insert(s);
            s="";
        }
        else{
            s+=sentence[i];
            if(i==sentence.size()-1){
                int ind=calculate_hash(s);
                if(dict_vector[ind]==NULL){
                    dict_vector[ind]=new Tree();
                }
                dict_vector[ind]->insert(s);
                s="";
            }
        }
    }
}

int Dictionary::get_word_count(string word){
    for(int i=0;i<word.size();i++){
        if(word[i]>='A' && word[i]<='Z'){
            word[i]+=32;
        }
    }
    int ind=calculate_hash(word);
    TreeNode* temp;
    if(dict_vector[ind]==NULL){
        return 0;
    }
    temp=dict_vector[ind]->search(word);

    if(temp->key==""){
        return 0;
    }  
    return temp->count;
}

void command(TreeNode* Node,vector<string> &commands){
    if(Node==NULL){
        return;
    }
    string s=Node->key+", "+to_string(Node->count);
    commands.push_back(s);
    command(Node->left,commands);
    command(Node->right,commands);
}

void iterate(vector<Tree*> dict_vector, vector<string> &commands){
    for(int i=0;i<1001;i++){
        if(dict_vector[i]!=NULL){
            TreeNode* p=dict_vector[i]->get_root();
            command(p,commands);
        }
    }
}

void Dictionary::dump_dictionary(string filename){
    ofstream outcfile(filename, ios::app);
    vector <string> comm;
    iterate(dict_vector,comm);
    for(int i=0;i<comm.size();i++){
        outcfile<<comm[i]<<std::endl;
        i++;
    }
    outcfile.close(); 
}

// int main(){
//     Dictionary *p1=new Dictionary();
//     string out="hello.txt";
//     p1->insert_sentence(1,2,1,1,"helllo world");
//     //cout<<"this1"<<endl;
//     p1->insert_sentence(1,2,1,1,"helLlo.helllo");
//     //cout<<"this2"<<endl;
//     p1->insert_sentence(1,2,1,1,"hElllo");
//     //cout<<"this3"<<endl;
//     p1->insert_sentence(1,2,1,1,"hello");
//     //cout<<"this4"<<endl;
//     p1->insert_sentence(1,2,1,1,"helo World");
//     //cout<<"this5"<<endl;
//     cout<<p1->get_word_count("helllo")<<endl;
//     cout<<p1->get_word_count("hlo")<<endl;
//     p1->dump_dictionary(out);
//     cout<<"Y";
// }