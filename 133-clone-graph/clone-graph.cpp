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
void find(Node*&node,Node*&clonenode,unordered_map<Node*,Node*>&mp)
{
    for(Node*x:node->neighbors)
      {
          if(mp.find(x)==mp.end())
           {
               Node *clone=new Node(x->val);
               mp[x]=clone;
               clonenode->neighbors.push_back(clone);
               find(x,clone,mp);

           }
           else
               clonenode->neighbors.push_back(mp[x]);
      }
}
    Node* cloneGraph(Node* node) {
        if(node==NULL)
          return node;
    unordered_map<Node*,Node*>mp;
     Node*clonenode=new Node(node->val);
     mp[node]=clonenode;
     find(node,clonenode,mp);
     return  clonenode;

    }
};