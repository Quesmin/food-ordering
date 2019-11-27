//
// Created by Cosmin on 05-Nov-19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

int getFoodOptionsNumber(char *line) {
    int count = 0;
    for (int i = 0; i < strlen(line); i++)
        if (line[i] == ')')
            count++;

    return count;
}
void readFoodType(char *save, FILE *f)
{
    int i=0;
    char c = fgetc(f);
    while(c!=' ')
    {
        save[i++] = c;
        c = fgetc(f);
    }
    save[--i] = '\0';
}

void getFoodAndPrice(char *Line, char *FoodOption[], double FoodPrice[])
{
    int OkBegin = 0;
    int i=0, k=0, Options =0;
    while(i < strlen(Line))
    {
        if(Line[i] == '(') {
            OkBegin = 1; Options++; k=0; // we count every option
            i++;
            continue;
        }
        if(OkBegin == 1)
        {
            // reading the food option
            FoodOption[Options-1] = (char*)malloc(MAX_FOOD_OPTION_NAME * sizeof(char));
            while(Line[i] != '-')
            {
                FoodOption[Options-1][k++] = Line[i++];
            }
            FoodOption[Options-1][k-1] = '\0';
            i = i+2; // jump over "- "
            char Number[20];
            k=0;
            while(Line[i] != ')')
            {
                Number[k++] = Line[i++];
            }
            Number[k] = '\0';
            sscanf(Number,"%lf",&FoodPrice[Options-1]);
            OkBegin = 0;

        }
        i++;

    }
}

void getDrinksAndPrice(char *Line, char *Drinks[], double DrinkPrices[])
{
    int i=0;
    int NoOfDrinkOptions = 0;
    while(i<strlen(Line))
    {
        char Data[50];
        int k=0;
        NoOfDrinkOptions++;
        while(Line[i] != ')')
        {
            Data[k++] = Line[i++];
        }
        Data[k++] = Line[i++];
        Data[k++] = '\0';
        Drinks[NoOfDrinkOptions-1] = (char *)malloc(MAX_DRINK_NAME * sizeof(char));
        sscanf(Data,"(%s - %lf)", Drinks[NoOfDrinkOptions-1], &DrinkPrices[NoOfDrinkOptions-1]);
        i = i+2;
    }
}
void userCredentialsStep (char username[], char password[], int *state)
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

void getAdditionalInfo(char AddInfo[])
{
    printf("Any additional info?\n");
    gets(AddInfo);
}