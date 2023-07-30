#include <bits/stdc++.h>
using namespace std;



/* --------------------------------------------------------- MACROES - START --------------------------------------------------------- */
#define ERR_EMPTY   "Tree is empty !"
#define ERR_NOEMPTY "Tree is non empty !"
#define ERR_VAL     "Invalid value !"

/* --------------------------------------------------------- MACROES - END ----------------------------------------------------------- */





/* ----------------------------------------------------- DATA STRUCTS - START -------------------------------------------------------- */
struct node {
	int data;
	node *left;
	node *right;

    node(int value) {
        data = value;
        left = right = nullptr;
    }
};



struct tree {
	node *root;

    tree() {
        root = nullptr;
    }
};
/* ------------------------------------------------------ DATA STRUCTS - END ---------------------------------------------------------- */





/* ------------------------------------------------------- PROTOTYPE - START ---------------------------------------------------------- */
/**
 * @brief Create a Tree object
 * 
 * @param root 
 * @param nums - number of nodes
 */
void createTree(node *&root, int nums);



/**
 * @brief add a new node to tree in the form of binary tree
 * 
 * @param Node 
 * @param data 
 */
void addBinaryNode(node *&Node, int data);



/**
 * @brief Create a Binary Tree object
 * 
 * @param root 
 * @param nums - the number of nodes
 */
void createBinaryTree(node *&root, int nums);



/**
 * @brief left subtree is visited first, then root and later right subtree
 * 
 * @param root 
 */
void printInOrder(node *root);



/**
 * @brief root is visited first, then left subtree and finally right subtree
 * 
 * @param root 
 */
void printPreOrder(node *root);



/**
 * @brief left subtree is visited first, then right subtree and finally root
 * 
 * @param root 
 */
void printPostOrder(node *root);



/**
 * @brief Traverse from level 0 for root node, 
 * for all the even levels, print the node's value from right to left and 
 * for all the odd levels, print the node's value from left to right.
 * 
 * https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1
 * 
 * @param root 
 */
void printSpiralOrder(node *root);



/**
 * @brief Right view of a Binary Tree is set of nodes visible when tree is viewed from right side. 
 * 
 * https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
 * 
 * @param root 
 * @param rightViewNodes contains nodes visible when tree is viewed from right side.
 * @param level original level (0)
 */
void printRightView(node *root, vector<int> &rightViewNodes, int level);



/**
 * @brief left view of a Binary Tree is set of nodes visible when tree is viewed from left side.
 * 
 * @param root 
 * @param leftViewNodes contains nodes visible when tree is viewed from left side.
 * @param level original level (0)
 */
void printLeftView(node *root, vector<int> &leftViewNodes, int level);



/**
 * @brief count the number of nodes
 * 
 * @param root 
 * @param count 
 */
void countLeafNode(node *root, int &count);



/**
 * @brief count the number of nodes whose data is equal to value 
 * 
 * @param root 
 * @param count 
 * @param val 
 */
void countNodeEqValue(node *root, int &count, int val);



/**
 * @brief check level of tree
 * 
 * @param root 
 * @return int 
 */
int treeLevel(node *root);



/**
 * @brief difference between levels of the left and right subtrees is not greater than 1
 * 
 * @param root 
 * @return true 
 * @return false 
 */
bool isAVL(node *root);



/**
 * @brief rotate tree to the right
 * 
 * https://codelearn.io/learning/data-structure-and-algorithms/887692
 * 
 * @param oldRoot 
 * @return node* 
 */
node *turnRight(node *oldRoot);



/**
 * @brief rotate tree to the left
 * 
 * https://codelearn.io/learning/data-structure-and-algorithms/887692
 * 
 * @param oldRoot 
 * @return node* 
 */
node *turnLeft(node *oldRoot);



/**
 * @brief convert current tree to AVL tree if necessary
 * 
 * https://codelearn.io/learning/data-structure-and-algorithms/887692
 * 
 * @param root 
 */
void updateTreeAVL(node *&root);



/**
 * @brief delete any node in tree
 * 
 * @param Node 
 */
void deleteNode(node *&Node);



