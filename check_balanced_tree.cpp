#include<iostream>
#include<queue>
#include<stack>
#include<utility>
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
int height(node* root)
{
    if(root == NULL)return 0;
    int lefti = height(root->left);
    int righti = height(root->right);
    return max(lefti,righti)+1;
}
pair<bool,int> balanced(node* root)
{
    if(root == NULL)
    {
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    pair<bool,int> lefti = balanced(root->left);
    pair<bool,int> righti = balanced(root->right);
    
    bool lans = lefti.first;
    bool rans = righti.first;
    bool cond = abs(lefti.second-righti.second)<=1;

    pair<bool,int>resu;
    resu.first = (lans&&rans&&cond);
    resu.second = max(lefti.second,righti.second)+1;

    return resu;
}
int main()
{
    node* root = NULL;
    build_tree_LOD(root);
    LOD(root);
    pair<bool,int>ans = balanced(root);
    if(ans.first)cout<<"Balanced"<<endl;
    else cout<<"Not Balanced"<<endl;
    cout<<ans.second;
}