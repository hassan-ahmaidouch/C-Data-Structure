#include<stdio.h>
#include<stdlib.h>
struct node *tree;

struct node {
    int data ;
    struct node *left ;
    struct node *right ;
};




              // 1- Search Element :

struct node *search_element(struct node *tree,int val){

 if(tree == NULL || tree->data == val){

 return tree ;
 }

 else if(val< tree->data){

  return search_element(tree->left,val);
 }

 else {
  
  return search_element(tree->right,val);
 }
  
}




                 //INSERT ELEMENT IN THE BINARY SEARCH TREE 

struct node* insert(struct node* tree, int val) {
  

    if (tree == NULL) {
    tree = (struct node*)malloc(sizeof(struct node));
    tree->data = val;
    tree->left = NULL;
    tree->right = NULL;

    }
     else {
        if (val < tree->data) {
            
            tree->left = insert(tree->left, val);
        } else {
            
            tree->right = insert(tree->right, val);
        }
    }
    return tree;
}





          // largest element in BST
struct node *findLargestElement(struct node *tree){
 if( (tree == NULL) || (tree->right == NULL))
 return tree;
 else
 return findLargestElement(tree->right);
}




        // Smallest element in BST
struct node *findSmallestElement(struct node *tree){
  if( (tree == NULL) || (tree->left == NULL))
  return tree;
  else
  return findSmallestElement(tree ->left);
}




        // delete node from BST
struct node* deleteNode(struct node* tree, int val) {
    if (tree == NULL) {
        printf("VAL is not found in the tree\n");
        return tree;
    }

    if (val < tree->data) {
        tree->left = deleteNode(tree->left, val);
    } 

     else if (val > tree->data) {
        tree->right = deleteNode(tree->right, val);
     } 
     
    else {
        
        if (tree->left != NULL && tree->right != NULL) {
            struct node* temp = findLargestElement(tree->left);
            tree->data = temp->data;
            tree->left = deleteNode(tree->left, temp->data);
        }
        
         else {
            
            struct node* temp = tree;
            if (tree->left != NULL) {
                tree = tree->left;
            } else {
                tree = tree->right;
            }
            free(temp);
        }
    }
    return tree;
}





        // Function that find the height of a tree :
int Height(struct node *tree){

 int leftheight, rightheight;
  if(tree==NULL)
    return 0;

 else{
   leftheight = Height(tree->left);
   rightheight = Height(tree->right);
    if(leftheight > rightheight){
    return (leftheight + 1);
    }
   else{
  return (rightheight + 1);
   }
}
}





       //Function that count the Total node of a tree  :
int totalNodes(struct node *tree){
 
 if(tree==NULL)
 return 0;
 else
 return(totalNodes(tree->left) + totalNodes(tree->right) + 1);
}





         // Function that count the Total of internale nodes :
int totalInternalNodes(struct node *tree)
{
 if( (tree==NULL) || ((tree->left==NULL) && (tree->right==NULL)))
 return 0;
 else
 return (totalInternalNodes(tree->left)+ totalInternalNodes(tree->right) + 1);
}




         // Function that count the totale of external nodes :
int totalExternalNodes(struct node *tree){
            if(tree==NULL){
             return 0;}
            else if((tree->left==NULL) && (tree->right==NULL)){
            return 1;}
            else{
            return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
            }
}



        // Function that delete the tree :
struct node *deleteTree(struct node *tree)
{
 if(tree!=NULL)
 {
 deleteTree(tree->left);
 deleteTree(tree->right);
 free(tree);
 }
}   



int main(){
int val = 2;
struct node *ptr;

               // insertion test :
 
            tree=insert(tree,5);
            tree=insert(tree,32);
            tree=insert(tree,2);
            tree=insert(tree,83);


             
             // search test :

         ptr = search_element(tree, val);
      if (ptr != NULL) {
        printf("La valeur %d a ete trouvre.\n", val);
      } 
       else {
        printf("La valeur %d n a pas ete trouvre.\n", val);
        }

        


        // delete a node 
          tree  = deleteNode(tree, 2);




          // smalest element in the tree : 
          ptr = findSmallestElement(tree);
          printf("\n Smallest element is :%d",ptr->data);


      
      
           // largest element in the tree : 
           ptr = findLargestElement(tree);
           printf("\n Largest element is : %d", ptr->data);

           
           

           // find the hight of the tree : 
           printf("\n The height of the tree = %d",Height(tree));


                      
             // the totale nodes of the tree :
            printf("\n Total no. of nodes = %d", totalNodes(tree));





            // the totale internal nodes of a tree
            printf("\n Total  of internal nodes = %d", totalInternalNodes(tree));

           

           // the totale external nodes of a tree :
          printf("\n Total  of external nodes = %d", totalExternalNodes(tree));

          


          // delete the tree :
          tree = deleteTree(tree);


    return  0;
}