/**
 * @brief delete any node whose data is equal to value
 * 
 * @param root 
 * @param val 
 */
void deleteNodeEqVal(node *&root, int val);



/**
 * @brief find maximum data of tree
 * 
 * @param root 
 * @return int 
 */
int maxValue(node *root);



/**
 * @brief find minimum data of tree
 * 
 * @param root 
 * @return int 
 */
int minValue(node *root);



/**
 * @brief Check whether it is a Binary Search Tree or not
 * 
 * https://practice.geeksforgeeks.org/problems/check-for-bst/1?page=1&sprint=161cbf2a057c66ee17ca1e5c102af8b7&sortBy=submissions
 * 
 * @param root 
 * @return true 
 * @return false 
 */
bool isBST(node *root);



/**
 * @brief find the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
 *
 * https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
 *  
 * @param root 
 * @param k kth ancestor
 * @param node given node
 * @return int 
 */
int kthAncestor(node *root, int k, int node);



/**
 * @brief find the Lowest Common Ancestors of the two nodes in the BST.
 * 
 * https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
 * 
 * @param root 
 * @param n1 data of node1
 * @param n2 data of node2
 * @return node* 
 */
node *LCA(node *root, int n1, int n2);



/**
 * @brief find the median
 * 
 * @param root 
 * @return float 
 */
float findMedian(node *root);



/**
 * @brief returns the in-order successor of the node X in BST
 * 
 * @param root 
 * @param X 
 * @return node* 
 */
node * inOrderSuccessor(node *root, node *X);

/* -------------------------------------------------------- PROTOTYPE - END ----------------------------------------------------------- */





/* --------------------------------------------------------- FUNCTIONS - START -------------------------------------------------------- */
void createTree(node *&root, int nums)
{  
    try {
        if (root != nullptr)                                    // non empty tree
            throw ERR_NOEMPTY;

        if (nums < 1)                                           // invalid quantity
            throw ERR_VAL;
       
        queue<node *> nodes;
        node *p;
        int data;

        cout << "Enter data of node: ";                         
        cin >> data;
        if (data == 0)                                          // null              
            return;

        root = new node(data);                                  // add root
        nodes.push(root);
        
        for (int i = 1; i < nums; i++) {
            if (i % 2 != 0) {                                   // consider to create subtree
                p = nodes.front();
                nodes.pop();
            }
            
            cout << "Enter data of node: ";
            cin >> data;

            if (data != 0 && i % 2 != 0) {                      // add node to left subtree
                p->left = new node(data);
                nodes.push(p->left);
            }

            if (data != 0 && i % 2 == 0) {                      // add node to right subtree
                p->right = new node(data);
                nodes.push(p->right);
            }
        }
    } 

    catch (const char *exc) {
        cout << exc << endl;
    }
}



void addBinaryNode(node *&Node, int data) 
{
	if (Node == nullptr)
		Node = new node(data);
    else
		if (data < Node->data) 
			addBinaryNode(Node->left, data);
		else
			addBinaryNode(Node->right, data);
}



void createBinaryTree(node *&root, int nums) 
{
    int data;
    
    try {
        if (root != nullptr)                                    // non empty tree
            throw ERR_NOEMPTY;

        if (nums < 1)                                           // invalid quantity
            throw ERR_VAL;

        for (int i = 0; i < nums; i++) {
            cout << "Enter data of node: ";
            cin >> data;          
            addBinaryNode(root, data);
        }
    }

    catch (const char *exc) {
        cout << exc << endl;
    }
}



void printInOrder(node *root) 
{
	if (root != nullptr) {
		printInOrder(root->left);
		cout << root->data << " ";
		printInOrder(root->right);
	}
}



void printPreOrder(node *root) 
{
	if (root != nullptr) {
		cout << root->data << " ";
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}



void printPostOrder(node *root)
{
	if (root != nullptr) {
		printPostOrder(root->left);
		printPostOrder(root->right);
		cout << root->data << " ";
	}
}



void printSpiralOrder(node *root)
{
    queue<node *> nodes;
    vector<int> temp;
    node *p;
    int level = 0, currentSize, i;
    
    if (root) {
        nodes.push(root);                               // init
        
        while (!nodes.empty()) {
            currentSize = nodes.size();                 // control numbers of current node in queue
            
            for (i = 0; i < currentSize; i++) {
                p = nodes.front();                      // get node
                nodes.pop();
                
                temp.push_back(p->data);                // store data of node
                
                if (p->left)                            // store node in left subtree
                    nodes.push(p->left);
            
                if (p->right)                           // store node in right subtree
                    nodes.push(p->right);
            }
            
            if (level % 2 == 0)                         // even level -> reverse
                reverse(temp.begin(), temp.end());
                
            level++;                                    // inc level
                
            for (auto Data : temp)                      // print spiral order
                cout << Data << " ";
                
            temp.clear();                               // reset for next iterations
        }
    }
}



void printRightView(node *root, vector<int> &rightViewNodes, int level)
{
    if (root != nullptr) {
        if (level == rightViewNodes.size()) {                       // rightmost node
            rightViewNodes.push_back(root->data);
            cout << root->data << " ";
        }
        
        printRightView(root->right, rightViewNodes, level+1);       // prioritize for right subtree
        
        printRightView(root->left, rightViewNodes, level+1);
    }
}



void printLeftView(node *root, vector<int> &leftViewNodes, int level)
{
    if (root != nullptr) {
        if (level == leftViewNodes.size()) {                        // leftmost node
            leftViewNodes.push_back(root->data);
            cout << root->data << " ";
        }
        
        printLeftView(root->left, leftViewNodes, level+1);          // prioritize for left subtree
        
        printLeftView(root->right, leftViewNodes, level+1);
    }
}



void countLeafNode(node *root, int &count)
{
	if (root != nullptr) {
		count++;
		countLeafNode(root->left, count);
		countLeafNode(root->right, count);
	}
}



void countNodeEqValue(node *root, int &count, int val)
{
	if (root != nullptr) {
		if (root->data == val)
			count++;
		countNodeEqValue(root->left, count, val);
		countNodeEqValue(root->right, count, val);
	}
}



int treeLevel(node *root) 
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return 1;
	else 
		return 1 + max(treeLevel(root->left), treeLevel(root->right));
}



bool isAVL(node *root) 
{
    return (abs(treeLevel(root->left) - treeLevel(root->right)) > 1) ? false : true;
}



node *turnRight(node *oldRoot)
{
	node *newRoot = oldRoot->left;
	node *rightSub = newRoot->right;
	oldRoot->left = rightSub;
	newRoot->right = oldRoot;
	return newRoot;
}



node *turnLeft(node *oldRoot) 
{
	node *newRoot = oldRoot->right;
	node *leftSub = newRoot->left;
	oldRoot->right = leftSub;
	newRoot->left = oldRoot;
	return newRoot;
}



void updateTreeAVL(node *&root) 
{
	if (!isAVL(root)) {
		if (treeLevel(root->left) > treeLevel(root->right)) {
			node *p = root->left;
			if (treeLevel(p->left) >= treeLevel(p->right))
				root = turnRight(root);
			else {
				root->left = turnLeft(root->left);
				root = turnRight(root);
			}
		} 
		else {
			node *p = root->right;
			if (treeLevel(p->right) >= treeLevel(p->left))
				root = turnLeft(root);
			else {
				root->right = turnRight(root->right);
				root = turnLeft(root);			
			}
		}	
	}
	if (root->left != nullptr) 
		updateTreeAVL(root->left);

	if (root->right != nullptr) 
		updateTreeAVL(root->right);

	// return root;
}



void deleteNode(node *&Node)
{
	if (Node != nullptr) {
		deleteNode(Node->left);
		deleteNode(Node->right);
		delete Node;
	}
}



void deleteNodeEqVal(node *&root, int val) 
{
	if (root != nullptr) {
		if (root->data == val) {
			deleteNode(root->left);
			deleteNode(root->right);
			root = nullptr;
		}
        else {
            deleteNodeEqVal(root->left, val);
            deleteNodeEqVal(root->right, val);
        }		
	}
}



