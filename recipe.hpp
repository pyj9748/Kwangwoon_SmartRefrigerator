#ifndef __RECIPE_H__
#define __RECIPE_H__

#include "ingredient.hpp"
#include <list>

using namespace std;

class Recipe {
  public:
    Recipe();
    Recipe(string name, list<string> content, list<string> list_for_ingerdient,
           string difficulty, int time);
    string get_recipe_name();
    list<string> get_recipe_content();
    list<string> get_recipe_ingredient();
    string get_recipe_difficulty();
    int get_recipe_time();

    void set_recipe_name(string str);
    void set_recipe_content(list<string> str);
    void set_recipe_ingredient(list<string> list);
    void set_recipe_difficulty(string str);
    void set_recipe_time(int n);

  private:
    string recipe_name;                  //이름
    list<string> recipe_content;         //내용
    list<string> recipe_ingredient_list; // 재료 (linked list)
    string recipe_difficulty;            // 난이도
    int recipe_time;                     //조리 시간
};
#endif
