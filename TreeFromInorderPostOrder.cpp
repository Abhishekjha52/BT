//Problem Link-https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

void createMapping(int in[], map<int, int>&NodeToIndex, int n)
{
    for(int i=0;i<n;i++)
    {
        NodeToIndex[in[i]]=i;
    }
}
Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int, int>&NodeToIndex)
{
    //base case
    //if index is out of preorder array or inorderStart>inorderEnd then return NULL;
    if(index<0 || inorderStart>inorderEnd)
        return NULL;
        
    //eelement which is root 
    int element=post[index--];//update index here only for next iteration
    Node* root=new Node(element);//make element as root
    
    //search that element in inorder array
    int position=NodeToIndex[element];
    
    root->right=solve(in, post, index, position+1, inorderEnd, n, NodeToIndex);
    root->left=solve(in, post, index, inorderStart, position-1, n, NodeToIndex);
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex=n-1;
    map<int, int>NodeToIndex;
    createMapping(in, NodeToIndex, n);
    Node* ans=solve(in, post, postOrderIndex, 0, n-1, n, NodeToIndex);
    return ans;
}
