#include "recipe.hpp"

Recipe::Recipe() {
    recipe_name = "";
    recipe_difficulty = "";
    recipe_time = 0;
}

Recipe::Recipe(const string &name, const vector<string> &content,
               const vector<string> &ingredient, const string &difficulty,
               int time) {
    recipe_name = name;
    recipe_content = content;
    recipe_ingredient_list = ingredient;
    recipe_difficulty = difficulty;
    recipe_time = time;
}

string Recipe::get_recipe_name() { return recipe_name; }

vector<string> Recipe::get_recipe_content() { return recipe_content; }

vector<string> Recipe::get_recipe_ingredient() {
    return recipe_ingredient_list;
}

vector<string> &Recipe::get_lacking_ingredients() {
    vector<string> &ref = lacking_ingredients;
    return ref;
}

string Recipe::get_recipe_difficulty() { return recipe_difficulty; }

int Recipe::get_recipe_time() { return recipe_time; }

void Recipe::set_recipe_name(const string &name) { this->recipe_name = name; }

void Recipe::set_recipe_content(const vector<string> &content) {
    recipe_content = content;
}

void Recipe::set_recipe_ingredient(const vector<string> &ingredient) {

    recipe_ingredient_list = ingredient;
}

void Recipe::set_recipe_difficulty(const string &difficulty) {
    this->recipe_difficulty = difficulty;
}

void Recipe::set_recipe_time(int time) { this->recipe_time = time; }
