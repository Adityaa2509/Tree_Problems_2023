#include<iostream>
#include<stack>
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
        this->right = NULL;
    }
};
void build_tree_LOD(node* &root)
{
    int data;
    cout<<"Enter data for root node of tree"<<endl;
    cin>>data;
    queue<node*>q;
    root = new node(data);
    if(data == -1) return ;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        
        cout<<"Enter data for left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

         
        cout<<"Enter data for right of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
void LOD(node* root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())q.push(NULL);
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }

    }



}
int main()
{
    node* root = NULL;
    build_tree_LOD(root);
    LOD(root);
}