
#include "cook.h"
#include "ingredient.h"
#include "recipe.h"
#include "show.h"
#include <iostream>

using namespace std;
list<Ingredient> ingredient_list;
list<Recipe> recipe_list;
list<Ingredient>::iterator it_ing;
list<Recipe>::iterator it_rec;
int main() {

    show_main();

    return 0;
}
