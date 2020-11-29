#include <iostream>
#include <list>
#include <string>
using namespace std;

class Ingredient {
  public:
    Ingredient(string name, string duedate, string kind, int quantity,
               string location);

    string get_ingredient_name();
    string get_ingredient_duedate();
    string get_ingredient_kind();
    string get_ingredient_location();
    int get_ingredient_quantity();

    void set_ingredient_name(string str);
    void set_ingredient_duedate(string str);
    void set_ingredient_kind(string str);
    void set_ingredient_location(string str);
    void set_ingredient_quantity(int n);

  private:
    string ingredient_name;     //이름
    string ingredient_duedate;  //유통기한
    string ingredient_kind;     // 종류
    int ingredient_quantity;    // 수량
    string ingredient_location; //위치
};
