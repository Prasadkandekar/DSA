class Node{
    public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(){
        key = 0;
        value = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int key , int value){
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }

};

void insertAfterHead(Node* node,Node* head , Node* tail){
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    node->prev = head;
}

void deleteNode(Node* node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
}
class LRUCache {
public:
    map<int,Node*>mpp;
    int size;
    Node* head=new Node(-1,-1);
    Node* tail= new Node(-1,-1) ;
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key)== mpp.end())return -1;

            Node* node = mpp[key];
            deleteNode(node);
            insertAfterHead(node,head,tail);

            return node->value;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->value = value;
            //node used so update
            deleteNode(node);
            insertAfterHead(node,head,tail);
        }else{

            if(mpp.size() == size){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
        Node* node = new Node(key,value);
        mpp[key] = node;
        insertAfterHead(node,head,tail);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */