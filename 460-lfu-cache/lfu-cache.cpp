class Node{
    public:
        int key;
        int value;
        int cnt ;
        Node* next;
        Node* prev;

        Node(){
            key = value = -1;
            cnt = 1;
            next = prev = nullptr;
        }
        Node(int key , int value){
            this->key = key;
            this->value = value;
            cnt =1;
            next = prev = nullptr;
        }
};
class List{
    public:
    Node* head;
    Node* tail;
    int size;

    List(){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = node->prev = nullptr;
        size--;
    }
    
};
class LFUCache {
    map<int,Node*>keyNode;
    map<int,List*>freqListMap;
    int maxSizeCache;
    int currSize;
    int minfreq;
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        currSize =0;
        minfreq = 0;
    }

    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minfreq && freqListMap[node->cnt]->size ==0){
            minfreq++;
        }

        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt +1)!= freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt+1];
        }
        node->cnt +=1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache ==0)return ;

        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }else{
            if(currSize == maxSizeCache){
                List * list = freqListMap[minfreq];
                keyNode.erase(list->tail->prev->key);

                freqListMap[minfreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minfreq =1;
            List * listFreq = new List();
            if(freqListMap.find(minfreq) != freqListMap.end()){
                listFreq = freqListMap[minfreq];
            }
            Node* node = new Node(key,value);
            listFreq->addFront(node);
            keyNode[key] =node;
            freqListMap[minfreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */