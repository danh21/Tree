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
void printInOrderTree(node *root);



/**
 * @brief root is visited first, then left subtree and finally right subtree
 * 
 * @param root 
 */
void printPreOrderTree(node *root);



/**
 * @brief left subtree is visited first, then right subtree and finally root
 * 
 * @param root 
 */
void printPostOrderTree(node *root);



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
 * @brief Right view of a Binary Tree is set of nodes visible when tree is viewed from right side. 
 * 
 * https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
 * 
 * @param root 
 * @param rightViewNodes contains nodes visible when tree is viewed from right side.
 * @param level original level (0)
 */
void rightViewTraversal(node *root, vector<int> &rightViewNodes, int level);



/**
 * @brief left view of a Binary Tree is set of nodes visible when tree is viewed from left side.
 * 
 * @param root 
 * @param leftViewNodes 
 * @param level 
 */
void leftViewTraversal(node *root, vector<int> &leftViewNodes, int level);



/**
 * @brief find maximum data of tree
 * 
 * @param root 
 * @return int 
 */
int maxValue(node *root);



/**
 * @brief find miximum data of tree
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



void printInOrderTree(node *root) 
{
	if (root != nullptr) {
		printInOrderTree(root->left);
		cout << root->data << " ";
		printInOrderTree(root->right);
	}
}



void printPreOrderTree(node *root) 
{
	if (root != nullptr) {
		cout << root->data << " ";
		printPreOrderTree(root->left);
		printPreOrderTree(root->right);
	}
}



void printPostOrderTree(node *root)
{
	if (root != nullptr) {
		printPostOrderTree(root->left);
		printPostOrderTree(root->right);
		cout << root->data << " ";
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



void rightViewTraversal(node *root, vector<int> &rightViewNodes, int level)
{
    if (root != nullptr) {
        if (level == rightViewNodes.size())
            rightViewNodes.push_back(root->data);
        
        rightViewTraversal(root->right, rightViewNodes, level+1);
        
        rightViewTraversal(root->left, rightViewNodes, level+1);
    }
}



void leftViewTraversal(node *root, vector<int> &leftViewNodes, int level)
{
    if (root != nullptr) {
        if (level == leftViewNodes.size())
            leftViewNodes.push_back(root->data);
        
        leftViewTraversal(root->left, leftViewNodes, level+1);
        
        leftViewTraversal(root->right, leftViewNodes, level+1);
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
/* ---------------------------------------------------------- FUNCTIONS - END ---------------------------------------------------------- */
