//
// Created by Cosmin on 27-Nov-19.
//

//
// Created by Cosmin on 27-Nov-19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constants.h"
#include "signup&in.h"

int isPasswordValid(char pass[], char username[]) {
    if (strlen(pass) < 7) {
        printf("%s\n", ERROR_PASSWORD_LONG);   // verify the pass length
        return 0;
    }
    if (strstr(pass, username) != NULL) {       // check if it contains the username
        printf("%s\n", ERROR_PASSWORD_NOT_USERNAME);
        return 0;
    }
    if (!strchr(pass, '.') && !strchr(pass, '_') && !strchr(pass, '!')) {
        printf("%s\n", ERROR_PASSWORD_SPECIAL_CHAR);             // check for special characters
        return 0;
    }
    for (int i = 0; i < strlen(pass); i++)           // check for digits
        if (pass[i] >= '0' && pass[i] <= '9')
            return 1;
    printf("%s\n", ERROR_PASSWORD_DIGITS);
    return 0;
}
void signUpProcess(char actualUser[], int *state, char key[])
{
    printf("%s\n", SIGNING_UP);
    FILE *f = fopen("users.txt", "r");
    fscanf(f,"%*[^\n]\n"); // discard first line in file
    int numberOfUsers, validUser = 1;
    fscanf(f,"%d\n", &numberOfUsers);
    printf("---Username\n");
    char givenUser[MAX_USERNAME];
    scanf("%[^\n]", givenUser);
    getchar();
    for(int i=0; i<numberOfUsers;i++) {
        char username[MAX_USERNAME];
        fscanf(f, "%s", username);
        if (strcmp(givenUser, username) == 0) {
            printf("%s\n", DUPLICATE_USER);
            validUser = 0;
            break;
        }
        fscanf(f,"%*[^\n]\n");
    }
    fclose(f);
    if(validUser){
        strcpy(actualUser,givenUser);
        printf("---Password\n");
        char givenPassword[MAX_PASSWORD];
        do {                                      // reading pass until is valid
            scanf("%s", givenPassword);
            getchar();
        } while (!isPasswordValid(givenPassword, givenUser));
        vinegarCipher(givenPassword,key,'e');
        f = fopen("users.txt", "a+");
        fseek(f,0,SEEK_END);
        fprintf(f,"\n%s %s", givenUser, givenPassword);
        fclose(f);
        f = fopen("users.txt", "r+");
        fseek(f,strlen(key)+2,SEEK_SET);
        fprintf(f,"%d", ++numberOfUsers); // considering the maximum number of users is 9999999999
        fclose(f);
        *state = 3;
    }
}
void signInProcess(char actualUser[], int *state, char key[])
{
    printf("%s\n", SIGNING_IN);
    printf("---Username\n");
    FILE *f = fopen("users.txt", "r");
    fscanf(f,"%*[^\n]\n"); // discard first line in file
    int numberOfUsers, userFound = 0;
    char givenUser[MAX_USERNAME], givenPassword[MAX_PASSWORD];

    scanf("%s",givenUser);
    getchar();
    fscanf(f,"%d\n", &numberOfUsers);
    for(int i=0; i<numberOfUsers;i++) {
        char username[MAX_USERNAME];
        fscanf(f,"%s", username);
        if (strcmp(username, givenUser) == 0) {
            userFound = 1;
            strcpy(actualUser,username);
            break;
        }
        fscanf(f,"%*[^\n]");
        fgetc(f);
    }
    if(userFound){
        printf("---Password\n");
        char password[MAX_PASSWORD];
        scanf("%[^\n]", givenPassword);
        getchar();
        fgetc(f); // discard the space between user and password
        fscanf(f,"%s",password);
        vinegarCipher(password,key,'d');
        if (strcmp(givenPassword, password) == 0) {
            *state = 3;
        } else {
            printf("%s\n", INCORRECT_PASSWORD);
        }
    } else {
        printf("%s\n", USER_NOT_FOUND);
        *state = 0;
    }
    fclose(f);
}
void chooseSignInOrSignUp(int *state)
{
    printf("%s\n", SIGN_IN_UP);
    printf("a) %s\n", SIGN_IN);
    printf("b) %s\n", SIGN_UP);
    char choice;
    choice = getchar();
    if (choice == 'a')
        *state = 1;
    else
        *state = 2;
    getchar();
}
void vinegarCipher(char givenString[], char key[], char encDecr) {
    char *tablow = (char *) malloc(66 * sizeof(char));
    char *copyKey = (char *) malloc(strlen(givenString) * sizeof(char));
    char result[20];
    strcpy(tablow, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!_. ");
    for (int i = 0, j = 0; i < strlen(givenString); i++, j++) {
        if (j == strlen(key))
            j = 0;
        copyKey[i] = key[j];
    }
    for (int i = 0; i < strlen(givenString); i++) {
        if (encDecr == 'e')
            result[i] = tablow[((strchr(tablow, givenString[i]) - tablow) + (strchr(tablow, copyKey[i]) - tablow)) %
                               (strlen(tablow))];
        else if (encDecr == 'd')
            result[i] = tablow[((strchr(tablow, givenString[i]) - tablow) - (strchr(tablow, copyKey[i]) - tablow) +
                                (strlen(tablow))) % (strlen(tablow))];
    }

    result[strlen(givenString)] = '\0';
    strcpy(givenString,result);
}