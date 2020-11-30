#include "show.hpp"
#include "cook.hpp"
#include <ctime>
#include <fcntl.h>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// list<ingred> ingredient_list;

void clear() { write(1, "\033[1;1H\033[2J", 10); }

//메인 메뉴
int show_main() {
    int menu = 0;

    while (menu < 1 || menu > 8) {
        clear();
        cout << "Smart Refrigerator\n" << endl;
        cout << "1. 재료 추가하기" << endl;
        cout << "2. 재료 삭제하기" << endl;
        cout << "3. 요리 추가하기" << endl;
        cout << "4. 요리 삭제하기" << endl;
        cout << "5. 재료 보기" << endl;
        cout << "6. 요리 보기" << endl;
        cout << "7. 요리 하기" << endl;
        cout << "8. 종료 하기" << endl;
        cout << "번호를 입력하세요(1~8) : ";
        cin >> menu;
        getchar();
    }

    return menu;
}

// 재료 추가하기.
void show_1(list<ingred> &ingredient_list) {
    int n;
    string name;
    int date;
    string kind;
    int location;
    int quantity;

    clear();
    cout << "1. 재료 추가하기\n" << endl;
    cout << "재료 이름 입력 (예 : 감자) : ";
    cin >> name;
    cout << "재료 유통기한 입력 (예 : 0101 ~ 1231): ";
    cin >> date;
    cout << "재료 종류 입력 (예 : 야채) : ";
    cin >> kind;
    cout << "재료 위치 입력 (1~3) : ";
    cin >> location;
    cout << "재료 수량 입력 (정수입력) : ";
    cin >> quantity;

    ingred ingredient(name, date, kind, quantity, location);
    ingredient_list.push_back(ingredient);
    cout << "재료가 추가 되었습니다." << endl;
    cout << "재료 더 추가하기 입력 : 1" << endl;
    cout << "메인메뉴로 돌아가기 입력 0:" << endl;
    cin >> n;
    while (1) {

        if (n == 0) {
            return;

        } else if (n == 1) {
            show_1(ingredient_list);

        } else {
            cout << "재료 더 추가하기 입력 : 1" << endl;
            cout << "메인메뉴로 돌아가기 입력 0:" << endl;
            cin >> n;
            continue;
        }
    }
    return;
}
// 재료 삭제하기.
void show_2(list<ingred> &ingredient_list) {
    int n;
    string name;

    list<ingred>::iterator it_ing;

    clear();
    cout << "2. 재료 삭제하기\n" << endl;
    cout << "재료 이름 입력 (예 : 감자) : ";
    cin >> name;
    for (it_ing = ingredient_list.begin(); it_ing != ingredient_list.end();
         it_ing++) {
        ingred &contact_1 = *it_ing;
        if (contact_1.get_ingredient_name() == name) {
            it_ing = ingredient_list.erase(it_ing);
        }
    }
    cout << "메인메뉴로 돌아가기 입력 0" << endl;
    cin >> n;
    while (1) {

        if (n == 0) {
            return;

        } else {
            cout << "메인메뉴로 돌아가기 입력 0:" << endl;
            cin >> n;
            continue;
        }
    }
}
// 요리 추가하기
void show_3(list<Recipe> &recipe_list) {
    int n;

    string name;          //이름
    list<string> content; //내용
    list<string> list;    // 재료 (linked list)
    string ingredient;
    string step;
    string difficulty; // 난이도
    int time;

    clear();
    cout << "3. 요리 추가하기\n" << endl;
    cout << "요리 이름 입력 (예 : 에그스크램블) : ";
    getline(cin, name);
    cout << "요리 내용 입력 (예 : 계란을 풀고 우유를 섞은 뒤 기름을 두른 팬 "
            "위에서 볶는다 0 // 추가 설명 : 조리 방법을 다 쓰고 마지막에 "
            "띄어쓰기 "
            "하고 0을 입력 ): ";

    while (1) {

        getline(cin, step);
        if (step == "0") {
            break;
        } else {
            content.push_back(step);
            continue;
        }
    }
    while (1) {
        cout << " 요리 재료 입력 (예 : 계란 , 그만 넣고 싶으면 0 입력 ) : ";
        cin >> ingredient;
        if (ingredient == "0") {
            break;
        } else {
            list.push_back(ingredient);
            continue;
        }
    }
    cout << "요리 난이도 입력 (예 : 상 중 하) : ";
    cin >> difficulty;
    cout << "요리 시간 입력 (분 단위 정수 입력)(예 : 35) : ";
    cin >> time;
    Recipe recipe(name, content, list, difficulty, time);
    recipe_list.push_back(recipe);
    cout << "요리 더 추가하기 입력 : 1" << endl;
    cout << "메인메뉴로 돌아가기 입력 0 : " << endl;
    cin >> n;
    while (1) {

        if (n == 0) {
            return;

        } else if (n == 1) {
            show_3(recipe_list);
        } else {
            cout << "요리 더 추가하기 입력 : 1" << endl;
            cout << "메인메뉴로 돌아가기 입력 0:" << endl;
            cin >> n;
            continue;
        }
    }
}

