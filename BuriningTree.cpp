/*
to start burining from the target node, we need its neighbours..
possible neighbours are left child, right child, and parent node
we have pointer to left and right child but we donot have pointer to parent 
so we need mapping of node to node which points parent
map<node*, node*>nodeToParent
To find the target node in map we parallely find the node while inserting it into map 
initialize time=0
should have a visited arrays to confirm that node is already visited
we require BFS to process the tree
if new node is inserted in tree then we increase the time-->time++


step1:create nodeToparent mapping
step2:find targetNode
step3:burn the tree in min time

*/
class Solution {
    public:
    Node* createMapping(Node* root, int target, map<Node*, Node*>&nodeToParent)
    {
        Node* res=NULL;
        
        queue<Node*>q;
        q.push(root);
        
        nodeToParent[root]=NULL;
        
        while(!q.empty())
        {
            Node* front=q.front();
            q.pop();
            
            if(front->data==target)
                res=front;
                
            if(front->left)
            {
                nodeToParent[front->left]=front;
                q.push(front->left);
            }
            
            if(front->right)
            {
                nodeToParent[front->right]=front;
                q.push(front->right);
            }
        }
        
        return res;
    }
    
    int burnTree(Node* root, map<Node*, Node*>&nodeToParent)
    {
        map<Node*, bool>visited;
        queue<Node*>q;
        q.push(root);
        visited[root]=true;
        
        int minTime=0;
        while(!q.empty())
        {
            bool flag=0;
            int len=q.size();
            while(len--)
            {
                Node* front=q.front();
                q.pop();
                
                //burn left child
                if(front->left && !visited[front->left])
                {
                    flag=1;
                    q.push(front->left);
                    visited[front->left]=true;
                }
                //burn right child
                if(front->right && !visited[front->right])
                {
                    flag=1;
                    q.push(front->right);
                    visited[front->right]=true;
                }
                //burn parent
                if(nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    flag=1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=true;
                }
            }
            if(flag==1)
                minTime++;
        }
        return minTime;     
    }
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*>NodeToParent;
        Node* targetNode=createMapping(root, target, NodeToParent);//finds the target node in tree in 0(logn)
        
        int time=burnTree(targetNode, NodeToParent);
        return time;
    }
};