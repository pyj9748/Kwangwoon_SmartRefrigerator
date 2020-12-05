#ifndef __RECIPE_H__
#define __RECIPE_H__

#include "ingredient.hpp"
#include <vector>

#define MAX_DATA_LENGTH 32

using namespace std;

class Recipe {
  public:
    Recipe();
    Recipe(const string &name, const vector<string> &content,
           const vector<string> &ingredient, const string &difficulty,
           int time);

    string get_recipe_name();
    vector<string> get_recipe_content();
    vector<string> get_recipe_ingredient();
    vector<string> &get_lacking_ingredients();
    string get_recipe_difficulty();
    int get_recipe_time();

    void set_recipe_name(const string &name);
    void set_recipe_content(const vector<string> &content);
    void set_recipe_ingredient(const vector<string> &ingredient);
    void set_recipe_difficulty(const string &difficulty);
    void set_recipe_time(int time);

  private:
    string recipe_name;                    // 이름
    vector<string> recipe_content;         // 내용
    vector<string> recipe_ingredient_list; // 필요한 재료
    vector<string> lacking_ingredients;    // 부족한 재료
    string recipe_difficulty;              // 난이도
    int recipe_time;                       // 조리 시간
};

#endif
