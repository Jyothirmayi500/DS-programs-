#include<stdio.h>
#include<stdlib.h>
struct node* insertion(struct node* root,int value);
struct node* inorder(struct node* root);
struct node* search(struct node* root,int key);
struct node* find_minimum(struct node*root);
struct node*delete(struct node*root,int x);
int max(int a,int b);
int Height(struct node*root);
struct node{
    int data;
    struct node*right;
    struct node* left;
};
struct node* root=NULL;
int main(){
    printf("Binary Search Tree \n");
    root=insertion(root,5);
    root=insertion(root,1);
    root=insertion(root,15);
    root=insertion(root,20);
    root=insertion(root,10);
    root=insertion(root,8);
    root=insertion(root,96);
    printf("\ninordered traversal is:");
    inorder(root); 
    printf("\n");
    printf("\nthe height of the tree is :%d ",Height(root));
    root=delete(root,15);
    printf("\nAfter deleting element 15  the inorder traversal is:");
    inorder(root);
    printf("\n");
    return 0;

}
struct node* insertion(struct node* root,int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->right=NULL;
    newnode->left=NULL;
    if(root==NULL)
     root=newnode;
    else{
     struct node* nodeptr=root;
     struct node* parentptr=NULL;
    while(nodeptr!=NULL){
        parentptr=nodeptr;
        if(value<nodeptr->data){
          nodeptr=nodeptr->left;
    }
    else{
        nodeptr=nodeptr->right;
    }
    }
    if(value<parentptr->data)
     parentptr->left=newnode;
    else{
     parentptr->right=newnode;
}
}
return root;
}
struct node* inorder(struct node* root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
    }
}
//function for searching
struct node* search(struct node* root,int key){
    if(root==NULL || root->data==key)
       return root;
      if(key<root->data)
     return search(root->left,key);
     else
      return search(root->right,key);
}
//function for deletion
struct node* find_minimum(struct node*root){
    if (root==NULL)
     return NULL;
    else if(root->left!=NULL)
     return find_minimum(root->left);
     return root;
}
struct node*delete(struct node*root,int x){
    if(root==NULL)
    return NULL;
    if(x>root->data)
     root->right=delete(root->right,x);
     else if(x<root->data)
      root->left=delete(root->left,x);
    else if(x==root->data){
        if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }    
else if(root->left==NULL || root->right==NULL){
    struct node*temp;
    if(root->left==NULL)
     temp=root->right;
    else
    temp=root->left;
    free(root);
    return temp;
}
else{
    struct node*temp=find_minimum(root->right);
    root->data= temp->data;
    root->right=delete(root->right,temp->data);
}
    }
return root;
}
int max(int a,int b){
    if(a>b)
     return a;
   else
    return b;  
}
int Height(struct node*root){
    int lh,rh;
    if(root==NULL)
    return 0;
    return max(Height(root->left),Height(root->right))+1;
}




