cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food_ordering main.c input.h input.c option.h option.c order.h order.c constants.h signup&in.c signup&in.h buyer.c buyer.h food.h food.c drinks.h drinks.c)