int maxValue(node *root) 
{
    if (root != NULL) {
        int value, maxLeftSub, maxRightSub;

        value = root->data;
        maxLeftSub = maxValue(root->left);
        maxRightSub = maxValue(root->right);

        return max(value, max(maxLeftSub, maxRightSub));
    }  
    else
        return INT_MIN;
}



int minValue(node *root) 
{
    if (root != NULL) {
        int value, maxLeftSub, maxRightSub;

        value = root->data;
        maxLeftSub = minValue(root->left);
        maxRightSub = minValue(root->right);

        return min(value, min(maxLeftSub, maxRightSub));
    }  
    else
        return INT_MAX;
}



bool isBST(node* root) 
{
    if (root == NULL)
        return true;
    
    if ((root->left != NULL && maxValue(root->left) >= root->data) || (root->right != NULL && minValue(root->right) <= root->data))
        return false;
    
    if (!isBST(root->left) || !isBST(root->right))
        return false;
        
    return true;
}



void kthAncestor_traversal(node *root, int k, int node, vector<int> &combinations, int &kthAncestor)
{
    if (root) {
        if ((root->data == node) && (combinations.size() >= k))
            kthAncestor = combinations[combinations.size()-k];
            
        combinations.push_back(root->data);
            
        kthAncestor_traversal(root->left, k, node, combinations, kthAncestor);
        
        kthAncestor_traversal(root->right, k, node, combinations, kthAncestor);
        
        combinations.pop_back();
    }
}

/*
    combine nodes to different branches, check each branch sequentially
    if detect node, find kth ancestor of that node 
*/
int kthAncestor(node *root, int k, int node)
{
    vector<int> combinations;
    int kthAncestor = -1;
    
    kthAncestor_traversal(root, k, node, combinations, kthAncestor);
    
    return kthAncestor;
}



void LCA_traversal(node *root, int node, vector<struct node *> &ancestor)
{
    if (root) {
        ancestor.push_back(root);
        
        if (root->data == node)
            return;
            
        if (root->data < node)
            LCA_traversal(root->right, node, ancestor);
        else
            LCA_traversal(root->left, node, ancestor);
    }
}

/*
    traverse to find node1, store ancestors of node1
    traverse to find node2, store ancestors of node2
    compare 2 vectors and find LCA
*/
node *LCA(node *root, int n1, int n2)
{
    vector<node *> ancestor1, ancestor2;
    
    LCA_traversal(root, n1, ancestor1);
    
    LCA_traversal(root, n2, ancestor2);
    
    for (int i = ancestor1.size()-1; i >= 0; i--)
        for (int j = ancestor2.size()-1; j >= 0; j--)
            if (ancestor1[i]->data == ancestor2[j]->data)
                return ancestor1[i];
}



void findMedian_traversal(node *root, vector<int> &nodes) 
{
    if (root) {
        nodes.push_back(root->data);
        
        findMedian_traversal(root->left, nodes);
        
        findMedian_traversal(root->right, nodes);
    }
}

float findMedian(node *root)
{
    try {
        if (root == nullptr)
            throw ERR_EMPTY;

        vector<int> nodes;
        float median;
        int size;
        
        findMedian_traversal(root, nodes);  // traverse to store nodes
        
        sort(nodes.begin(), nodes.end());   // ascending sort
        
        size = nodes.size();                // find median
        if (size % 2 == 0)
            return (float)(nodes[size/2 - 1] + nodes[size/2]) / 2;
        else
            return nodes[(size+1)/2 - 1];
    }

    catch (const char *exc) {
        cout << exc << endl;
    }   
}



void inOrderSuccessor_traversal(node *root, vector<node *> &nodes) 
{
    if (root) {
        inOrderSuccessor_traversal(root->left, nodes);
        nodes.push_back(root);
        inOrderSuccessor_traversal(root->right, nodes);
    }
}

node * inOrderSuccessor(node *root, node *X)
{
    vector<node *> nodes;
    
    inOrderSuccessor_traversal(root, nodes);
    
    for (int i = 0; i < nodes.size(); i++)
        if (nodes[i] == X && i+1 < nodes.size())
            return nodes[i+1];
            
    return NULL;
}

/* ---------------------------------------------------------- FUNCTIONS - END ---------------------------------------------------------- */
