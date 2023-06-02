#include<iostream>
#include<queue>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right=  NULL;
    }
};
node* build_tree(node* root)
{
//cout<<"Enter Data"<<endl;
int data;
cin>>data;
root = new node(data);
if(data == -1)return NULL;

cout<<"Enter data for left of "<<data<<endl;
root->left = build_tree(root->left);

cout<<"Enter data for right of "<<data<<endl;
root->right=build_tree(root->right);

return root;
}


void LOD(node* root)
{
    if(root == NULL)return ;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
}














int main()
{
    node* root = NULL;
    root = build_tree(root);
    LOD(root);
}