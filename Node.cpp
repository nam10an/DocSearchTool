#include "Node.h"

ListNode::ListNode() {}

ListNode::ListNode(int _book_code, int _page_no, int _paragraph_no, int _sentence_no, int _offset){
    book_code = _book_code;
    page_no = _page_no;
    paragraph_no = _paragraph_no;
    sentence_no = _sentence_no;
    offset = _offset;
}