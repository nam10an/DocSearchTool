#pragma once
// using namespace std;
class ListNode {
    public: 
    ListNode* next;

    int book_code;
    int page_no;
    int paragraph_no;
    int sentence_no;
    int offset;

    ListNode();
    ListNode(int _book_code, int _page_no, int _paragraph_no, int _sentence_no, int _offset);
};