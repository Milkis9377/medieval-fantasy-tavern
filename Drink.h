#pragma once
#include <string>

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
};