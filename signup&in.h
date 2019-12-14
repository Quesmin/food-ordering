//
// Created by Cosmin on 27-Nov-19.
//

#ifndef FOOD_ORDERING_SIGNUP_IN_H
#define FOOD_ORDERING_SIGNUP_IN_H

void vinegarCipher(char givenString[], char key[], char encDecr);
int isPasswordValid(char pass[], char username[]);
void signUpProcess(char username[], int *state, char key[]);
void signInProcess(char username[], int *state, char key[]);
void chooseSignInOrSignUp(int *state);


#endif //FOOD_ORDERING_SIGNUP_IN_H
