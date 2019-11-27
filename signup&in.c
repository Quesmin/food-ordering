//
// Created by Cosmin on 27-Nov-19.
//

//
// Created by Cosmin on 27-Nov-19.
//
#include <stdio.h>
#include <string.h>
#include "constants.h"

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
void signUpProcess(char username[], char password[], int *state)
{
    printf("%s\n", SIGNING_UP);
    printf("---Username\n");
    char givenUser[20];
    scanf("%[^\n]", givenUser);
    getchar();
    if (strcmp(givenUser, username) == 0) {
        printf("%s\n", DUPLICATE_USER);
    } else {
        strcpy(username, givenUser);
        printf("---Password\n");
        char givenPassword[20];
        do {                                      // reading pass until is valid
            scanf("%[^\n]", givenPassword);
            getchar();
        } while (!isPasswordValid(givenPassword, username));
        strcpy(password,givenPassword);
        *state = 3;
    }
}
void signInProcess(char username[], char password[], int *state)
{
    printf("%s\n", SIGNING_IN);
    printf("---Username\n");
    char givenUser[20];
    scanf("%[^\n]", givenUser);
    getchar();
    if (strcmp(username, givenUser) == 0) {
        printf("---Password\n");
        char givenPassword[20];
        scanf("%[^\n]", givenPassword);
        getchar();
        if (strcmp(givenPassword, password) == 0) {
            *state = 3;
        } else {
            printf("%s\n", INCORRECT_PASSWORD);
        }
    } else {
        printf("%s\n", USER_NOT_FOUND);
        *state = 0;
    }
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
