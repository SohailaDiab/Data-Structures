/*---------------------------------------------------------------------------------

Program to check if 2 trees are identical or not,
given their roots.

Two binary trees are considered the same if they are structurally identical,
and the nodes have the same value.

---------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)const{
        // in order traversing
        if(p!=NULL && q!=NULL){
            isSameTree(p->left, q->left);

            // compare between the values of both nodes,
            // return false if they are different (non identical trees)
            if(p->val != q->val || ( (p==NULL && q!=NULL) || (q==NULL &&p!=NULL)))
                return false;

            isSameTree(p->right, q->right);
        }
        // returns true if reached the end of the tree (p and q are NULL)
        // meaning that both trees were traversed and did not come across different values and
        // both trees are the same size (identical trees)
        if(p==NULL && q==NULL)
            return true;
    }
};

int main()
{
    Solution s;
    // -- TEST CASES --

    cout<<" - - - Program to check if 2 trees are identical - - - "<<endl;

    // TEST CASE 1
    cout<<endl;
    cout<<"Test Case 1:"<<endl;
    cout<<"Input: p = [1,2,3], q = [1,2,3]"<<endl;
    // Tree 1
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    // Tree 2
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    if(s.isSameTree(root1, root2))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;


    // TEST CASE 2
    cout<<endl;
    cout<<"Test Case 2:"<<endl;
    cout<<"Input: p = [1,2], q = [1,null,2]"<<endl;
    // Tree 1
    TreeNode *root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    // Tree 2
    TreeNode *root4 = new TreeNode(1);
    root4->left = new TreeNode(NULL);
    root4->right = new TreeNode(2);

    if(s.isSameTree(root3, root4))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;


    // TEST CASE 3
    cout<<endl;
    cout<<"Test Case 3:"<<endl;
    cout<<"Input: p = [1,2,1], q = [1,1,2]"<<endl;
    // Tree 1
    TreeNode *root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(1);
    // Tree 2
    TreeNode *root6 = new TreeNode(1);
    root6->left = new TreeNode(1);
    root6->right = new TreeNode(2);

    if(s.isSameTree(root5, root6))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;


    return 0;
}
