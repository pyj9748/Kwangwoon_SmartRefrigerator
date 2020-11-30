#ifndef __SHOW_H__
#define __SHOW_H__
#include "ingredient.hpp"
#include "recipe.hpp"

// 화면지우기
void clear();

//메인 메뉴
int show_main();

// 선택한 메뉴
void show_1(list<ingred> &ingredient_list); // 재료 추가
void show_2(list<ingred> &ingredient_list); // 재료 삭제
void show_3(list<Recipe> &recipe_list);     // 레시피 추가
void show_4(list<Recipe> &recipe_list);     // 레시피 삭제
void show_5(list<ingred> &ingredient_list); // 재료 목록
void show_6(list<Recipe> &recipe_list);     // 레시피 목록
void show_7();
#endif
