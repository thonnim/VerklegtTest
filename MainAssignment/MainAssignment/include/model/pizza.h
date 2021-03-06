#ifndef PIZZA_H
#define PIZZA_H

#include <stddef.h>
#include <string>
#include <vector>
#include "BaseService.h"
#include "topping.h"
#include "Base.h"

using namespace std;

class Pizza
{
    public:

        enum Size
        {
            Small,
            Medium,
            Large
        };

        Pizza();
        Pizza(string name, Pizza::Size pizzaSize);

        void addTopping(Topping topping);
        void clearToppings();
        void generatePrice();
        void generatePrice(double extraCost);

        friend ostream& operator << (ostream& out, const Pizza& pizza);
        friend istream& operator >> (istream& in, Pizza& pizza);

        ///Getters and setters.
        int getToppingCount() const;
        double getPrice() const;
        string getName() const;
        void setName(string name);
        vector<Topping> getToppings() const;
        Pizza::Size getSize() const;
        void setSize(Pizza::Size pizzaSize);
        Base getBase() const;
        void setBase(Base base);

    protected:

    private:
        vector<Topping> toppings;
        double price;
        char name[32];
        Pizza::Size pizzaSize;
        Base base;
};

#endif // PIZZA_H
