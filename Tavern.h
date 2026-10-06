#pragma once

#include <vector>
#include <set>
#include "Drink.h"
#include "Ingredient.h"
#include "Production.h"

class Tavern{
    private :
        int gold;
        int yesterdayGold;
        int raceCount;
        int MaxBrewing;
        int Brewing;

        std::vector<Drink> drinks;
        std::vector<Ingredient> ingredients;
        std::set<Drink*> unlockedDrink;
        std::set<Drink*> choosedDrink;
        std::vector<Production> brewing;

    public :
        Tavern();

        int getGold();
        int getDrinksCount();
        int getUnlockedDrinkCount();
        int getYesterdayGold();
        int getraceCount();
        int getDrinkIndex(Drink&);

        
        Drink& getDrink(int);
        Ingredient* getIngredient(const std::string&);
        const std::set<Drink*>& getunlockedDrink();


        bool havestock(const Drink&);
        bool isUnlocked(Drink&);
        bool finishing(int);


        void sellDrink(Drink&);
        void makingDrink(Drink&);
        void Unlocked_Drink(Drink&);
        void UpdateGold();
        void SetupRecipe();


};