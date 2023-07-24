#include <bits/stdc++.h>
#include "Tree.h"
using namespace std;



int main() {
	tree *Tree = new tree;
	int nums, opt, cnt, val;
	vector<int> nodes;

	while (1) {
        cout << endl << " ---------------------------- MENU --------------------------- " << endl;
        cout << "0. Quit" << endl;
        cout << "1. Create tree" << endl;
        cout << "2. Create binary tree" << endl;
        cout << "3. Display in-order tree" << endl;
        cout << "4. Display pre-order tree" << endl;
        cout << "5. Display post-order tree" << endl;
        cout << "6. Display the number of nodes" << endl;
        cout << "7. Display the level of tree" << endl;
        cout << "8. Check AVL" << endl;
        cout << "9. Convert to AVL tree" << endl;
        cout << "10. Display the number of nodes equal to value" << endl;
        cout << "11. Delete nodes equal to value" << endl;
        cout << "12. Display nodes visible in right view of tree" << endl;
        cout << "13. Display nodes visible in left view of tree" << endl;
		cout << "14. Check Binary Search Tree" << endl;
        cout << "Enter your option: ";
        cin >> opt;

        switch (opt)
        {
            case 0:
                return 0;
            case 1:
                cout << "Enter the number of nodes: ";
				cin >> nums; 
				createTree(Tree->root, nums);
                break;
			case 2:
                cout << "Enter the number of nodes: ";
				cin >> nums; 
				createBinaryTree(Tree->root, nums);
                break;
            case 3:
                cout << "In-order traversal: ";
				printInOrderTree(Tree->root);
				cout << endl;
                break;
            case 4:
                cout << "Pre-order traversal: ";
				printPreOrderTree(Tree->root);
				cout << endl;
                break;
            case 5:
                cout << "Post-order traversal: ";
				printPostOrderTree(Tree->root);
				cout << endl;
                break;
			case 6:
				cnt = 0;
				countLeafNode(Tree->root, cnt);
				cout << "The number of nodes: " << cnt << endl;
				break;
			case 7:
				cout << "The level of tree: " << treeLevel(Tree->root) << endl;
				break;
			case 8:
				if (isAVL(Tree->root))
					cout << "This tree is AVL tree" << endl;
				else
					cout << "This tree is not AVL tree" << endl;
				break;
			case 9:
				while (!isAVL(Tree->root)) 
					updateTreeAVL(Tree->root);
				break;
			case 10:
				cnt = 0;
				cout << "Enter the value to count: ";
				cin >> val;
				countNodeEqValue(Tree->root, cnt, val);
				cout << "The number of nodes equal to " << val << ": " << cnt << endl;
				break;
			case 11:
				cout << "Enter the value to delete: ";
				cin >> val;
				deleteNodeEqVal(Tree->root, val);
				break;
			case 12:
				rightViewTraversal(Tree->root, nodes, 0);
				for (int val : nodes)
					cout << val << " ";
				cout << endl;
				nodes.clear();
				break;
			case 13:
				leftViewTraversal(Tree->root, nodes, 0);
				for (int val : nodes)
					cout << val << " ";
				cout << endl;
				nodes.clear();
				break;
			case 14:
				if (isBST(Tree->root))
					cout << "This tree is a binary search tree" << endl;
				else
					cout << "This tree is a not binary search tree" << endl;
				break;
            default:
                cout << "Invalid option !" << endl;
                break;
        }
    }

    return 0;
}