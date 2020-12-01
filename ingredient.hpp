#ifndef __INGREDIENT_H__
#define __INGREDIENT_H__

#include <string>

using namespace std;

class ingred {
  public:
    ingred();
    ingred(string name, int date, string kind, int quantity, int location);

    string get_ingredient_name();
    int get_ingredient_duedate();
    string get_ingredient_kind();
    int get_ingredient_quantity();
    int get_ingredient_location();

    void set_ingredient_name(string s);
    void set_ingredient_duedate(int i);
    void set_ingredient_kind(string s);
    void set_ingredient_quantity(int i);
    void set_ingredient_location(int i);

  private:
    string ingredient_name;  //이름
    int ingredient_duedate;  //유통기한
    string ingredient_kind;  // 종류
    int ingredient_quantity; // 수량
    int ingredient_location; //위치
};

#endif
