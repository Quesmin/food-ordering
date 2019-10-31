#include <stdio.h>

int main() {
    printf("Welcome to Food Thingies!\nPlease sign in to continue!\n");
    char username[20];
    char password[20];
    char AddInfo[100];
    int Food, Type, Drink, Cutlery, choice;



    int state = 0;
    int orderPlaced = 0;
    int noOfFoodTypes = 3;
    int noOfDrinks = 4;
    char FoodType[3][10] = {"Pizza", "Pasta", "Salad"};
    char Drinks[4][10] = {"Coca-Cola", "Fanta", "Lipton", "Water"};
    double DrinkPrice[] = {5,5,5,4};
    int noOfFoodOptions[3] = {3,2,4};
    char FoodOption[3][4][50] = {
            {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita" },
            {"Chicken alfredo", "Mac&Cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}
    };
    double FoodPrice[3][4] = {
            {21,23,19},
            {23,21},
            {23,22,19,21}
    };


    while(!orderPlaced)
    {
        switch (state)
        {
            case(0):
            {
                printf("--Username:\n");
                gets(username);
                printf("--Password:\n");
                gets(password);

                state++;
                break;
            }
            case(1):
            {
                printf("Please choose the food you feel like eating today:\n");
                for(int i=0;i<noOfFoodTypes;i++)
                {
                    putchar('a'+i);
                    printf(") %s\n", FoodType[i]);
                }
                printf("%c) Go back\n", 'a'+noOfFoodTypes);
                choice = getchar();
                getchar();
                if(choice == 'a' + noOfFoodTypes)
                {
                    state--;
                    break;
                }
                Food = choice - 'a';
                state++;
                break;
            }
            case(2):
            {
                printf("Please choose the type of %s:\n", FoodType[Food]);
                for(int i=0; i<noOfFoodOptions[Food]; i++)
                {
                    putchar('a'+i);
                    printf(") %s: %.2f RON\n", FoodOption[Food][i], FoodPrice[Food][i]);
                }
                putchar('a' + noOfFoodOptions[Food]);
                printf(") Go back\n");
                choice = getchar();
                getchar();
                if(choice == 'a' + noOfFoodOptions[Food])
                {
                    state--;
                    break;
                }
                Type = choice - 'a';
                state++;
                break;
            }
            case(3):
            {
                printf("Please choose a drink to go with your %s:\n", FoodType[Food]);
                for(int i=0; i<noOfDrinks; i++)
                {
                    putchar('a'+i);
                    printf(") %s: %.2f RON\n", Drinks[i], DrinkPrice[i]);
                }
                putchar('a'+ noOfDrinks);
                printf(") No, thanks!\n");

                putchar('a' + noOfDrinks +1);
                printf(") Go back\n");

                choice = getchar();
                getchar();

                if(choice =='a' + noOfDrinks + 1)
                {
                    state--;
                    break;
                }
                Drink = choice - 'a';
                state++;
                break;
            }
            case(4):
            {
                printf("Do you want cutlery?\n");
                printf("a) Yes\n");
                printf("b) No, thanks!\n");
                printf("c) Go back\n");

                choice = getchar();
                getchar();

                if(choice == 'a' + 2)
                {
                    state--;
                    break;
                }
                Cutlery = choice - 'a';
                state++;
                break;
            }
            case(5):
            {
                printf("Any additional info?\n");
                gets(AddInfo);
                state++;
                break;
            }
            case(6):
            {
                printf("This is your order:\n");
                printf("-------------------\n");
                printf("Name: %s\n", username);
                printf("Food items:\n");
                printf("---%s: %.2f RON\n", FoodOption[Food][Type], FoodPrice[Food][Type]);
                if(Drink != noOfDrinks)
                    printf("---%s: %.2f RON\n", Drinks[Drink],DrinkPrice[Drink]);
                if(Cutlery == 0)
                    printf("Cutlery: yes\n");
                else
                    printf("Cutlery: no\n");
                double total = 0;
                if(AddInfo[0] != '\0' && AddInfo[0] != '\n')
                    printf("Additional info: \"%s\"\n", AddInfo);
                if(Drink == noOfDrinks)
                    total = FoodPrice[Food][Type];
                else
                    total = FoodPrice[Food][Type] + DrinkPrice[Drink];
                printf("Payment amount: %.2f RON\n", total);
                printf("-------------------\n");
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                choice = getchar();
                getchar();
                if(choice == 'a' + 1)
                {
                    state = 4;
                    break;
                }
                orderPlaced = 1;
                break;


            }
        }
    }
    printf("Order confirmed! Thank you for buying from us, %s!", username);
    return 0;
}