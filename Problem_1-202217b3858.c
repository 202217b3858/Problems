

#include<stdio.h>

#define MAX 20 // Corrected the max size to 20 as per array b size

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

// Global variables
int b[MAX]; // Array to hold elements
int n, pos, e, i; // Variables for size, position, element, and loop

int main()
{
    int ch;
    char g='y';
    
    do
    {
        printf("\n Main Menu");
        printf("\n 1. Create \n 2. Delete \n 3. Search \n 4. Insert \n 5. Display\n 6. Exit \n");
        printf("\n Enter your Choice: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0; // Using return instead of exit() to terminate the program
            default:
                printf(" \n Enter the correct choice:");
        }
        
        printf("\n Do you want to continue (y/n)?: ");
        scanf(" %c", &g);
    }
    while(g == 'y' || g == 'Y');
    
    return 0;
}

void create()
{
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("\n Enter the Elements:\n");
    for(i = 0; i < n; i++)
    {
        printf(" Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion()
{
    printf("\n Enter the position you want to delete: ");
    scanf("%d", &pos);
    
    if(pos >= n || pos < 0)
    {
        printf("\n Invalid Location!");
    }
    else
    {
        for(i = pos; i < n - 1; i++)
        {
            b[i] = b[i + 1];
        }
        n--;
        
        printf("\n The Elements after deletion:");
        display();
    }
}

void search()
{
    printf("\n Enter the Element to be searched: ");
    scanf("%d", &e);
    
    for(i = 0; i < n; i++)
    {
        if(b[i] == e)
        {
            printf("\n Element %d found at position %d.", e, i + 1);
            return; // Exit the function after finding the element
        }
    }
    
    printf("\n Element %d not found in the list.", e);
}

void insert()
{
    printf("\n Enter the position you need to insert: ");
    scanf("%d", &pos);
    
    if(pos > n || pos < 0)
    {
        printf("\n Invalid Location!");
    }
    else
    {
        printf("\n Enter the element to insert: ");
        scanf("%d", &e);
        
        for(i = n; i > pos; i--)
        {
            b[i] = b[i - 1];
        }
        b[pos] = e;
        n++;
        
        printf("\n The list after insertion:");
        display();
    }
}

void display()
{
    printf("\n The Elements of The list ADT are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}
