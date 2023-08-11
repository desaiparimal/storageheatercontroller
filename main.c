#include<stdio.h>
#include<stdlib.h>

int main(){
    char *str = NULL;
    size_t len = 0;     /* ignored when line = NULL */
    ssize_t read;

    printf ("\nEnter string below [ctrl + d] to quit\n");

    while ((read = getline(&str, &len, stdin)) != -1) {

        if (read > 0)
            printf ("\n  read %zd chars from stdin, allocated %zd bytes for line : %s\n", read, len, str);

        printf ("Enter string below [ctrl + d] to quit\n");
    }    
    return 0;
}