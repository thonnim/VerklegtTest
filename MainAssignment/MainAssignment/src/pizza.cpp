#include "pizza.h"


Pizza::Pizza()
{
    this->name[0] = '\0';
    this->pizzaSize = Small;
    this->price = 0.0;
    this->basePizzaPrice = 1300;
}


Pizza::Pizza(string name, Pizza::Size pizzaSize = Small)
{

    //Iterate trough the input string and put each character into the char array.
    for(unsigned int i = 0; i < name.length(); i++)
    {
        //Set the current character into the char array.
        this->name[i] = name[i];
        //Set the end character to the next character (Will be overwritten if it loops again).
        this->name[i+1] = '\0';
    }

    //Put the pizzaSize input in pizzaSize.
    this->pizzaSize = pizzaSize;
    this->basePizzaPrice = 1300;
}


void Pizza::addTopping(Topping topping)
{
    this->toppings.push_back(topping);
}


void Pizza::clearToppings()
{
    this->toppings.clear();
}


void Pizza::generatePrice()
{
    this->generatePrice(0.0);
}

void Pizza::generatePrice(double extraCost = 0.0)
{
    //Create temporary variables for price and a Topping class.
    double tempPrice = 0;
    Topping tempTopping;

    //Loop trough all toppings that Pizza is storing and add
    //the price of those toppings to tempPrice.
    for(unsigned int i = 0; i < this->toppings.size(); i++)
    {
        tempTopping = this->toppings.at(i);
        tempPrice += tempTopping.getPrice();
    }
    //Add extraCost and the base price to tempPrice
    tempPrice += (extraCost + this->basePizzaPrice);

    //Set price to be the calculated tempPrice.
    this->price = tempPrice;
}


ostream& operator << (ostream& out, const Pizza& pizza)
{
    Topping tempTopping;

    out << pizza.name << " " << pizza.price << " ";
    out << pizza.toppings.size() << " ";
    for(unsigned int i = 0; i < pizza.toppings.size(); i++)
    {
        tempTopping = pizza.toppings.at(i);
        out << tempTopping.getName() << " " << tempTopping.getPrice() << " ";
    }
    out << endl;

    return out;
}


istream& operator >> (istream& in, Pizza& pizza)
{
    unsigned int toppingsCount = 0;
    string toppingName;
    double toppingPrice;

    in >> pizza.name;
    in >> pizza.price;
    in >> toppingsCount;

    for(unsigned int i = 0; i < toppingsCount; i++)
    {
        in >> toppingName >> toppingPrice;
        Topping tempTopping(toppingName, toppingPrice);
        pizza.addTopping(tempTopping);
    }

    return in;
}


///Getters and setters.
int Pizza::getToppingCount()
{
    return this->toppings.size();
}

double Pizza::getPrice()
{
    //Returns a different price depending on the pizza size.
    if(this->pizzaSize == this->Small)
    {
        return this->price * 1.0;
    }
    else if(this->pizzaSize == this->Medium)
    {
        return this->price * 1.2;
    }
    else if(this->pizzaSize == this->Large)
    {
        return this->price * 1.4;
    }
    else
    {
        return -1.0;
    }
}

string Pizza::getName()
{
    //Convert char array name to string and store in return string
    string returnString = string(this->name);
    //Return the string.
    return returnString;
}


void Pizza::setName(string name)
{
    //Iterate trough the input string and put each character into the char array.
    for(unsigned int i = 0; i < name.length(); i++)
    {
        //Set the current character into the char array.
        this->name[i] = name[i];
        //Set the end character to the next character (Will be overwritten if it loops again).
        this->name[i+1] = '\0';
    }
}


vector<Topping> Pizza::getToppings()
{
    return this->toppings;
}


Pizza::Size Pizza::getSize()
{
    return this->pizzaSize;
}


void Pizza::setSize(Pizza::Size pizzaSize)
{
    this->pizzaSize = pizzaSize;
}
