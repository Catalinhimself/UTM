#include "bin_tree.h"

int main()
{
    srand(time(NULL));
    printf("__main__\n");

    bin_test();
//   put_realty(get_realty()); 
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
            char c = 'c';
            while (c=='c'||c=='a')
            {   
                realty temp;
                if (c=='c')
                    temp = get_realty(++order);
                if (c =='a')
                    temp = generate_realty(++order);
                grow_tree(&root, temp);
                printf("\ncontinuati/ autocompletare/ stop [c/a/s] ");
                scanf(" %c",&c);
            }

            break;               
        }
        case 2:{           
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
                printf("numarul de noduri: %d\n",count_list_nodes(head));
                break;
            }
            break;}
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
            while(found->immovable.price == key){
            modify_node(found);    
            if (found->left==NULL)
                break;
            found=found->left;
            }
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
            break;
        }
    }
    return 0;
}
