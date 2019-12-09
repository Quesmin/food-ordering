//
// Created by Cosmin on 05-Nov-19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

void readFoodTypeAndNo(char **food, int *number, FILE *f)
{
    int i=0;
    char c = fgetc(f);
    while(c!=' ')
    {
        (*food)[i++] = c;
        c = fgetc(f);
    }
    (*food)[i] = '\0';
    c = fgetc(f);
    i = 0;
    char noTypes[5];
    while(c!=' ')
    {
        noTypes[i++] = c;
        c = fgetc(f);
    }
    sscanf(noTypes,"%d:", &(*number));

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

void getDrinksAndPrice(char *Line, char ***Drinks, double **DrinkPrices)
{
    int i=1; //discard the first brace
    int NoOfDrinkOptions = 0;
    while(i<strlen(Line))
    {
        NoOfDrinkOptions++;
        int k=0;
        (*Drinks)[NoOfDrinkOptions-1] = (char *)malloc(MAX_DRINK_NAME * sizeof(char));
        while(Line[i] != '-')
        {
            (*Drinks)[NoOfDrinkOptions-1][k++] = Line[i++];
        }
        (*Drinks)[NoOfDrinkOptions-1][k] = Line[i++];
        (*Drinks)[NoOfDrinkOptions-1][--k] = '\0';
        char number[10];
        k = 0;
        while(Line[i] != ')')
        {
            number[k++] = Line[i++];
        }
        number[k] = Line[i++];
        number[k] = '\0';
        sscanf(number," %lf", &(*DrinkPrices)[NoOfDrinkOptions - 1]);
        i = i+3; // jump over ", ("
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
void storeFoodAndPricesFromInput(int **NoOfFoodOptions, char ***FoodType, char ****FoodOption, double ***FoodPrice, int NoOfFoodTypes, FILE *f)
{
    *NoOfFoodOptions = (int *) malloc(NoOfFoodTypes * sizeof(int));
    *FoodType = (char **) malloc(NoOfFoodTypes * sizeof(char *));
    *FoodOption = (char ***) malloc(NoOfFoodTypes * sizeof(char **));
    *FoodPrice = (double **) malloc(NoOfFoodTypes * sizeof(double *));
    for (int i = 0; i < NoOfFoodTypes; i++) {
        (*FoodType)[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
        readFoodTypeAndNo(&(*FoodType)[i],&(*NoOfFoodOptions)[i], f);
        char Line[100];
        fscanf(f, "%[^\n]", Line);
        fgetc(f);
        (*FoodOption)[i] = (char **) malloc((*NoOfFoodOptions)[i] * sizeof(char *));
        (*FoodPrice)[i] = (double *) malloc((*NoOfFoodOptions)[i] * sizeof(double));
        getFoodAndPrice(Line, (*FoodOption)[i], (*FoodPrice)[i]);
    }
}
void storeDrinksAndPricesFromInput(char ***Drinks, int NoOfDrinks, double **DrinkPrice, int *NoOfDrinkOptions, FILE *f)
{
    *Drinks = (char **) malloc(NoOfDrinks * sizeof(char *));
    *DrinkPrice = (double *) malloc(NoOfDrinks * sizeof(double));
    char Line[100];
    fscanf(f, "%[^\n]", Line); // same process as the above
    fgetc(f);
    getDrinksAndPrice(Line, Drinks, DrinkPrice);
    *NoOfDrinkOptions = NoOfDrinks + 1;
}