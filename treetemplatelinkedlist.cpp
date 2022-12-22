#include <bits/stdc++.h>
using namespace std;
  
class TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;
  
    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildtree(){

  int d; 
  cin>>d;
  TreeNode*root;
  if(d==-1){
    return NULL;
  }
  root=new TreeNode(d);
  root->left=buildtree();
  root->right=buildtree();
  return root;
}

void print(TreeNode* root)
{
    if(root==NULL)
    {
        return ;
    }
   cout<<root->data<<" ";
   print(root->left);
   print(root->right);
}



int main()
{

   int n ;
   TreeNode *root= buildtree();
   return 0; 

}
