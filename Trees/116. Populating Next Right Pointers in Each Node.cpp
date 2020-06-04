class Solution {
private:
    void solve(Node* node1, Node* node2)
    {
        if(node1 == NULL || node2 == NULL)
            return;
        if(node1->next != NULL)
            return;
        node1->next = node2;
        solve(node1->left, node1->right);
        solve(node1->right, node2->left);
        solve(node2->left, node2->right);
    }
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        solve(root->left, root->right);
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        Node* Root = root;
        while(root->left)
        {
            Node* temp = root;
            root->left->next = root->right;
            while(root->next)
            {
                root->left->next = root->right;
                root->right->next = root->next->left;
                root = root->next;
            }
            root->left->next = root->right;
            root = temp->left;
        }
        return Root;
    }
};
