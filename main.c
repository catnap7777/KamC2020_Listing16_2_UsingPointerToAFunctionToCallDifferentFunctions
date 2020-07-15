//Listing 16.2 Using a pointer to a function to call different functions; p 389

#include <stdio.h>

//function prototypes
void func1(int x);
void one(void);
void two(void);
void other(void);

int main(void)
{
    int nbr;

    for(;;)  //<-- endless loop
    {
        puts("\nEnter an integer between 1 and 10, 0 to exit: ");
        scanf("%d", &nbr);

        if(nbr == 0)
            break;
        func1(nbr);
    }
}

void func1(int val)
{
   //the pointer to the function
    void (*ptr)(void);

    if(val ==1)
        ptr = one;
    else if(val == 2)
        ptr = two;
    else
        ptr = other;

    ptr(); //<-- function call using ptr which has address of one, two, or other functions
}

void one(void)
{
    puts("You entered 1.");
}

void two(void)
{
    puts("You entered 2.");
}

void other(void)
{
    puts("You entered something other than 1 or 2.");
}
