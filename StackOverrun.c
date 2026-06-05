#include <stdio.h>
#include <string.h>
void foo(const char *input)
{
    char buf[10];
    // What? No extra arguments supplied to printf?
    // It’s a cheap trick to view the stack 8-)
    // We’ll see this trick again when we look at format strings.
    printf("My stack looks like :\n%p\n%p\n%p\n%p\n%p\n%p\n\n");
    printf("Address of my buf:\n %x\n\n", buf);
    // Pass the user input straight to secure code public enemy #1.
    strcpy(buf, input);
    printf(" %s\n\n", buf);
    printf("Now the stack looks like:\n%p\n%p\n%p\n%p\n%p\n%p\n\n");
}

void bar(void)
{
    printf("Augh !I’ve been hacked !\n\n");
}

int main(int argc, char *argv[])
{
    // Blatant cheating to make life easier on myself
    printf("Address of main is:\n %p\n\n", main); 
    printf("Address of foo =\n %p\n\n", foo);
    printf("Address of bar =\n %p\n\n", bar);
    if (argc != 2)
    {
        printf("Please supply a string as an argument!\n\n");
        return -1;
    }
    foo(argv[1]);
    return 0;
}
