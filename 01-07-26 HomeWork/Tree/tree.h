template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class Tree {
public:
    TreeNode<T>* root;

    Tree() {
        root = nullptr;
    }
    TreeNode<T>* insert(TreeNode<T>* node, T x) {
        if (node == nullptr) {
            return new TreeNode<T>(x);
        }
        if (x < node->data) {
            node->left = insert(node->left, x);
        } else {
            node->right = insert(node->right, x);
        }
        return node;
    }
    void operator+(T x) {
        root = insert(root, x);
    }
    void operator--(int) {
        if (root == nullptr) {
            std::cout << "Tree underflow\n";
            return;
        }

        if (root->right == nullptr) {
            TreeNode<T>* temp = root->left;
            delete root;
            root = temp;
            return;
        }

        TreeNode<T>* parent = root;
        TreeNode<T>* current = root->right;
        while (current->right != nullptr) {
            parent = current;
            current = current->right;
        }
        parent->right = current->left;
        delete current;
    }
    void preorder(std::ostream& os, TreeNode<T>* node) const {
        if (node != nullptr) {
            os << node->data << " ";
            preorder(os, node->left);
            preorder(os, node->right);
        }
    }
    void inorder(std::ostream& os, TreeNode<T>* node) const {
        if (node != nullptr) {
            inorder(os, node->left);
            os << node->data << " ";
            inorder(os, node->right);
        }
    }
    void postorder(std::ostream& os, TreeNode<T>* node) const {
        if (node != nullptr) {
            postorder(os, node->left);
            postorder(os, node->right);
            os << node->data << " ";
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Tree<T>& t) {
        os << "Tree elements: ";
        os << "\n\tPreorder: ";
        t.preorder(os, t.root);
        os << "\n\tInorder: ";
        t.inorder(os, t.root);
        os << "\n\tPostorder: ";
        t.postorder(os, t.root);
        os << "\n"; 
        return os;
    }
};