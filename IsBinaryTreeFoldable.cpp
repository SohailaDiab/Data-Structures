/*---------------------------------------------------------------------------------

Program to check if a binary tree is foldable or not.

A binary tree is foldable if the left subtree and right subtree are mirror images
of each other. An empty tree is also foldable.

---------------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

struct TreeNode{
    int info;
    TreeNode *llink;
    TreeNode *rlink;

    TreeNode() : info(0), llink(nullptr), rlink(nullptr) {}
    TreeNode(int x) : info(x), llink(nullptr), rlink(nullptr) {}
};

class Solution{
public:
    // recursive function to traverse the left and right
    // tree and see if they are mirror images
    bool isMirror(TreeNode *p, TreeNode*q){
        // if the end of both trees are reached at the
        // same time then they are mirror images
        if(p == NULL && q==NULL)
            return true;

        // if reached the end of *only one* tree, then
        // they are not mirror
        if(p == NULL || q == NULL)
            return false;

        if( (isMirror(p->rlink, q->llink)) && isMirror(p->llink, q->rlink) )
            return true;
        else
            return false;

    }
////////////////////////////////////////////////
    bool isFoldable(TreeNode *p){
        // return true if tree is empty
        if(p == NULL)
            return true;

        // return true if there is only one node
        else if(p->rlink == NULL && p->llink == NULL)
            return true;

        // if, from the root, there is no right node but there is a left node
        // or there is no left node but there is a right one
        // return false
        else if( (p->rlink == NULL && p->llink !=NULL) || (p->llink == NULL && p->rlink !=NULL))
            return false;

        // else go to isMirror function to traverse through
        // the left subtree and the right subtree to check if they are mirror
        // images of each other
        else{
            bool x = isMirror(p->llink, p->rlink);
            return x;
        }
    }
};

int main()
{
    Solution s;
    // -- TEST CASES --

    cout<<" - - - Program to check if a tree is foldable - - - "<<endl;

    // TEST CASE 1
    cout<<endl;
    cout<<"Test Case 1:"<<endl;

    cout<<"     1    "<<endl;
    cout<<"  /     \\"<<endl;
    cout<<" 4       2"<<endl;
    cout<<"  \\     /"<<endl;
    cout<<"   5   3"<<endl;
    // Tree 1
    TreeNode *root1 = new TreeNode(1);
    root1->llink = new TreeNode(4);
    root1->rlink = new TreeNode(2);
    root1->llink->rlink = new TreeNode(5);
    root1->rlink->llink = new TreeNode(3);

    if(s.isFoldable(root1))
        cout<<"This tree is foldable."<<endl;
    else
        cout<<"This tree is not foldable."<<endl;


    // TEST CASE 2
    cout<<endl;
    cout<<"Test Case 2:"<<endl;

    cout<<"     1    "<<endl;
    cout<<"   /   \\"<<endl;
    cout<<"  2     3"<<endl;
    cout<<" /       \\"<<endl;
    cout<<"4         5"<<endl;
    // Tree 2
    TreeNode *root2 = new TreeNode(1);
    root2->llink = new TreeNode(2);
    root2->rlink = new TreeNode(3);
    root2->llink->llink = new TreeNode(4);
    root2->rlink->rlink = new TreeNode(5);

    if(s.isFoldable(root2))
        cout<<"This tree is foldable."<<endl;
    else
        cout<<"This tree is not foldable."<<endl;


    // TEST CASE 3
    cout<<endl;
    cout<<"Test Case 3:"<<endl;

    cout<<"     1    "<<endl;
    cout<<"   /   \\"<<endl;
    cout<<"  2     3"<<endl;
    cout<<" / \\     \\"<<endl;
    cout<<"4   6     5"<<endl;
    // Tree 3
    TreeNode *root3 = new TreeNode(1);
    root3->llink = new TreeNode(2);
    root3->rlink = new TreeNode(3);
    root3->llink->llink = new TreeNode(4);
    root3->llink->rlink = new TreeNode(6);
    root3->rlink->rlink = new TreeNode(5);

    if(s.isFoldable(root3))
        cout<<"This tree is foldable."<<endl;
    else
        cout<<"This tree is not foldable."<<endl;


    // TEST CASE 4
    cout<<endl;
    cout<<"Test Case 4:"<<endl;

    cout<<"     1    "<<endl;
    cout<<"   /   \\"<<endl;
    cout<<"  2     3"<<endl;
    cout<<" / \\   / \\"<<endl;
    cout<<"4   5 6   7"<<endl;
    // Tree 4
    TreeNode *root4 = new TreeNode(1);
    root4->llink = new TreeNode(2);
    root4->rlink = new TreeNode(3);
    root4->llink->llink = new TreeNode(4);
    root4->llink->rlink = new TreeNode(5);
    root4->rlink->rlink = new TreeNode(6);
    root4->rlink->llink = new TreeNode(7);

    if(s.isFoldable(root4))
        cout<<"This tree is foldable."<<endl;
    else
        cout<<"This tree is not foldable."<<endl;


    // TEST CASE 5
    cout<<endl;
    cout<<"Test Case 5:"<<endl;

    cout<<"Empty Tree"<<endl;
    // Tree 5
    TreeNode *root5 = new TreeNode();

    if(s.isFoldable(root5))
        cout<<"This tree is foldable."<<endl;
    else
        cout<<"This tree is not foldable."<<endl;


    // TEST CASE 6
    cout<<endl;
    cout<<"Test Case 6:"<<endl;

    cout<<"     1    "<<endl;
    cout<<"   /   \\"<<endl;
    cout<<"  2     3"<<endl;
    cout<<" / \\   / \\"<<endl;
    cout<<"4   5 6   7"<<endl;
    cout<<"           \\"<<endl;
    cout<<"            8"<<endl;
    // Tree 6
    TreeNode *root6 = new TreeNode(1);
    root6->llink = new TreeNode(2);
    root6->rlink = new TreeNode(3);
    root6->llink->llink = new TreeNode(4);
    root6->llink->rlink = new TreeNode(5);
    root6->rlink->rlink = new TreeNode(6);
    root6->rlink->llink = new TreeNode(7);
    root6->rlink->llink->rlink = new TreeNode(8);

    if(s.isFoldable(root6))
        cout<<"This tree is foldable."<<endl;
    else
        cout<<"This tree is not foldable."<<endl;

    return 0;
}
