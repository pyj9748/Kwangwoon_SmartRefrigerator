#ifndef __RECIPE_H__
#define __RECIPE_H__

#include "ingredient.hpp"
#include <vector>

#define MAX_DATA_LENGTH 32

using namespace std;

class Recipe {
  public:
    Recipe();
    Recipe(string name, vector<string> content,
           vector<string> list_for_ingerdient, string difficulty, int time);

    string get_recipe_name();
    vector<string> get_recipe_content();
    vector<string> get_recipe_ingredient();
    string get_recipe_difficulty();
    int get_recipe_time();

    void set_recipe_name(string str);
    void set_recipe_content(vector<string> str);
    void set_recipe_ingredient(vector<string> list);
    void set_recipe_difficulty(string str);
    void set_recipe_time(int n);

    vector<string> lacking_ingredients; // 부족한 재료

  private:
    string recipe_name;                    // 이름
    vector<string> recipe_content;         // 내용
    vector<string> recipe_ingredient_list; // 필요한 재료
    string recipe_difficulty;              // 난이도
    int recipe_time;                       // 조리 시간
};

#endif
