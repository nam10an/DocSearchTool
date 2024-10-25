// compile by: g++ search.cpp Node.cpp -o my_program
// and run by: ./my_program
#include "search.h"
#include "Node.h"
SentenceNode::SentenceNode(){}

SentenceNode::~SentenceNode(){}

SentenceNode::SentenceNode(int _book_code, int _page_no, int _para_no, int _sentence_no, string _sentence){
    book_code = _book_code;
    page_no = _page_no;
    paragraph_no = _para_no;
    sentence_no = _sentence_no;
    sentence = _sentence;
}

//KMP
vector<int> make_prefix(string pattern){
    vector<int> ans(pattern.size(),0);
    if(pattern==""){
        return ans;
    }
    int i=1;
    int len=0;
    while(i<pattern.size()){
        if(pattern[i]==pattern[prev]){
            len++;
            ans[i]=len;
            i++;
        }
        else if(prev==0){
            ans[i]=0;
            i++;
        }
        else{
            len=ans[len-1];
        }
    }
    return ans;
}

vector<int> search_helper(string pattern, string sentence){
    vector<int> prefix=make_prefix(pattern);
    vector<int> ans;
    int i=0;
    int j=0;
    while(i<sentence.size()){
        if(sentence[i]==pattern[j]){
            j++;
            i++;
        }
        else{
            if(j==0){
                i++;
            }
            else{
                j=prefix[j-1];
            }
        }
        if(j==pattern.size()){
            ans.push_back(i-pattern.size());
            j=prefix[j-1];
        }
    }
    return ans;
}

void Linkedlist::insertNode(ListNode *Node){
    if(head==NULL){
        head=Node;
        tail=Node;
        return;
    }
    tail->next = Node;
    tail=tail->next;
}

SearchEngine::SearchEngine(){
    List = new Linkedlist();
}

SearchEngine::~SearchEngine(){
    while((int)store.size()!=0){
        delete store.back();
        store.pop_back();
    }
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    for(int i=0; i<sentence.length(); i++){
        if(sentence[i]>='A' && sentence[i]<='Z'){
            sentence[i]+=32;
        }
    }
    SentenceNode *sent = new SentenceNode(book_code, page, paragraph, sentence_no, sentence);
    store.push_back(sent);
    return;
}


ListNode *SearchEngine::search(string pattern, int &n_matches){ 
    for(int i=0; i<pattern.size(); i++){
        if(pattern[i]>='A' && pattern[i]<='Z'){
            pattern[i]+=32;
        }
    }
    int count=0;
    // cout<<"st size "<<store.size()<<endl;
    // for(int i=0;i<store.size();i++){
    //     cout<<store[i]->sentence<<endl;
    // }

    for (int j=0;j<store.size();j++){
        string sent=store[j]->sentence;
        vector<int> pos=search_helper(pattern,sent);
        count+=pos.size();
        for(int i=0;i<pos.size();i++){
            ListNode* temp=new ListNode();
            if(temp==nullptr) {
                std::cerr << "Failed to allocate memory for ListNode" << std::endl;
            }
            temp->book_code = store[j]->book_code;
            temp->page_no = store[j]->page_no;
            temp->paragraph_no = store[j]->paragraph_no;
            temp->sentence_no = store[j]->sentence_no; 
            temp->offset = pos[i];  
            List->insertNode(temp);
        }
    }
    n_matches=count;
    return List->head;
}

int main(){
    SearchEngine *S=new SearchEngine();
    S->insert_sentence(1,1,1,1,"hello abcdef xyBcDel");
    S->insert_sentence(1,1,1,2,"dakhfbcde fv");
    int _n_matches=0;       //gives number of times pattern occurs in whole of the file
    ListNode* node=S->search("cde",_n_matches);
    // cout<<"hey1"<<endl;
    if(node!=NULL)
        cout<<node->offset<<"  n_matches:"<<_n_matches<<endl;
    // cout<<"hey2"<<endl;
}