#include "ingredient.hpp"
#include <cstring>

Ingredient::Ingredient() {
    memset(ingredient_name, '\0', MAX_DATA_LENGTH + 1);
    ingredient_duedate = 0;
    memset(ingredient_name, '\0', MAX_DATA_LENGTH + 1);
    ingredient_quantity = 0;
    ingredient_location = 0;
    ingredient_checkdue = 0;
}
Ingredient::Ingredient(const string &name, int date, const string &kind,
                       int quantity, int location) {
    memcpy(ingredient_name, name.c_str(), MAX_DATA_LENGTH);
    ingredient_duedate = date;
    memcpy(ingredient_kind, kind.c_str(), MAX_DATA_LENGTH);
    ingredient_quantity = quantity;
    ingredient_location = location;
    ingredient_checkdue = 0;
}

string Ingredient::get_ingredient_name() { return string(ingredient_name); }
int Ingredient::get_ingredient_duedate() { return ingredient_duedate; }
string Ingredient::get_ingredient_kind() { return string(ingredient_kind); }
int Ingredient::get_ingredient_location() { return ingredient_location; }
int Ingredient::get_ingredient_quantity() { return ingredient_quantity; }
int Ingredient::get_ingredient_checkdue() { return ingredient_checkdue; }

void Ingredient::set_ingredient_name(const string &name) {
    memcpy(ingredient_name, name.c_str(), MAX_DATA_LENGTH);
}
void Ingredient::set_ingredient_duedate(int duedate) {
    ingredient_duedate = duedate;
}
void Ingredient::set_ingredient_kind(const string &kind) {
    memcpy(ingredient_kind, kind.c_str(), MAX_DATA_LENGTH);
}
void Ingredient::set_ingredient_location(int location) {
    ingredient_location = location;
}
void Ingredient::set_ingredient_quantity(int quantity) {
    ingredient_quantity = quantity;
}
void Ingredient::set_ingredient_checkdue(int checkdue) {
    ingredient_checkdue = checkdue;
}
