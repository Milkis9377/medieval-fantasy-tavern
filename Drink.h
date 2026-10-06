#pragma once
#include <string>
#include <vector>
#include "Recipe.h"

enum class MakingState
{
    None,
    Brewing,
    BrewDone,
    Pouring
};

enum class Drinktype{
    Alcohol,
    Juice,
    Other
};

class Drink{
    public :
        std::string name;
        int price;
        int stock;
        Drinktype type;
        MakingState state;
        int makingTimeSec;
        int brewTimeDay;
        int pouringTimeSec;
        int numberPerTime;

        std::vector<Recipe> recipes;
};