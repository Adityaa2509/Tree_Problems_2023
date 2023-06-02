#include<iostream>
#include<stack>
#include<queue>
#include<math.h>
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
void build(node* &root)
{
    int data;
    cin>>data;
    if(data == -1)return ; 
    root = new node(data);
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();q.pop();
        cout<<"Enter data for left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata !=-1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
          cout<<"Enter data for right of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata !=-1)
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
        node* temp = q.front();q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }
        else
        {cout<<temp->data<<" ";
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);

        }
    }
}
int height(node* root)
{
   if(root == NULL)return 0;
   int lefti = height(root->left);
    int righti = height(root->right);
    return max(lefti,righti)+1;
   
}
int main()
{
    node* root = NULL;
    build(root);
    LOD(root);
    //int height = 0;
    cout<<height(root);
    //cout<<cnt;
}










