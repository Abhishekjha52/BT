//Problem Link-https://practice.geeksforgeeks.org/problems/construct-tree-1/1

int findPos(int in[], int element, int n)//O(N)
{
    for(int i=0;i<n;i++)
    {
        if(in[i]==element)
            return i;
    }
    return -1;
}
Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
{
    //base case
    //if index is out of preorder array or inorderStart>inorderEnd then return NULL;
    if(index>=n || inorderStart>inorderEnd)
        return NULL;
        
    //eelement which is root 
    int element=pre[index++];//update index here only for next iteration
    Node* root=new Node(element);//make element as root
    
    //search that element in inorder array
    int position=findPos(in, element, n);
    
    root->left=solve(in, pre, index, inorderStart, position-1, n);
    root->right=solve(in, pre, index, position+1, inorderEnd, n);
    
    return root;
}
Node* buildTree(int in[],int pre[], int n)
{
    int preOrderIndex=0;
    Node* ans=solve(in, pre, preOrderIndex, 0, n-1, n);
    return ans;
}

//We can find the position of element in inorder array by mapping nodes to its index using map


void createMapping(int in[], map<int, int>&NodeToIndex, int n)
{
    for(int i=0;i<n;i++)
    {
        NodeToIndex[in[i]]=i;
    }
}
Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int>&NodeToIndex)
{
    //base case
    //if index is out of preorder array or inorderStart>inorderEnd then return NULL;
    if(index>=n || inorderStart>inorderEnd)
        return NULL;
        
    //eelement which is root 
    int element=pre[index++];//update index here only for next iteration
    Node* root=new Node(element);//make element as root
    
    //search that element in inorder array
    int position=NodeToIndex[element];//O(1)
    
    root->left=solve(in, pre, index, inorderStart, position-1, n, NodeToIndex);
    root->right=solve(in, pre, index, position+1, inorderEnd, n, NodeToIndex);
    
    return root;
}
Node* buildTree(int in[],int pre[], int n)
{
    int preOrderIndex=0;
    map<int, int>NodeToIndex;
    createMapping(in, NodeToIndex, n);
    Node* ans=solve(in, pre, preOrderIndex, 0, n-1, n, NodeToIndex);
    return ans;
}













