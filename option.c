//
// Created by Cosmin on 05-Nov-19.
//
#include <stdio.h>
#include "constants.h"

void printFoodTypes(int noOfFoodTypes, char **FoodType)
{
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<noOfFoodTypes;i++)
    {
        putchar('a'+i);
        printf(") %s\n", FoodType[i]);
    }
    printf("%c) Go back\n", 'a'+noOfFoodTypes);
}

void printFoodOptions(int noOfFoodOptions[], double **FoodPrice, char ***FoodOption, int Food)
{
    for(int i=0; i<noOfFoodOptions[Food]; i++)
    {
        putchar('a'+i);
        printf(") %s: %.2f RON\n", FoodOption[Food][i], FoodPrice[Food][i]);
    }
    putchar('a' + noOfFoodOptions[Food]);
    printf(") Go back\n");
}

void printDrinkOptions(int noOfDrinks, double *DrinkPrice, char **Drinks)
{
    for(int i=0; i<noOfDrinks; i++)
    {
        putchar('a'+i);
        printf(") %s: %.2f RON\n", Drinks[i], DrinkPrice[i]);
    }
    putchar('a'+ noOfDrinks);
    printf(") No, thanks!\n");

    putchar('a' + noOfDrinks +1);
    printf(") Go back\n");
}

void printCutleryOptions()
{
    printf("Do you want cutlery?\n");
    printf("a) Yes\n");
    printf("b) No, thanks!\n");
    printf("c) Go back\n");
}