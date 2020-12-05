#ifndef __COOK_H__
#define __COOK_H__

#include "recipe.hpp"
#include <list>

class Cook {
  public:
    Cook();
    Cook(const list<Ingredient> &ingredient_list,
         const list<Recipe> &recipe_list);

    void set_ingredients(const list<Ingredient> &ingredient_list);
    void set_entire_recipes(const list<Recipe> &recipe_list);

    void
    arrange_recipes(); // 전체 레시피를 재료가 충분한 것과 부족한 것으로 분류
    vector<Recipe> get_cookable();
    vector<Recipe> get_uncookable();

  private:
    list<Ingredient> ingredients;
    list<Recipe> entire_recipes;       // 전체 레시피
    vector<Recipe> cookable_recipes;   // 재료가 충분한 레시피
    vector<Recipe> uncookable_recipes; // 재료가 부족한 레시피
};

// 재료 부족 판별
bool is_lack(const string &target, list<Ingredient> ingredients);
// 재료 소모
void use_ingredients(vector<string> using_ingreds, list<Ingredient> &ingreds);

#endif
