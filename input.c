//
// Created by Cosmin on 05-Nov-19.
//
#include <stdio.h>

void getUserCredentials (char username[], char password[], int *state)
{
    printf("--Username:\n");
    gets(username);
    printf("--Password:\n");
    gets(password);

    (*state)++;
}

int getChoiceIndex(int noOfFoodTypes, int *state)
{
    int choice;
    choice = getchar();
    getchar();
    if(choice == 'a' + noOfFoodTypes)
    {
        (*state)--;
    }
    else
        (*state)++;
    return choice - 'a';
}

void getAdditionalInfo(char AddInfo[], int *state)
{
    printf("Any additional info?\n");
    gets(AddInfo);
    (*state)++;
}