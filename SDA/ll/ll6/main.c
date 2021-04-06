#include "bin_tree.h"

int main()
{
    printf("__main__\n");

    bin_test();
   
    tree*root=NULL; 
    list* tail = NULL;
    list* head = NULL;

    int option = 666;
    while(option)
    {
    option = menu();
    
    switch (option)
        {
        case 1:            
        {
            char c = 'y';
            int order = 0;
            while (c=='y')
            {
                grow_tree(&root,read_node(++order));
                printf("continuati? [y/n] ");
                scanf(" %c",&c);
            }

            break;               
        }
        case 2:           
           if (isnt_tree_root(root))
              break; 
            printf("optiuni de afisare a nodurilor\n");
            printf("1. inordine\n");
            printf("2. preordine\n");
            printf("3. postordine\n");
            printf("4. dupa nivele\n");
            int print;
            scanf("%d",&print);
            switch (print)
            {
            case 1:
                printf("inordine\n");
                inorder(root); 
                break;
            case 2:
                printf("preordine\n");
                preorder(root);
                break;
            case 3: 
                printf("postordine\n");
                postorder(root);
                break;
            case 4:
                append_to_queue(root, 0, &tail);
                head = tail;
                levels(head, &tail);
                print_levels(root);
                break;
            }
            break;
        case 3:
        {
           if (isnt_tree_root(root));
               break;
            printf("elementul cautat\n");    
            int data;
            scanf(" %d",&data);
            tree*found = search_node(root,data);
            if (!found){
                printf("nu exista asa nod\n");
                break;
            }
            print_node(found);    
            break;
        }
        case 4:
        {   
           if (isnt_tree_root(root))
                 break;
            printf("elementul cautat pentru modificare\n");    
            int data;
            scanf("%d",&data);
            tree*found = search_node(root,data);
            if (!found){
                printf("nu exista asa nod\n");
                break;
            }
            modify_node(found);    
            break;
        }
        case 5:
            printf("numarul de noduri: %d\n",count_list_nodes(head));
            break;
        case 6:
           if (isnt_tree_root(root))
               break;
            printf("inaltimii arborelui este: %d\n",print_levels(root));
            break;
        case 7:
            free_list(&head);
            break;
        }
    }
    return 0;
}
