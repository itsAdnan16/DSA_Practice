#include<iostream>
using namespace std;
class Node
{   
    public:
    int data;
    Node * left;
    Node * right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node * build_tree(){
    int data;
    cout<<"Enter the data for the root node"<<endl;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    Node * root = new Node(data);
    cout<<"Enter the data for the left Node "<<data<<endl;
    root->left = build_tree();
    cout<<"Enter the data for the right Node "<<data<<endl;
    root -> right = build_tree();
    return root;

}
int main(){
    Node * root = build_tree();
}