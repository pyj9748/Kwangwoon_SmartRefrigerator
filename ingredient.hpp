#ifndef __INGREDIENT_H__
#define __INGREDIENT_H__

#include <string>

#define MAX_DATA_LENGTH 32

using namespace std;

class Ingredient {
  public:
    Ingredient();
    Ingredient(const string &name, int date, const string &kind, int quantity,
               int location);

    string get_ingredient_name();
    int get_ingredient_duedate();
    string get_ingredient_kind();
    int get_ingredient_quantity();
    int get_ingredient_location();
    int get_ingredient_checkdue();

    void set_ingredient_name(const string &name);
    void set_ingredient_duedate(int i);
    void set_ingredient_kind(const string &kind);
    void set_ingredient_quantity(int i);
    void set_ingredient_location(int i);
    void set_ingredient_checkdue(int i);

  private:
    char ingredient_name[MAX_DATA_LENGTH + 1]; //이름
    int ingredient_duedate;                    //유통기한
    char ingredient_kind[MAX_DATA_LENGTH + 1]; //종류
    int ingredient_quantity;                   //수량
    int ingredient_location;                   //위치
    int ingredient_checkdue;                   //유통기한 경과 여부
};

#endif
