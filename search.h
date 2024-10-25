#include <string>
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

class Linkedlist{   // this is the answer list
public:
    ListNode *head;
    ListNode *tail;
    Linkedlist(){
        head = NULL;
        tail = NULL;
    }
    void insertNode(ListNode*);
};

class SentenceNode {
    public: 

    int book_code;
    int page_no;
    int paragraph_no;
    int sentence_no;
    string sentence;

    SentenceNode();
    SentenceNode(int _book_code, int _page_no, int _para_no, int _sentence_no, string _sentence);
    ~SentenceNode();
};

class SearchEngine{
    vector<SentenceNode* > store;   //stores each sentence in SenNode
    Linkedlist *List;       // final ans which contains all the sentence that matches the given pattern

    public:

    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    ListNode *search(string pattern, int &n_matches);

};