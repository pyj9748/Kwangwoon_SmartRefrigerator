#ifndef __COOK_H__
#define __COOK_H__

#include "recipe.hpp"
#include <list>

class Cook {
  public:
    Cook();
    Cook(const list<ingred> &ingredient_list, const list<Recipe> &recipe_list);

    void set_ingredients(const list<ingred> &ingredient_list);
    void set_entire_recipes(const list<Recipe> &recipe_list);

    void arrange_recipes();
    vector<Recipe> get_cookable();
    vector<Recipe> get_uncookable();

  private:
    list<ingred> ingredients;
    list<Recipe> entire_recipes;
    vector<Recipe> cookable_recipes;
    vector<Recipe> uncookable_recipes;
};

bool is_lack(const string &target, list<ingred> ingredients);

#endif
