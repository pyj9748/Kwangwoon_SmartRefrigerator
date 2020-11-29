#include "ingredient.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Recipe {
  public:
    string get_recipe_name();
    string get_recipe_content();
    list<string> get_recipe_ingredient();
    string get_recipe_difficulty();
    int get_recipe_time();

    void set_recipe_name(string str);
    void set_recipe_content(string str);
    void set_recipe_ingredient(list<string> list);
    void set_recipe_difficulty(string str);
    void set_recipe_time(int n);

  private:
    string recipe_name;                  //이름
    string recipe_content;               //내용
    list<string> recipe_ingredient_list; // 재료 (linked list)
    string recipe_difficulty;            // 난이도
    int recipe_time;                     //조리 시간
};
