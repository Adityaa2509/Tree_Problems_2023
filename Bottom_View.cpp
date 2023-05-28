#include<iostream>
#include<queue>
#include<map>
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
    cout<<"Enter data for root"<<endl;
    int data ;
    cin>>data;
    if(data==-1)return ;
    root = new node(data);

    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"Enter data for left node of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter data for right node of "<<temp->data<<endl;
        int rightdata;
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

void Bootom_View(node* root)
{
    if(root == NULL)return ;
    map<int,int>mp;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        auto it = q.front();q.pop();
        
        node* temp = it.first;
        int line = it.second;
        
        mp[line] = temp->data;

        if(temp->left)q.push({temp->left,line-1});
        if(temp->right)q.push({temp->right,line+1});
    }

    cout<<"Bottom View of Binary Tree is :- ";
    for(auto it : mp)
    {
        cout<<it.second<<" ";

    }
cout<<endl;
}

int main()
{
    
    node* root = NULL;
    
    build(root);
    LOD(root);

    Bootom_View(root);

}
