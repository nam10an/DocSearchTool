#pragma once
#include<fstream>
#include<string> 
#include<vector>
#include<iostream>
using namespace std;

extern std::vector<char> vec;
void addvec();
class TreeNode{
public:
    string key;
    int height;
    int count=0;
    
    TreeNode* par;
    TreeNode* left;
    TreeNode* right;

    TreeNode();
    TreeNode(string k);

    TreeNode* LeftLeftRotation(); 
    TreeNode* RightRightRotation();
    TreeNode* LeftRightRotation();
    TreeNode* RightLeftRotation();

    ~TreeNode();
    
};
//AVL TREE
class Tree{
    int size;
    TreeNode* root;

    public: 
    Tree();
    ~Tree();

    void insert(string k);

    void remove(string k);

    TreeNode* search(string k);

    void assign_address(string k,int idx);

    int get_size();

    TreeNode* get_root();
};

class Dictionary {
    vector<Tree*> dict_vector;
    public: 
    Dictionary();

    ~Dictionary();

    void insert_sentence(int book_code, int page_no, int paragraph_no, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);
};

// #endif