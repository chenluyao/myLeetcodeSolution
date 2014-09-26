class LRUCache{
public:
    class LinkNode
    {
    public:
        LinkNode *prev;
        LinkNode *next;
        int key;
        int value;
        LinkNode(int k, int v, LinkNode *pre)
        {
            key = k;
            value = v;
            prev = pre;
            next = NULL;
            if(pre != NULL)
            {
                pre->next = this;
            }
        }
        
    };
    
    int capa;
    LinkNode *head;
    LinkNode *rear;
    int size;
    map<int,LinkNode* > key2Node; 
    LRUCache(int capacity) 
    {
        head = new LinkNode(-1,-1,NULL);
        rear = head;
        capa = capacity;
        size = 0;
    }
    void removeNode(LinkNode *n)
    {
        n->prev->next = n->next;
        if(n->next != NULL)///!!!!
        {
            n->next->prev = n->prev;
        }
    }
    void deleteNode(LinkNode *n)
    {
        removeNode(n);
        key2Node.erase(key2Node.find(n->key));
        delete n;
    }
    int get(int key) 
    {
        if(key2Node.find(key) == key2Node.end())
        {
            return -1;
        }
        else
        {
            LinkNode *temp = key2Node[key];
            if(rear == temp)//!!!!
            {
                rear = temp->prev;
            }
            int value = temp->value;
            deleteNode(temp);
            LinkNode *newNode = new LinkNode(key, value, rear);
            key2Node[key] = newNode;
            rear = newNode;
            return value;
        }
    }
    void set(int key, int value) 
    {
        LinkNode *temp;
        if(key2Node.find(key) == key2Node.end() && size == capa)
        {
           temp = head->next;
           if(rear == temp)//!!!!
           {
                rear = temp->prev;
            }
           deleteNode(temp);
           size--;
        }
        else if(key2Node.find(key) != key2Node.end())
        {
            temp = key2Node[key];
            if(rear == temp)//!!!!
            {
                rear = temp->prev;
            }
            deleteNode(temp);
            size--;
        }
        LinkNode *newNode = new LinkNode(key, value, rear);
        key2Node[key] = newNode;
        rear = newNode;
        size++;
    }
};