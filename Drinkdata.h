#include <vector>
#include "Drink.h"
const std::vector<Drink> alldrinks
{
    {"Beer", 5, 10, Drinktype::Alcohol, MakingState::None, 10, 1, 3, 20},
    {"Water", 1, 10, Drinktype::Other, MakingState::None, 5, 0, 1, 10},
    {"Apple Juice", 10, 0, Drinktype::Juice, MakingState::None, 20, 0, 2, 15}
};