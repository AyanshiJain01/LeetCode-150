/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
     //Map to keep track of visited nodes and their clones
    unordered_map<Node*, Node*> mapping;

    Node* cloneGraph(Node* node) {

        if(node == NULL) return NULL;

        //If we have already processed ths node, return its clone
        if(mapping.find(node) != mapping.end())
            return mapping[node];

        //create new node and register in map
        Node* clone = new Node(node -> val);
        mapping[node] = clone;

        //Traverse neighbours
        for(Node* neighbors : node -> neighbors)
        {
            clone -> neighbors.push_back(cloneGraph(neighbors));
        }
        return clone;
    }
};