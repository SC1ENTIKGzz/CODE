#include<bits/stdc++.h>
using namespace std;


class LRUCache {
public:
    class Node {
    public:
        int key ; 
        int val ;
        Node* next ;
        Node* prev ;
    };
    
    Node* head;
    Node* tail;
    unordered_map<int, Node*> node_map;
    int cache_capacity;
    

    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        cache_capacity = capacity;
    }
    void add_node(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }
    void remove_node(Node* node) {
        Node* next_node = node->next;
        Node* prev_node = node->prev;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }

    int get(int key) {
        int result = -1 ;
        Node* node = node_map[key];
        if(node){
            result = node->val;
            remove_node(node);
            add_node(node);
        }
        return result;   
    }
    
    void put(int key, int value) {
        Node* node = node_map[key];
        if(node){
            remove_node(node);
            node->val = value;
            add_node(node);
        }
        else {
            if ( node_map.size() == cache_capacity) {
                node_map.erase(tail->prev->key);
                remove_node(tail->prev);
            }
            Node* new_node = new Node();
            new_node->key = key;
            new_node->val = value;
            node_map[key] = new_node;
            add_node(new_node);

        }
    }
    
   
};
int main()
{
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1)<<endl;
    obj->put(3,3);
    cout<<obj->get(2)<<endl;
    obj->put(4,4);
    cout<<obj->get(1)<<endl;
    cout<<obj->get(3)<<endl;
    cout<<obj->get(4)<<endl;
    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */