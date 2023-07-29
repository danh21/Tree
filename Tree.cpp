#include <bits/stdc++.h>
#include "Tree.h"
using namespace std;



int main() {
	tree *Tree = new tree;
	int nums, opt, cnt, val, k;
	vector<int> nodes;

	while (1) {
        cout << "\n\n" << " ---------------------------- MENU --------------------------- " << endl;
        cout << "0. Quit" << endl;
        cout << "1. Create tree" << endl;
        cout << "2. Create binary tree" << endl;
        cout << "3. Display in-order tree" << endl;
        cout << "4. Display pre-order tree" << endl;
        cout << "5. Display post-order tree" << endl;
        cout << "6. Display spiral-order tree" << endl;
		cout << "7. Display nodes visible in right view of tree" << endl;
        cout << "8. Display nodes visible in left view of tree" << endl;
        cout << "9. Display the number of nodes" << endl;
        cout << "10. Display the level of tree" << endl;
        cout << "11. Check AVL" << endl;
        cout << "12. Convert to AVL tree" << endl;
        cout << "13. Display the number of nodes equal to value" << endl;
        cout << "14. Delete nodes equal to value" << endl;        
		cout << "15. Check Binary Search Tree" << endl;
		cout << "16. Display kth ancestor of any node" << endl;
		cout << "17. Display median" << endl;
        cout << "Enter your option: ";
        cin >> opt;

        switch (opt)
        {
            case 0:
                return 0;
            case 1:
                cout << "Enter the quantity: ";
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
				printInOrder(Tree->root);
                break;
            case 4:
                cout << "Pre-order traversal: ";
				printPreOrder(Tree->root);
                break;
            case 5:
                cout << "Post-order traversal: ";
				printPostOrder(Tree->root);
                break;
			case 6:
                cout << "Spiral-order traversal: ";
				printSpiralOrder(Tree->root);
                break;
			case 7:
				printRightView(Tree->root, nodes, 0);
				nodes.clear();
				break;
			case 8:
				printLeftView(Tree->root, nodes, 0);
				nodes.clear();
				break;
			case 9:
				cnt = 0;
				countLeafNode(Tree->root, cnt);
				cout << "The number of nodes: " << cnt;
				break;
			case 10:
				cout << "The level of tree: " << treeLevel(Tree->root);
				break;
			case 11:
				if (isAVL(Tree->root))
					cout << "This tree is AVL tree";
				else
					cout << "This tree is not AVL tree";
				break;
			case 12:
				while (!isAVL(Tree->root)) 
					updateTreeAVL(Tree->root);
				break;
			case 13:
				cnt = 0;
				cout << "Enter the value to count: ";
				cin >> val;
				countNodeEqValue(Tree->root, cnt, val);
				cout << "The number of nodes equal to " << val << ": " << cnt;
				break;
			case 14:
				cout << "Enter the value to delete: ";
				cin >> val;
				deleteNodeEqVal(Tree->root, val);
				break;
			case 15:
				if (isBST(Tree->root))
					cout << "This tree is a binary search tree";
				else
					cout << "This tree is not a binary search tree";
				break;
			case 16:
				cout << "Enter data of node: ";
				cin >> val;
				cout << "Enter k: ";
				cin >> k; 
				if (kthAncestor(Tree->root, k, val) == -1)
					cout << "Kth ancestor of node: NULL";
				else
					cout << "Kth ancestor of node: " << kthAncestor(Tree->root, k, val);
				break;
			case 17:
				cout << "Median of tree: " << findMedian(Tree->root);
				break;
            default:
                cout << "Invalid option !";
                break;
        }
    }

    return 0;
}