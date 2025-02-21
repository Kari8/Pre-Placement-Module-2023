/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
         if(root == NULL) return NULL;
        Node* dummy = new Node();
        dummy->next = root;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            int i = 1;
            Node* pre = q.front();
            q.pop();
            if(pre->left!=NULL) q.push(pre->left);
            if(pre->right!=NULL) q.push(pre->right);
            while(i < size){
                
                Node* cur = q.front();
                q.pop();
                pre->next = cur;//connect two pointers
                pre = cur;//move ahead pointer
                if(cur->left!=NULL) q.push(cur->left);
                if(cur->right!=NULL) q.push(cur->right);
                i++;  
            }
            pre->next = NULL;
        }
        return dummy->next;
    }

        
    
};