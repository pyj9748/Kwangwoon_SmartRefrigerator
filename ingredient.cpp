#include "ingredient.hpp"

ingred::ingred() {
    ingredient_name = "없음";
    ingredient_duedate = 0;
    ingredient_kind = "없음";
    ingredient_quantity = 0;
    ingredient_location = 0;
}
ingred::ingred(string name, int date, string kind, int quantity, int location) {
    ingredient_name = name;
    ingredient_duedate = date;
    ingredient_kind = kind;
    ingredient_quantity = quantity;
    ingredient_location = location;
}

string ingred::get_ingredient_name() { return ingredient_name; }
int ingred::get_ingredient_duedate() { return ingredient_duedate; }
string ingred::get_ingredient_kind() { return ingredient_kind; }
int ingred::get_ingredient_location() { return ingredient_location; }
int ingred::get_ingredient_quantity() { return ingredient_quantity; }

void ingred::set_ingredient_name(string name) { ingredient_name = name; }
void ingred::set_ingredient_duedate(int duedate) {
    ingredient_duedate = duedate;
}
void ingred::set_ingredient_kind(string kind) { ingredient_kind = kind; }
void ingred::set_ingredient_location(int location) {
    ingredient_location = location;
}
void ingred::set_ingredient_quantity(int quantity) {
    ingredient_quantity = quantity;
}
