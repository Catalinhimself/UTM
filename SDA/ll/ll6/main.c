#include "bin_tree.h"

int main()
{
    printf("__main__\n");

    bin_test();
   
    tree*root=NULL; 

    grow_tree(&root,5);
    grow_tree(&root,3);
    grow_tree(&root,6);
    grow_tree(&root,4);
    grow_tree(&root,2);
   
    printf("inordine\n");
    inorder(root); 

    printf("preordine\n");
    preorder(root);

    printf("postorder\n");
    postorder(root);
    
    printf("elementul cautat\n");    

    print_node(search_node(root,6));    

    //modify_node(search_node(root,3));    


    return 0;
}
