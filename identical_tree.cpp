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
        this->right = NULL;
    }
};
void build(node* &root)
{
    cout<<"Enter data for root of tree "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1)return ;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

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
    if(root == NULL) return ;
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
        else{
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}
bool identical(node* root1,node* root2)
{
    if(root1 == NULL && root2 == NULL)return true;
    if(root1 == NULL && root2 != NULL)return false;
    if(root1 != NULL && root2 == NULL)return false;
        bool lefti  = identical(root1->left,root2->left);
        bool righti  = identical(root1->right,root2->right);
        bool cond = root1->data ==  root2->data;
        return (lefti && righti && cond);

}




int main()
{
    cout<<"first"<<endl;
    node* root1 = NULL;
    build(root1);
    LOD(root1);
 cout<<"second"<<endl;
    node* root2 = NULL;
    build(root2);
    LOD(root2);
if(identical(root1,root2))cout<<"Identical hai dono"<<endl;
else cout<<"Identical nahi hai dono"<<endl;

}


