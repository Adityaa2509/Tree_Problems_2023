#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void build(node* &root)
{
    cout<<"Enter data for root "<<endl;
    int data;
    cin>>data;
    if(data == -1) return ;
    root = new node(data);
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();q.pop();

        int leftdata;
        cout<<"Enter data for left node of "<<temp->data<<endl;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        int rightdata;
        cout<<"Enter data for right node of "<<temp->data<<endl;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }

    }
}


void LOD(node* root)
{
    if(root == NULL)return ;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp = q.front();q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}
void traverseleft(node* root,vector<int>& ans)
{
    if((root == NULL)||(root->left == NULL && root->right == NULL))return ;

    ans.push_back(root->data);
    if(root->left)traverseleft(root->left,ans);
    else traverseleft(root->right,ans);   
return ;
}
void traverseLeaf(node* root,vector<int>& ans)
{
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL) ans.push_back(root->data);
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
return ;
}
void traverseright(node* root,vector<int>& ans)
{
    if((root == NULL)||(root->left == NULL && root->right == NULL))return ;
    if(root->right)traverseright(root->right,ans);
    else traverseright(root->left,ans);
    ans.push_back(root->data);
    return ;
}





































int main()
{
    node* root = NULL;
    build(root);
    LOD(root);
    vector<int>ans;

    //enter root
    ans.push_back(root->data);

    traverseleft(root->left,ans);
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
    traverseright(root->right,ans);







    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}






































