
class Node {
    public:
    int key , val;
    Node *next , *prev;
    Node()
    {
        key = 0;
        val = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int key , int val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};





class LRUCache {
public:
    Node *head = new Node() , *tail = new Node();
    unordered_map<int,Node*> nodes;
    int size, k;

    void insertNode(int key , int val)
    {
        Node *newNode = new Node(key,val);
        Node *nextNode = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = nextNode;
        nextNode->prev = newNode;
        nodes[key] = newNode;
        size++;
    }

    void deleteNode(Node *targetNode)
    {
        int key = targetNode->key;
        Node *prevNode = targetNode->prev , *nextNode = targetNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        nodes.erase(key);
        size--;
    }

    LRUCache(int capacity) {
        size = 0;
        k = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(nodes.count(key))
        {
            int val = nodes[key]->val;
            deleteNode(nodes[key]);
            insertNode(key,val);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(nodes.count(key))
        {
            deleteNode(nodes[key]);
            insertNode(key,value);
        }
        else
        {
            if(size == k)
            {
                deleteNode(tail->prev);
            }
            insertNode(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
