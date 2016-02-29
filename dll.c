#include <stdio.h>
#include <stdlib.h>
// linked list implementation in C language by Mouzakitis Nikolaos.March 2016.

struct kombos {
    int data;
    struct kombos *pre;
    struct kombos *next;
} ;

void create(struct kombos *p)
{
    int data;

    if ( p->next == NULL)
    {
        struct kombos *new;
        new = malloc(sizeof(struct kombos));
        printf("Enter first integer to insert to the list: ");
        scanf("%d",&data);
        printf("\n");
        // DEBUG        printf("[debug]Data to insert: %d\n",data);

        new->data = data;
        p->next = new;

        new->next = NULL;
        new->pre = p;
    }
    else
    {

        struct kombos *new,*seeker;

        new = malloc(sizeof(struct kombos));
        seeker = malloc(sizeof(struct kombos));

        seeker = p;

        printf("Enter integer to insert to the list: ");
        scanf("%d",&data);
        printf("\n");
        new->data = data;
        //DEBUG         printf("[debug]line2 %d\n",seeker->link->data);

        while(seeker->next != NULL)
        {
            seeker = seeker->next;
        }
        seeker->next = new;
        new->next = NULL;
        new->pre = seeker;

    }

    printf("Operation complete.\n");
}


void print_nodes(struct kombos *p)
{

    if(p->next == NULL)
        printf("List is empty.\n");

    printf("Linked list: ");

    p= p->next;

    while(p->next != NULL)
    {
        printf("%3d ",p->data);
        p = p->next;
    }
    printf("%3d \n",p->data);
}



void delete(struct kombos *p)
{
        struct kombos *seeker;

        seeker = malloc(sizeof(struct kombos));

        seeker = p;
        if(p->pre == NULL)
                printf("Unable to delete.\n");
        else
        {
                while(seeker->next != NULL)
                        seeker = seeker->next;
                printf("Deleting element %d\n",seeker->data);

                seeker = seeker->pre;
                seeker->next = NULL;
        }

}


int main(void)
{
    struct kombos arxh;
    struct kombos *p;
    int ch;

    p=malloc(sizeof(struct kombos));
    p = &arxh;

    arxh.next = NULL;
    arxh.pre = NULL;

    while(1)
    {

        printf("1.create a new node.\n2.exit\n3.print existing nodes data.\n4.Delete last input.\n");
        scanf("%d",&ch);
        switch(ch) {
        case 1 :
            create(p);
            break;
        case 2 :
            exit(0);

        case 3 :
            print_nodes(p);
            break;
        case 4 :
            delete(p);
            break;
        default :
            break;
        }
    }

    return 0;
}
