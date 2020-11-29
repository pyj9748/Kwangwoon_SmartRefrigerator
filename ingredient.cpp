#include "ingredient.h"
#include <list>

Ingredient::Ingredient(string name, string duedate, string kind, int quantity,
                       string location) {
    set_ingredient_name(name);
    set_ingredient_duedate(duedate);
    set_ingredient_kind(kind);
    set_ingredient_location(location);
    set_ingredient_quantity(quantity);
}

string Ingredient::get_ingredient_name() { return ingredient_name; }
string Ingredient::get_ingredient_duedate() { return ingredient_duedate; }
string Ingredient::get_ingredient_kind() { return ingredient_kind; }
string Ingredient::get_ingredient_location() { return ingredient_location; }
int Ingredient::get_ingredient_quantity() { return ingredient_quantity; }

void Ingredient::set_ingredient_name(string name) { ingredient_name = name; }
void Ingredient::set_ingredient_duedate(string duedate) {
    ingredient_duedate = duedate;
}
void Ingredient::set_ingredient_kind(string kind) { ingredient_kind = kind; }
void Ingredient::set_ingredient_name(string location) {
    ingredient_location = location;
}
void Ingredient::set_ingredient_quantity(int quantity) {
    ingredient_quantity = quantity;
}
