#include "cook.hpp"
#include "ingredient.hpp"
#include "recipe.hpp"
#include "show.hpp"
#include <iostream>
#include <list>

using namespace std;

int main() {
    list<ingred> ingredient_list;
    list<Recipe> recipe_list;

    int menu = 0;

    while (true) {
        menu = show_main();

        switch (menu) {
        case 1:
            show_1(ingredient_list);
            break;
        case 2:
            show_2(ingredient_list);
            break;
        case 3:
            show_3(recipe_list);
            break;
        case 4:
            show_4(recipe_list);
            break;
        case 5:
            show_5(ingredient_list);
            break;
        case 6:
            show_6(recipe_list);
            break;
        case 7:
            break;
        case 8:
            clear();
            return 0;
        default:
            continue;
        }
    }
}
