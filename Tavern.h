#pragma once

#include <vector>
#include <set>
#include "Drink.h"
#include "Ingredient.h"

class Tavern{
    private :
        int gold;
        int yesterdayGold;
        int raceCount;
        std::vector<Drink> drinks;
        std::vector<Ingredient> ingredients;
        std::set<Drink*> unlockedDrink;
        std::set<Drink*> choosedDrink;

    public :
        Tavern();

        int getGold();
        int getDrinksCount();
        int getUnlockedDrinkCount();
        int getYesterdayGold();
        int getraceCount();
        int getDrinkIndex(Drink&);
        Drink& getDrink(int);
        const std::set<Drink*>& getunlockedDrink();
        bool havestock(const Drink&);
        bool isUnlocked(Drink&);
        void sellDrink(Drink&);
        void makingDrink(Drink&);
        void Unlocked_Drink(Drink&);
        void Update();
};