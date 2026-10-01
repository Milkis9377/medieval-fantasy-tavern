#include <iostream>
#include <chrono>
#include <thread>
#include "Tavern.h"
#include "Customer.h"
#include "HumanCustomer.h"
#include "ElfCustomer.h"
#include "DwarfCustomer.h"

using namespace std;

int main(){ 
    Tavern tavern; 
    cout << "Do you have a dream?" << endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    cout << "A dream of striking it rich......" << endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    cout << "Then......" << endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));

    cout << "\n===Welcome to the Tavern!===" << endl; 
    cout << "Gold: " << tavern.getGold() << endl; 
 
    for(int i=0; i < tavern.getUnlockedDrinkCount() ; i++){ 
        cout<< tavern.getDrink(i).name << ": "  
            << tavern.getDrink(i).stock  
            << " price: " << tavern.getDrink(i).price  
            << endl; 
    } 
 
    int command; 
    command = 0; 
    int day = 1; 
    int count = 0; 
 
    cout << "Enter a command." << endl; 
    cout << "1. Serve a customer" << endl; 
    cout << "2. Make something" << endl; 
    cout << "3. Exit" << endl; 
    cout << "~~~Day " << day << "~~~"<< endl; 
     
    cin >> command; 
 
    while(command != 3){ 
        int bre = 0; 
        switch(command) 
        { 
            case 1 : 
            { 
                int r = rand() % tavern.getraceCount(); 
                Customer* customer = nullptr; 
                if(r <= 1){ 
                    customer = new HumanCustomer(); 
                    cout << "A human entered the tavern." << endl; 
                    cout << "Customer: " ; 
                } else if(r == 2){ 
                    customer = new ElfCustomer(); 
                    cout << "An elf entered the tavern." << endl; 
                    cout << "Customer: " ; 
                } else if(r == 3){ 
                    customer = new DwarfCustomer(); 
                    cout << "A dwarf entered the tavern." << endl; 
                    cout << "Customer: " ; 
                } 
                 
                customer->talk(); 
 
                if(customer->ordering(tavern)){ 
                    count++; 
                    cout << "There are " << 10 - count << " customers remaining." << endl; 
                    cout << "Gold: " << tavern.getGold() << endl; 
                } 
 
                delete customer; 
                break; 
            }     
            case 2 : 
            { 
                int kind;  
                cout << "What would you like to make?" << endl; 
                for(int i=0 ; i < tavern.getDrinksCount() ; i++){ 
                    cout<< i + 1 << ". " 
                        << tavern.getDrink(i).name << " Stock: "  
                        << tavern.getDrink(i).stock   
                        << endl; 
                } 
                cin >> kind; 
                tavern.makingDrink(tavern.getDrink(kind-1)); 
                for(int i=0 ; i < tavern.getDrinksCount() ; i++){ 
                    cout<< i + 1 << ". " 
                        << tavern.getDrink(i).name << " Stock: "  
                        << tavern.getDrink(i).stock   
                        << endl; 
                } 
                break; 
            }
                 
            default :  
                break; 
        } 
        if(count >= 10){ 
            cout << "The day is over!" << endl; 
            cout << "You earned " << tavern.getGold() - tavern.getYesterdayGold() << " gold today!"<< endl; 
            tavern.Update(); 
            count = 0;  
            day++; 
            cout << "~~~Day " << day << "~~~"<< endl; 
        } 
        if(bre){ 
            break; 
        }
        cout << "Enter a command." << endl; 
        cout << "1. Serve a customer" << endl; 
        cout << "2. Make something" << endl; 
        cout << "3. Exit" << endl; 
        cout << "~~~Day " << day << "~~~"<< endl;  
        cin >> command; 
    } 
     
    return 0; 
}