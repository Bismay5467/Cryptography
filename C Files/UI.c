#include<stdio.h>
#include<stdlib.h>

int main(){

    system("gcc helperFunction.h -o helperFunction");
    system("gcc readFile.h -o readFile");
    system("gcc encrypt.h -o encrypt");
    system("gcc writeFile.h -o writeFile");
    system("gcc decrypt.h -o decrypt");
    system("gcc masterFile.c -o masterFile");
    system("clear");

    char choice;
    printf("(1) Without Substitution\n");
    printf("(2) Substitution\n");
    printf("Enter choice of Encryption Technique: ");
    scanf("%c", &choice);
    fflush(stdin);

    switch(choice){
        case '1':
            system("./masterfile ../Text\\ Files/textFile.txt ../Text\\ Files/encrypt.txt ENCRYPT 1");
            printf("Wanna Decrypt? : ");
            scanf("%c", &choice);
            if(choice == 'Y')
                system("./masterfile ../Text\\ Files/encrypt.txt ../Text\\ Files/decrypt.txt DECRYPT 1");
            break;
        
        case '2':
            system("./masterfile ../Text\\ Files/textFile.txt ../Text\\ Files/encrypt.txt ENCRYPT 2");
            printf("Wanna Decrypt? : ");
            scanf("%c", &choice);
            if(choice == 'Y')
                system("./masterfile ../Text\\ Files/encrypt.txt ../Text\\ Files/decrypt.txt DECRYPT 2");
            break;
        default:
            printf("Invalid Choice!\n");
            break;
    }   



    return EXIT_SUCCESS;

}