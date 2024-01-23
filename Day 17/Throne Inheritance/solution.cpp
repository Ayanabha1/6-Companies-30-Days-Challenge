class Node {
    public:
    string name;
    vector<Node*> children;
    Node(string name)
    {
        this->name = name;
    }
};

class ThroneInheritance {
public:
    unordered_set<string> dead;
    unordered_map<string,Node*> pos;
    Node *king;
    ThroneInheritance(string kingName) {
        king = new Node(kingName);
        pos[kingName] = king;
    }
    
    void birth(string parentName, string childName) {
        if(!pos.count(parentName))
        {
            // Parent already died
            return;
        }
        Node *newNode = new Node(childName);
        Node* parent = pos[parentName];
        parent->children.push_back(newNode);
        pos[childName] = newNode;
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    void getList(Node *node , vector<string> &list , unordered_set<Node *> &vis)
    {
        if(!node)
        {
            return;
        }
        vis.insert(node);
        if(!dead.count(node->name))
        {
            list.push_back(node->name);
        }
        for(auto it: node->children)
        {
            if(!vis.count(it))
            {
                getList(it,list,vis);
            }
        }
    }

    vector<string> getInheritanceOrder() {
        unordered_set<Node *> visited;
        vector<string> list;
        getList(king,list,visited);
        return list;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
