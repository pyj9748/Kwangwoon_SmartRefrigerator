#include "recipe.h"
#include <list>
#include <string>
Recipe::Recipe(string name, string content, Ingredient ingredient,
               string difficulty, int time) {
    set_recipe_name(name);
    set_recipe_content(content);
    set_recipe_ingredient(ingredient);
    set_recipe_difficulty(difficulty);
    set_recipe_time(time);
}

string Recipe::get_recipe_name() { return recipe_name; }
string Recipe::get_recipe_content() { return recipe_content; }
list<Ingredient> Recipe::get_recipe_ingredient() {
    return recipe_ingredient_list;
}
string Recipe::get_recipe_difficulty() { return recipe_difficulty; }
int Recipe::get_recipe_time() { return recipe_time; }

void Recipe::set_recipe_name(string name) { this->recipe_name = name; }
void Recipe::set_recipe_content(string content) {
    this->recipe_content += content;
}
void Recipe::set_recipe_ingredient(Ingredient ingredient) {

    this->recipe_ingredient_list.push_back(ingredient);
}

void Recipe::set_recipe_difficulty(string difficulty) {
    this->recipe_difficulty = difficulty;
}
void Recipe::set_recipe_time(int time) { this->recipe_time = time; }
