#include<stdio.h>
#include<stdlib.h>

int main(){

    system("gcc helperFunction.h -o helperFunction");
    system("gcc readFile.h -o readFile");
    system("gcc encrypt.h -o encrypt");
    system("gcc writeFile.h -o writeFile");
    system("gcc decrypt.h -o decrypt");
    system("gcc masterFile.c -o masterFile -lm");
    
    char choice;

    do{
        system("cls");
        printf("\n(1) Encrypt\n");
        printf("(2) Decrypt\n");
        printf("(3) Show File\n");
        printf("(4) Exit\n");
        printf("\nEnter your choice: ");
        choice = getchar();
        getchar();

        switch(choice){
            case '1':
                system("cls");
                printf("(1) Without Substitution\n");
                /* printf("(2) Substitution\n"); */
                printf("\nEnter choice for Encryption Technique: ");
                choice = getchar();
                getchar();
                if(choice == '1'){
                    system("cls");
                    system("masterFile textFile.txt encrypt.txt ENCRYPT 1");
                    printf("\nPress [Enter] to contineu... ");
                    getchar();
                    getchar();
                }
                /* else if(choice == '2'){
                    system("cls");
                    system("masterFile textFile.txt encrypt.txt ENCRYPT 2");
                    printf("\nPress [Enter] to contineu... ");
                    getchar();
                    getchar();
                } */
                else{
                    system("cls");
                    printf("Invalid Choice!!!\n");
                    printf("\nPress [Enter] to contineu... ");
                    getchar();
                    getchar();
                }
                break;

            case '2':
                system("cls");
                printf("(1) Without Substitution\n");
                /* printf("(2) Substitution\n"); */
                printf("\nEnter choice for Decryption Technique: ");
                choice = getchar();
                getchar();
                if(choice == '1'){
                    system("cls");
                    system("masterFile encrypt.txt decrypt.txt DECRYPT 1");
                    printf("\nPress [Enter] to contineu... ");
                    getchar();
                    getchar();
                }
                /* else if(choice == '2'){
                    system("cls");
                    system("masterFile encrypt.txt decrypt.txt DECRYPT 2");
                    printf("\nPress [Enter] to contineu... ");
                    getchar();
                    getchar();
                } */
                else{
                    system("cls");
                    printf("Invalid Choice!!!\n");
                    printf("\nPress [Enter] to contineu... ");
                    getchar();
                    getchar();
                }
                break;

            case '3':
                system("cls");
                printf("(1) Text File\n");
                printf("(2) Encrypted File\n");
                printf("(3) Decrypted File\n");
                printf("\nEnter choice for Display: ");
                choice = getchar();
                getchar();
                switch(choice){
                    case '1':
                        system("cls");
                        system("type textFile.txt");
                        printf("\n\nPress [Enter] to contineu... ");
                        getchar();
                        getchar();
                        break;
                    case '2':
                        system("cls");
                        system("type encrypt.txt");
                        printf("\n\nPress [Enter] to contineu... ");
                        getchar();
                        getchar();
                        break;
                    case '3':
                        system("cls");
                        system("type decrypt.txt");
                        printf("\n\nPress [Enter] to contineu... ");
                        getchar();
                        getchar();
                        break;
                    default:
                        system("cls");
                        printf("Invalid Choice!!\n");
                        printf("\n\nPress [Enter] to contineu... ");
                        getchar();
                        getchar();
                        break;
                }
                break;
            case '4':
                break;
            default:
                system("cls");
                printf("Invalid Choice!!!\n");
                printf("\nPress [Enter] to contineu... ");
                getchar();
                getchar();
                break;

        }

    }while(choice!='4');


    return EXIT_SUCCESS;

}