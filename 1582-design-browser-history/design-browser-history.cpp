class node {
    public:
    string url;
    node* next;
    node* prev;
    node(string s) : url(s) , next(NULL) , prev(NULL){};
    node() :next(NULL) , prev(NULL){};
};


class BrowserHistory {

public:
    node* head= NULL;
    BrowserHistory(string homepage) {
        node* new_node = new node(homepage);
        head = new_node;
    }
    
    void visit(string url) {
        node * new_node = new node(url);
        new_node->prev = head;
        head->next = new_node;
        head = new_node;
    }
    
    string back(int steps) {
        while(steps and head->prev){
            head = head->prev;
            steps--;
        }
        return head->url;
    }
    
    string forward(int steps) {
        while(steps and head->next){
            head = head->next;
            steps--;
        }
        return head->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */