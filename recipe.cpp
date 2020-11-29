#include "recipe.h"
#include <list>
#include <string>

string Recipe::get_recipe_name() { return recipe_name; }
string Recipe::get_recipe_content() { return recipe_content; }
list<string> Recipe::get_recipe_ingredient() { return recipe_ingredient_list; }
string Recipe::get_recipe_difficulty() { return recipe_difficulty; }
int Recipe::get_recipe_time() { return recipe_time; }

void Recipe::set_recipe_name(string name) { this->recipe_name = name; }
void Recipe::set_recipe_content(string content) {
    this->recipe_content += content;
}
void Recipe::set_recipe_ingredient(list<string> ingredient) {

    this->recipe_ingredient_list.assign(ingredient.begin(), ingredient.end());
}

void Recipe::set_recipe_difficulty(string difficulty) {
    this->recipe_difficulty = difficulty;
}
void Recipe::set_recipe_time(int time) { this->recipe_time = time; }
