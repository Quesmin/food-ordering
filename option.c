//
// Created by Cosmin on 05-Nov-19.
//
#include <stdio.h>
#include "constants.h"
#include "food.h"
#include "drinks.h"

void printFoodTypes(foodType f)
{
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<f.noOfFoodTypes;i++)
    {
        putchar('a'+i);
        printf(") %s\n", f.foodType[i]);
    }
    printf("%c) Go back\n", 'a'+f.noOfFoodTypes);
}

void printFoodOptions(specificFood food, int Food)
{
    for(int i=0; i<food.noOfFoodOptions[Food]; i++)
    {
        putchar('a'+i);
        printf(") %s: %.2f RON\n", food.foodOption[Food][i], food.foodPrice[Food][i]);
    }
    putchar('a' + food.noOfFoodOptions[Food]);
    printf(") Go back\n");
}

void printDrinkOptions(drinks d)
{
    for(int i=0; i<d.noOfDrinks; i++)
    {
        putchar('a'+i);
        printf(") %s: %.2f RON\n", d.Drinks[i], d.drinkPrice[i]);
    }
    putchar('a'+ d.noOfDrinks);
    printf(") No, thanks!\n");

    putchar('a' + d.noOfDrinks +1);
    printf(") Go back\n");
}

void printCutleryOptions()
{
    printf("Do you want cutlery?\n");
    printf("a) Yes\n");
    printf("b) No, thanks!\n");
    printf("c) Go back\n");
}