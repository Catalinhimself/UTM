#include "bin_tree.h"

int main()
{
    srand(time(NULL));
    printf("__main__\n");
    bin_test();
    
    tree*root=NULL; 
    list* tail = NULL;
    list* head = NULL;

    int order = 0;
    int option = 666;
    while(option)
    {
    option = menu();
    
    switch (option)
        {
        case 1:            
        {
            realty temp = get_realty(++order);
            grow_tree(&root, temp);
            break;               
        }
        case 11:
        {
            realty temp = generate_realty(++order);
            grow_tree(&root, temp);
            break;
        }
        case 21:
                if (isnt_tree_root(root))
                    break;  
                printf("inordine\n");
                inorder(root); 
                break;
        case 22:
                if (isnt_tree_root(root))
                    break;  
                printf("preordine\n");
                preorder(root);
                break;
        case 23: 
                if (isnt_tree_root(root))
                    break;  
                printf("postordine\n");
                postorder(root);
                break;
        case 2:
                if (isnt_tree_root(root))
                    break;
                append_to_queue(root, 0, &tail);
                head = tail;
                levels(head, &tail);
                print_levels(root);
                printf("numarul de noduri: %d\n",count_list_nodes(head));
                break;
        case 3:
        {   
           if (isnt_tree_root(root))
                 break;
            printf("elementul cautat (dupa pret)\n");    
            int key;
            scanf("%d",&key);
            tree*found = search_node(root,key);
            if (!found){
                printf("nu exista asa nod\n");
                break;
            }         
            
            if (found->left)
                if(found->left->immovable.price == key)
                    found = found->left;
            if (found->right)
                if (found->right->immovable.price == key)
                    found = found->right;
            while(found->immovable.price == key){
            put_realty(found->immovable);
            if (found->left==NULL)
                break;
            found=found->left;
            }
            break;
        }
        case 4:
        {   
           if (isnt_tree_root(root))
                 break;
            printf("elementul cautat pentru modificare (dupa pret)\n");    
            int key;
            scanf("%d",&key);
            tree*found = search_node(root,key);
            if (!found){
                printf("nu exista asa nod\n");
                break;
            }

            tree * sub_tree = NULL; 
            if (found->immovable.price != key)
            {
            if (found->left)
                if(found->left->immovable.price == key)
                {
                    sub_tree = found->left;
                    found->left=NULL;
                    found = sub_tree;
                }
            if (found->right)
                if (found->right->immovable.price == key)
                {
                    sub_tree = found->right;
                    found->right=NULL;
                    found = sub_tree;
                }
            }
            else
            {
                sub_tree = found;
                root = NULL;
            }

            while(sub_tree->immovable.price == key)
            {
                modify_node(sub_tree);    
                if (sub_tree->left==NULL)
                    break;
                sub_tree=sub_tree->left;
            }
            preorder_grow(&root,found);
            postorder_free_lite(&found);
            break;
        }
        case 5:
            append_to_queue(root, 0, &tail);
            head = tail;
            levels(head, &tail);
            printf("numarul de noduri: %d\n",count_list_nodes(head));
            break;
        case 6:
           if (isnt_tree_root(root))
               break;
            printf("inaltimii arborelui este: %d\n",print_levels(root));
            break;
        case 7:
            free_list(&head);
            postorder_free(&root);
            order = 0;
            break;
        }
    }
    return 0;
}