void show_4(list<Recipe> &recipe_list) {
    int n;
    string name;

    list<Recipe>::iterator it_rec;

    clear();
    cout << "   4. 요리 삭제하기\n" << endl;
    cout << "요리 이름 입력 (예 : 에그스크램블) : ";
    getline(cin, name);
    for (it_rec = recipe_list.begin(); it_rec != recipe_list.end(); it_rec++) {
        Recipe &contact_1 = *it_rec;
        if (contact_1.get_recipe_name() == name) {
            it_rec = recipe_list.erase(it_rec);
        }
    }

    cout << "메인메뉴로 돌아가기 입력 0" << endl;
    cin >> n;
    while (1) {

        if (n == 0) {
            return;

        } else {
            cout << "메인메뉴로 돌아가기 입력 0:" << endl;
            cin >> n;
            continue;
        }
    }
}
// 재료 보기.
void show_5(list<ingred> &ingredient_list) {
    int n;
    int t = 0;

    time_t curr_time;
    struct tm *curr_tm;
    curr_time = time(NULL);
    curr_tm = localtime(&curr_time);
    t += (curr_tm->tm_mon + 1) * 100;
    t += curr_tm->tm_mday;

    list<ingred>::iterator it_ing;

    clear();
    cout << "5. 재료 보기\n" << endl;
    if (ingredient_list.empty()) {
        cout << "냉장고가 비었습니다." << endl;
        cout << "재료를 추가해주세요(메뉴 1번)." << endl;
        cout << "메인메뉴로 돌아가기 입력 0" << endl;
        cin >> n;
        while (1) {

            if (n == 0) {
                return;

            } else {
                cout << "메인메뉴로 돌아가기 입력 0:" << endl;
                cin >> n;
                continue;
            }
        }
    }
    cout << "--------------------------------" << endl;
    cout << "3층 " << endl;
    for (it_ing = ingredient_list.begin(); it_ing != ingredient_list.end();
         it_ing++) {
        ingred &contact_1 = *it_ing;

        if (contact_1.get_ingredient_location() == 3) {
            cout << "이름 : " << contact_1.get_ingredient_name() << " "
                 << " 종류 :" << contact_1.get_ingredient_kind() << " "
                 << "개수 :" << contact_1.get_ingredient_quantity() << " "
                 << "유통기한: " << contact_1.get_ingredient_duedate();
            if ((contact_1.get_ingredient_duedate() - t) < 0) {
                cout << " 유통기한 지남!!!" << endl;
            }
            cout << endl;
        }
    }

    cout << "--------------------------------" << endl;
    cout << "2층 " << endl;
    for (it_ing = ingredient_list.begin(); it_ing != ingredient_list.end();
         it_ing++) {
        ingred &contact_1 = *it_ing;

        if (contact_1.get_ingredient_location() == 2) {
            cout << "이름 : " << contact_1.get_ingredient_name() << " "
                 << " 종류 :" << contact_1.get_ingredient_kind() << " "
                 << "개수 :" << contact_1.get_ingredient_quantity() << " "
                 << "유통기한: " << contact_1.get_ingredient_duedate();
            if ((contact_1.get_ingredient_duedate() - t) < 0) {
                cout << " 유통기한 지남!!!" << endl;
            }
            cout << endl;
        }
    }
    cout << "--------------------------------" << endl;
    cout << "1층 " << endl;
    for (it_ing = ingredient_list.begin(); it_ing != ingredient_list.end();
         it_ing++) {
        ingred &contact_1 = *it_ing;

        if (contact_1.get_ingredient_location() == 1) {
            cout << "이름 : " << contact_1.get_ingredient_name() << " "
                 << " 종류 :" << contact_1.get_ingredient_kind() << " "
                 << "개수 :" << contact_1.get_ingredient_quantity() << " "
                 << "유통기한: " << contact_1.get_ingredient_duedate();
            if ((contact_1.get_ingredient_duedate() - t) < 0) {
                cout << " 유통기한 지남!!!" << endl;
            }
            cout << endl;
        }
    }
    cout << "--------------------------------" << endl;

    cout << "메인메뉴로 돌아가기 입력 0" << endl;
    cin >> n;
    while (1) {

        if (n == 0) {
            return;

        } else {
            cout << "메인메뉴로 돌아가기 입력 0:" << endl;
            cin >> n;
            continue;
        }
    }
}
// 요리보기
void show_6(list<Recipe> &recipe_list) {
    int n;
    int i = 0;

    list<string>::iterator it;
    list<Recipe>::iterator it_rec;

    clear();
    cout << "6. 요리 보기\n" << endl;

    if (recipe_list.empty()) {
        cout << "요리 목록이 비어있습니다. " << endl;
        cout << "요리를 추가해주세요 메뉴 3" << endl;
    }
    cout << "--------------------------------" << endl;
    for (it_rec = recipe_list.begin(); it_rec != recipe_list.end(); it_rec++) {
        Recipe &contact_1 = *it_rec;
        cout << ++i << "번 요리 : ";
        cout << contact_1.get_recipe_name() << endl;
        cout << "조리 내용 : ";

        list<string> content = contact_1.get_recipe_content();
        for (it = content.begin(); it != content.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
        cout << "재료 : ";
        list<string> list = contact_1.get_recipe_ingredient();
        for (it = list.begin(); it != list.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
        cout << "난이도 : " << contact_1.get_recipe_difficulty() << endl;
        cout << "조리 시간 : " << contact_1.get_recipe_time() << "분 걸립니다."
             << endl;
        cout << "--------------------------------" << endl;
    }

    cout << "메인메뉴로 돌아가기 입력 0" << endl;
    cin >> n;
    while (1) {

        if (n == 0) {
            return;

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

    clear();
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
