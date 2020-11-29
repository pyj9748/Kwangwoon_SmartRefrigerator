
#include "show.h"
#include "ingredient.h"
#include "recipe.h"
#include <ctime>
#include <iterator>
extern list<Ingredient> ingredient_list;
extern list<Recipe> recipe_list;
extern list<Ingredient>::iterator it_ing;
extern list<Recipe>::iterator it_rec;
//메인 메뉴
void show_main() {
    int menu = 0;
    system("/bin/clear");
    cout << "          smart refrigerator" << endl;
    cout << "1. 재료 추가하기" << endl;
    cout << "2. 재료 삭제하기" << endl;
    cout << "3. 요리 추가하기" << endl;
    cout << "4. 요리 삭제하기" << endl;
    cout << "5. 재료 보기" << endl;
    cout << "6. 요리 보기" << endl;
    cout << "7.요리 하기" << endl;
    cout << "8. 종료 하기" << endl;
    cout << "번호를 입력하세요  1~7" << endl;
    cin >> menu;
    while (1) {
        if (menu == 1) {
            show_1();
            break;
        } else if (menu == 2) {
            show_2();
            break;
        } else if (menu == 3) {
            show_3();
            break;
        } else if (menu == 4) {
            show_4();
            break;
        } else if (menu == 5) {
            show_5();
            break;
        } else if (menu == 6) {
            show_6();
            break;
        } else if (menu == 7) {
            show_7();
            break;
        } else if (menu == 8) {

            exit(8);
        }

        else {
            cout << "1~7 의 번호를 입력하세요" << endl;
            cin >> menu;
            continue;
        }
    }
    return;
}

void show_1() {
    int n;
    string name;
    string date;
    string kind;
    string location;
    int quantity;

    system("/bin/clear");
    cout << "   1. 재료 추가하기" << endl;
    cout << "재료 이름 입력 (예 : 감자) : ";
    cin >> name;
    cout << "재료 유통기한 입력 (예 : 0101 ~ 1231): ";
    cin >> date;
    cout << "재료 종류 입력 (예 : 야채) : ";
    cin >> kind;
    cout << "재료 위치 입력 (1층~3층) : ";
    cin >> location;
    cout << "재료 수량 입력 (정수입력) : ";
    cin >> quantity;
    Ingredient ingredient(name, date, kind, quantity, location);
    ingredient_list.push_back(ingredient);
    cout << "재료가 추가 되었습니다." << endl;

    cout << "메인메뉴로 돌아가기 입력 0:" << endl;
    cin >> n;
    while (1) {

        if (n == 0) {
            show_main();

        } else {
            cout << "메인메뉴로 돌아가기 입력 0:" << endl;
            cin >> n;
            continue;
        }
    }
    return;
}

void show_2() {
    int n;
    string name;
    system("/bin/clear");
    cout << "   2. 재료 삭제하기" << endl;
    cout << "재료 이름 입력 (예 : 감자) : ";
    cin >> name;
    for (it_ing = ingredient_list.begin(); it_ing != ingredient_list.end();
         it_ing++) {
        Ingredient &contact_1 = *it_ing;
        if (contact_1.get_ingredient_name() == name) {
            ingredient_list.erase(it_ing);
        }
    }
    cout << "메인메뉴로 돌아가기 입력 0" << endl;
    cin >> n;
    while (1) {

        if (n == 0) {
            show_main();

        } else {
            cout << "메인메뉴로 돌아가기 입력 0:" << endl;
            cin >> n;
            continue;
        }
    }
}

void show_3() {
    int n;
    Recipe recipe;

    string name;       //이름
    string content;    //내용
    list<string> list; // 재료 (linked list)
    string ingredient;
    string difficulty; // 난이도
    int time;
    system("/bin/clear");
    cout << "   3. 요리 추가하기" << endl;
    cout << "요리 이름 입력 (예 : 감자) : ";
    cin >> name;
    recipe.set_recipe_name(name);
    cout << "요리 내용 입력 (예 : ): ";
    cin >> content;
    recipe.set_recipe_content(content);
    while (1) {
        cout << " 요리 재료 입력 (예 : 계란 , 그만 넣고 싶으면 끝 입력 ) : ";
        cin >> ingredient;
        list.push_back(ingredient);
        if (ingredient == "끝") {
            break;
        } else {
            continue;
        }
    }
    recipe.set_recipe_ingredient(list);
    cout << "요리 난이도 입력 (예 : 상 중 하) : ";
    cin >> difficulty;
    recipe.set_recipe_difficulty(difficulty);
    cout << "요리 시간 입력 (정수입력 시간 단위 ) : ";
    cin >> time;
    recipe.set_recipe_time(time);
    cout << "메인메뉴로 돌아가기 입력 0 : " << endl;
    cin >> n;
    while (1) {

        if (n == 0) {
            show_main();

        } else {
            cout << "메인메뉴로 돌아가기 입력 0:" << endl;
            cin >> n;
            continue;
        }
    }
}

