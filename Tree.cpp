#include <iostream>
#include <math.h>
using namespace std;



#define ERR_EMPTY "Tree is empty !"



struct node {
	int data;
	node *left;
	node *right;
};

struct tree {
	node *root;
};



node *insert(node *leaf, int data) {
	if (leaf == NULL) {
		node *temp = new node;
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} 
    else
		if (data < leaf->data) 
			leaf->left = insert(leaf->left, data);
		else
			leaf->right = insert(leaf->right, data);
}



tree *createTree(int n) {
	int data, i;
	tree *t = new tree;
    t->root = NULL;
    
	for (i = 0; i < n; i++) {
        cout << "Enter data of node: ";
		cin >> data;
        t->root = insert(t->root, data);
    }

	return t;
}



void printInOrderTree(node *root) {
	if (root != NULL) {
		printInOrderTree(root->left);
		cout << root->data << " ";
		printInOrderTree(root->right);
	}
}

void printPreOrderTree(node *root) {
	if (root != NULL) {
		cout << root->data << " ";
		printPreOrderTree(root->left);
		printPreOrderTree(root->right);
	}
}

void printPostOrderTree(node *root) {
	if (root != NULL) {
		printPostOrderTree(root->left);
		printPostOrderTree(root->right);
		cout << root->data << " ";
	}
}



void countLeafNode(node *root, int &count) {
	if (root != NULL) {
		count++;
		countLeafNode(root->left, count);
		countLeafNode(root->right, count);
	}
}

void countNodeEqValue(node *root, int val, int &count) {
	if (root != NULL) {
		if (root->data == val)
			count++;
		countNodeEqValue(root->left, val, count);
		countNodeEqValue(root->right, val, count);
	}
}



int treeLevel(node *root) {
	if (root == NULL)
		return -1;
	if (root->left == NULL && root->right == NULL)
		return 0;
	else 
		return 1 + max(treeLevel(root->left), treeLevel(root->right));
}



// The AVL tree checks the levels of the left and right subtrees and makes sure that the difference between them is not greater than 1
bool isAVL(node *root) {
	return (abs(treeLevel(root->left) - treeLevel(root->right)) > 1) ? false : true;
}

// https://codelearn.io/learning/data-structure-and-algorithms/887692
node *turnRight(node *oldRoot) {
	node *newRoot = oldRoot->left;
	node *rightSub = newRoot->right;
	oldRoot->left = rightSub;
	newRoot->right = oldRoot;
	return newRoot;
}

node *turnLeft(node *oldRoot) {
	node *newRoot = oldRoot->right;
	node *leftSub = newRoot->left;
	oldRoot->right = leftSub;
	newRoot->left = oldRoot;
	return newRoot;
}

node *updateTreeAVL(node *root) {
	node *leftSub = root->left, *rightSub = root->right;

	if (!isAVL(root)) {
		if (treeLevel(leftSub) > treeLevel(rightSub)) {
			if (treeLevel(leftSub->left) >= treeLevel(leftSub->right))
				root = turnRight(root);
			else {
				leftSub = turnLeft(leftSub);
				root = turnRight(root);
			}
		} 
		else {
			if (treeLevel(rightSub->right) >= treeLevel(rightSub->left))
				root = turnLeft(root);
			else {
				rightSub = turnRight(rightSub);
				root = turnLeft(root);			
			}
		}	
	}

	if (leftSub != NULL) 
		leftSub = updateTreeAVL(leftSub);

	if (rightSub != NULL) 
		rightSub = updateTreeAVL(rightSub);
	
	return root;
}



void deleteNode(node *leaf) {
	if (leaf != NULL) {
		deleteNode(leaf->left);
		deleteNode(leaf->right);
		delete leaf;
	}
}

node *deleteNodeEqVal(node *root, int val) {
	if (root != NULL) {
		if (root->data == val) {
			deleteNode(root->left);
			deleteNode(root->right);
			root = NULL;
		}
		else if (root->data > val) 
			root->left = deleteNodeEqVal(root->left, val);
		else 
			root->right = deleteNodeEqVal(root->right, val);		
	}
	return root;
}



int main() {
	tree *tr = new tree;
	tr->root = NULL;
	int n, opt, cntLeaf, val, cntVal;

	while (1) {
        cout << " -------------- MENU ------------- " << endl;
        cout << "0. Quit" << endl;
        cout << "1. Create tree" << endl;
        cout << "2. Display in-order tree" << endl;
        cout << "3. Display pre-order tree" << endl;
        cout << "4. Display post-order tree" << endl;
        cout << "5. Display the number of nodes" << endl;
        cout << "6. Display the level of tree" << endl;
        cout << "7. Check AVL" << endl;
        cout << "8. Convert to AVL tree" << endl;
        cout << "9. Display the number of nodes equal to value" << endl;
        cout << "10. Delete nodes equal to value" << endl;
        cout << "Enter your option: ";
        cin >> opt;

		if (tr->root == NULL && opt > 1 && opt < 11) {
			cout << ERR_EMPTY << endl;
			continue;
		}

        switch (opt)
        {
            case 0:
                return 0;
            case 1:
                cout << "Enter the number of nodes: ";
				cin >> n; 
				tr = createTree(n);
                break;
            case 2:
                cout << "In-order traversal: ";
				printInOrderTree(tr->root);
				cout << endl;
                break;
            case 3:
                cout << "Pre-order traversal: ";
				printPreOrderTree(tr->root);
				cout << endl;
                break;
            case 4:
                cout << "Post-order traversal: ";
				printPostOrderTree(tr->root);
				cout << endl;
                break;
			case 5:
				cntLeaf = 0;
				countLeafNode(tr->root, cntLeaf);
				cout << "The number of nodes: " << cntLeaf << endl;
				break;
			case 6:
				cout << "The level of tree: " << treeLevel(tr->root) << endl;
				break;
			case 7:
				if (isAVL(tr->root))
					cout << "This tree is AVL tree" << endl;
				else
					cout << "This tree is not AVL tree" << endl;
				break;
			case 8:
				while(!isAVL(tr->root)) 
					tr->root = updateTreeAVL(tr->root);
				break;
			case 9:
				cntVal = 0;
				cout << "Enter the value to count: ";
				cin >> val;
				countNodeEqValue(tr->root, val, cntVal);
				cout << "The number of nodes equal to " << val << ": " << cntVal << endl;
				break;
			case 10:
				cout << "Enter the value to delete: ";
				cin >> val;
				tr->root = deleteNodeEqVal(tr->root, val);
				break;
            default:
                cout << "Invalid option !" << endl;
                break;
        }
    }

    return 0;
}