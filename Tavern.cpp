#include "Tavern.h"
#include "Drinkdata.h"
#include "IngredientData.h"
#include <iostream>

using namespace std;

Tavern::Tavern() {
    gold = 100;
    yesterdayGold = 100;

    raceCount = 4;
    MaxBrewing = 3;
    Brewing = 0;
    
    drinks = alldrinks;
    ingredients = allIngredient;
    SetupRecipe();

    unlockedDrink.insert(&drinks[0]);
    unlockedDrink.insert(&drinks[1]);
}

int Tavern::getGold(){
    return gold;
}

int Tavern::getDrinksCount(){
    return drinks.size();
}

int Tavern::getUnlockedDrinkCount(){
    return unlockedDrink.size();
}

void Tavern::Unlocked_Drink(Drink& d){
    unlockedDrink.insert(&d);
}

Drink& Tavern::getDrink(int index){
    return drinks[index]; 
}

int Tavern::getYesterdayGold(){
    return yesterdayGold;
}

int Tavern::getraceCount(){
    return raceCount;
}
void Tavern::UpdateGold(){
    yesterdayGold = gold;
}

bool Tavern::havestock(const Drink& d){
    if(d.stock > 0){
        return true;
    } else {
        return false;
    }
}

bool Tavern::isUnlocked(Drink& d){
    return unlockedDrink.find(&d) != unlockedDrink.end();
}

void Tavern::sellDrink(Drink& d){
        gold += d.price;
        d.stock --;
}

void Tavern::makingDrink(Drink& d){
    if(d.type == Drinktype::Alcohol && (Brewing == MaxBrewing)){
        cout << "There's no space to brew!" << endl;
        return;
    } else if(d.type == Drinktype::Alcohol){
        d.stock += 20;
        Brewing++;
    } else if(d.type == Drinktype::Other){
        d.stock += 20;
    } else if(d.type == Drinktype::Juice){
        d.stock += 20;
    } else {
        cout << "Invalid choice!" << endl;
        return;
    }
}

const std::set<Drink*>& Tavern::getunlockedDrink(){
    return unlockedDrink;
}

int Tavern::getDrinkIndex(Drink& d){
    for(int i = 0; i < drinks.size(); i++){
        if(&drinks[i] == &d){
            return i;
        }
    }

    return -1;
}

bool Tavern::finishing(int choice){
    int index = choice - 1;
    if(index < 0 || index >= brewing.size()){
        return false;
    }
    if(brewing[index].drinks->state == MakingState::BrewDone){
        brewing[index].drinks->stock += brewing[index].drinks->numberPerTime;
        Brewing--;
        brewing.erase(brewing.begin() + index); 
        return true;
    } else {
        return false;
    }
}

void Tavern::SetupRecipe(){
    for (Drink& drink : drinks)
    {
        for (Recipe& recipe : drink.recipes)
        {
            for (Ingredient& ingredient : ingredients)
            {
                if (recipe.ingredient->name == ingredient.name)
                {
                    recipe.ingredient = &ingredient;
                    break;
                }
            }
        }
    }
}

Ingredient* Tavern::getIngredient(const string& name){
    for (Ingredient& ingredient : ingredients)
    {
        if (ingredient.name == name)
        {
            return &ingredient;
        }
    }

    return nullptr;
}