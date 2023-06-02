#include<iostream>
#include<queue>
#include<stack>
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
node* build_tree(node* root)
{
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1)return NULL;

    cout<<"Enter data for left of "<<data<<endl;
    root->left = build_tree(root->left);
    cout<<"Enter data for right of "<<data<<endl;
    root->right = build_tree(root->right);
return root;
}
void inorder(node* root)
{
    stack<node*>st;
    node* curr = root;
    while(true)
    {
        if(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        else
        {
            if(st.empty())break;
            curr = st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
}





int main()
{
    node* root = NULL;
    root = build_tree(root);
    inorder(root);
}