void show_4() {
    int n;
    string name;
    system("/bin/clear");
    cout << "   4. 요리 삭제하기" << endl;
    cout << "요리 이름 입력 (예 : 피자) : ";
    cin >> name;
    for (it_rec = recipe_list.begin(); it_rec != recipe_list.end(); it_rec++) {
        Recipe &contact_1 = *it_rec;
        if (contact_1.get_recipe_name() == name) {
            recipe_list.erase(it_rec);
        }
    }

    cout << "메인메뉴로 돌아가기 입력 0" << endl;
    cin >> n;
    while (1) {

        if (n == 0) {
            show_main();

        } else {
            cout << "메인메뉴로 돌아가기 입력 0:" << endl;
            cin >> n;
            continue;
        }
    }
}

void show_5() {
    int n;
    string str;
    time_t curr_time;
    struct tm *curr_tm;
    curr_time = time(NULL);
    curr_tm = localtime(&curr_time);
    str += curr_tm->tm_mon + 1;

    str += curr_tm->tm_mday;

    system("/bin/clear");
    cout << "   5. 재료 보기" << endl;

    cout << "--------------------------------" << endl;
    cout << "3층 " << endl;
    for (it_ing = ingredient_list.begin(); it_ing != ingredient_list.end();
         it_ing++) {
        Ingredient &contact_1 = *it_ing;
        if (contact_1.get_ingredient_location() == "3") {
            cout << contact_1.get_ingredient_name()
                 << contact_1.get_ingredient_kind()
                 << contact_1.get_ingredient_quantity()
                 << contact_1.get_ingredient_duedate();
            if (contact_1.get_ingredient_duedate() > str) {
                cout << "유통기한 지남!!!" << endl;
            } else {
                cout << endl;
            }
        }
    }
    cout << "--------------------------------" << endl;
    cout << "2층 " << endl;
    for (it_ing = ingredient_list.begin(); it_ing != ingredient_list.end();
         it_ing++) {
        Ingredient &contact_1 = *it_ing;
        if (contact_1.get_ingredient_location() == "2") {
            cout << contact_1.get_ingredient_name()
                 << contact_1.get_ingredient_kind()
                 << contact_1.get_ingredient_quantity()
                 << contact_1.get_ingredient_duedate();
            if (contact_1.get_ingredient_duedate() > str) {
                cout << "유통기한 지남!!!" << endl;
            } else {
                cout << endl;
            }
        }
        cout << "--------------------------------" << endl;
        cout << "1층 " << endl;
        for (it_ing = ingredient_list.begin(); it_ing != ingredient_list.end();
             it_ing++) {
            Ingredient &contact_1 = *it_ing;
            if (contact_1.get_ingredient_location() == "1") {
                cout << contact_1.get_ingredient_name()
                     << contact_1.get_ingredient_kind()
                     << contact_1.get_ingredient_quantity()
                     << contact_1.get_ingredient_duedate();
                if (contact_1.get_ingredient_duedate() > str) {
                    cout << "유통기한 지남!!!" << endl;
                } else {
                    cout << endl;
                }
            }
        }
        cout << "--------------------------------" << endl;

        cout << "메인메뉴로 돌아가기 입력 0" << endl;
        cin >> n;
        while (1) {

            if (n == 0) {
                show_main();

            } else {
                cout << "메인메뉴로 돌아가기 입력 0:" << endl;
                cin >> n;
                continue;
            }
        }
    }
}
void show_6() {
    list<string>::iterator it;
    int n;
    system("/bin/clear");
    cout << "   6. 요리 보기" << endl;
    for (it_rec = recipe_list.begin(); it_rec != recipe_list.end(); it_rec++) {
        Recipe &contact_1 = *it_rec;

        cout << contact_1.get_recipe_name();
        cout << contact_1.get_recipe_content();
        cout << contact_1.get_recipe_difficulty();
        list<string> list = contact_1.get_recipe_ingredient();
        for (it = list.begin(); it != list.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
        cout << contact_1.get_recipe_time() << endl;
    }

    cout << "메인메뉴로 돌아가기 입력 0" << endl;
    cin >> n;
    while (1) {

        if (n == 0) {
            show_main();

        } else {
            cout << "메인메뉴로 돌아가기 입력 0:" << endl;
            cin >> n;
            continue;
        }
    }
    return;
}

void show_7() { // 민수님
    int n;
    system("/bin/clear");
    cout << "메인메뉴로 돌아가기 입력 0" << endl;
    cin >> n;
    while (1) {

        if (n == 0) {
            show_main();

        } else {
            cout << "메인메뉴로 돌아가기 입력 0:" << endl;
            cin >> n;
            continue;
        }
    }
    return;
}
