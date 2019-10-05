#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "bst.h"


int main()
{
Tree bst = tree_new();
Tree *tree = &bst;
tree = add_node(tree,100);
tree = add_node(tree,70);
tree = add_node(tree,30);
tree = add_node(tree,50);
tree = add_node(tree,10);
tree = add_node(tree,20);

assert(tree->count == 6);

assert(lookup(tree,50)==1);
assert(lookup(tree,90)==0);

tree = delete_node(tree,30);
assert(tree->count == 5);



//in-order, pre-order, post-order
printf("In-order: ");
tree_inorder(tree);
printf("\nPre-order: ");
tree_preorder(tree);
printf("\nPost-order: ");
tree_postorder(tree);


//max and min element in BST

assert(find_min(tree)==10);
assert(find_max(tree)==100);

//display elements in ascending order
printf("\n");
printf("Ascending Order: ");
tree_ascending(tree);

//display elements in descending order

printf("\n");
printf("Descending Order: ");
tree_descending(tree);



return 0 ;

}
