#include "show.hpp"
#include "cook.hpp"
#include <cstdio>
#include <ctime>
#include <fcntl.h>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

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
        cout << "\n번호를 입력하세요(1~8) : ";
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
    int menu = 0;

    while (true) {
        clear();
        cout << "1. 재료 추가하기\n" << endl;
        cout << "재료 이름 입력 (예: 감자): ";
        getline(cin, name);
        cout << "재료 유통기한 입력 (예: 0101~1231): ";
        cin >> date;
        getchar();
        cout << "재료 종류 입력 (예: 야채): ";
        getline(cin, kind);
        cout << "재료 위치 입력 (0: 실온, 1~3: 냉장실, 4: 냉동실): ";
        cin >> location;
        cout << "재료 수량 입력 (정수 입력): ";
        cin >> quantity;

        ingred ingredient(name, date, kind, quantity, location);
        ingredient_list.push_back(ingredient);
        printf("%c[32m", 27);
        cout << "\n재료가 추가 되었습니다." << endl;
        printf("%c[0m", 27);
        cout << "----------------------------------------------------------"
             << endl;
        cout << "0. 메인메뉴로 돌아가기" << endl;
        cout << "1. 재료 더 추가하기" << endl;
        cout << "\n번호를 입력하세요(0~1) : ";
        while (true) {
            cin >> menu;
            getchar();
            if (menu == 0)
                return;
            else if (menu == 1)
                break;
            else {
                printf("%c[31m", 27);
                cout << "0~1 사이의 번호를 입력해 주세요: ";
                printf("%c[0m", 27);
                continue;
            }
        }
    }
}

// 재료 삭제하기.
void show_2(list<ingred> &ingredient_list) {
    int n;
    string name;
    bool result = false;
    int menu = 0;

    list<ingred>::iterator it_ing;

    while (true) {
        result = false;
        clear();
        cout << "2. 재료 삭제하기\n" << endl;
        cout << "재료 이름 입력 (예: 감자): ";
        getline(cin, name);
        for (it_ing = ingredient_list.begin(); it_ing != ingredient_list.end();
             ++it_ing) {
            ingred &contact_1 = *it_ing;
            if (contact_1.get_ingredient_name() == name) {
                it_ing = ingredient_list.erase(it_ing);
                result = true;
                break;
            }
        }

        if (result == true) {
            printf("%c[32m", 27);
            cout << name << "이(가) 삭제되었습니다." << endl;
            printf("%c[0m", 27);
        } else {
            printf("%c[31m", 27);
            cout << name << "을(를) 찾지 못했습니다." << endl;
            printf("%c[0m", 27);
        }
        cout << "----------------------------------------------------------"
             << endl;
        cout << "0. 메인메뉴로 돌아가기" << endl;
        cout << "1. 재료 더 삭제하기" << endl;
        cout << "\n번호를 입력하세요(0~1) : ";
        while (true) {
            cin >> menu;
            getchar();
            if (menu == 0)
                return;
            else if (menu == 1)
                break;
            else {
                printf("%c[31m", 27);
                cout << "0~1 사이의 번호를 입력해 주세요: ";
                printf("%c[0m", 27);
                continue;
            }
        }
    }
}

// 요리 추가하기
void show_3(list<Recipe> &recipe_list) {
    int n;
    int i = 1;
    int menu = 0;

    string name;                //이름
    vector<string> contents;    //내용
    vector<string> ingredients; // 재료 (linked list)
    string ingredient;
    string step;
    string difficulty; // 난이도
    int time;

    while (true) {
        clear();
        cout << "3. 요리 추가하기\n" << endl;
        cout << "요리 이름 입력 (예: 에그 스크램블): ";
        getline(cin, name);
        cout << "\n요리 순서 입력 (\'완성\' 입력 시 종료): " << endl;

        i = 1;
        contents.clear();
        while (true) {
            cout << "[" << i << "] ";
            getline(cin, step);
            contents.push_back(step);
            if (step == "완성") {
                break;
            } else {
                ++i;
                continue;
            }
        }

        cout << "\n요리 재료 입력 (예: 계란) ('0' 입력 시 종료): " << endl;
        ingredients.clear();
        while (true) {
            getline(cin, ingredient);
            if (ingredient == "0") {
                break;
            } else {
                ingredients.push_back(ingredient);
                continue;
            }
        }

        cout << "\n요리 난이도 입력 (예: 상 중 하): ";
        getline(cin, difficulty);
        cout << "\n요리 시간 입력 (분 단위 정수 입력) (예: 35): ";
        cin >> time;
        Recipe recipe(name, contents, ingredients, difficulty, time);
        recipe_list.push_back(recipe);

        printf("%c[32m", 27);
        cout << "\n요리가 추가 되었습니다." << endl;
        printf("%c[0m", 27);
        cout << "----------------------------------------------------------"
             << endl;
        cout << "0. 메인메뉴로 돌아가기" << endl;
        cout << "1. 요리 더 추가하기" << endl;
        cout << "\n번호를 입력하세요(0~1) : ";
        while (true) {
            cin >> menu;
            getchar();
            if (menu == 0)
                return;
            else if (menu == 1)
                break;
            else {
                printf("%c[31m", 27);
                cout << "0~1 사이의 번호를 입력해 주세요: ";
                printf("%c[0m", 27);
                continue;
            }
        }
    }
}

void show_4(list<Recipe> &recipe_list) {
    int n;
    string name;
    bool result = false;
    int menu = 0;

    list<Recipe>::iterator it_rec;

    while (true) {
        result = false;
        clear();
        cout << "4. 요리 삭제하기\n" << endl;
        cout << "요리 이름 입력 (예: 에그 스크램블): ";
        getline(cin, name);
        for (it_rec = recipe_list.begin(); it_rec != recipe_list.end();
             it_rec++) {
            Recipe &contact_1 = *it_rec;
            if (contact_1.get_recipe_name() == name) {
                it_rec = recipe_list.erase(it_rec);
                result = true;
                break;
            }
        }

        if (result == true) {
            printf("%c[32m", 27);
            cout << name << "이(가) 삭제되었습니다." << endl;
            printf("%c[0m", 27);
        } else {
            printf("%c[31m", 27);
            cout << name << "을(를) 찾지 못했습니다." << endl;
            printf("%c[0m", 27);
        }
        cout << "----------------------------------------------------------"
             << endl;
        cout << "0. 메인메뉴로 돌아가기" << endl;
        cout << "1. 요리 더 삭제하기" << endl;
        cout << "\n번호를 입력하세요(0~1) : ";
        while (true) {
            cin >> menu;
            getchar();
            if (menu == 0)
                return;
            else if (menu == 1)
                break;
            else {
                printf("%c[31m", 27);
                cout << "0~1 사이의 번호를 입력해 주세요: ";
                printf("%c[0m", 27);
                continue;
            }
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
        cout << "----------------------------------------------------------"
             << endl;
        cout << "냉장고가 비었습니다." << endl;
        cout << "재료를 추가해주세요. (메뉴 1번)" << endl;
        cout << "----------------------------------------------------------"
             << endl;
    } else {
        for (int i = 0; i <= 4; ++i) {
            cout << "----------------------------------------------------------"
                 << endl;
            if (i == 0) {
                printf("%c[33m", 27);
                cout << "실온" << endl;
                printf("%c[0m", 27);
            } else if (i == 4) {
                printf("%c[36m", 27);
                cout << "냉동실 " << endl;
                printf("%c[0m", 27);
            } else {
                printf("%c[34m", 27);
                cout << "냉장실 " << i << "층" << endl;
                printf("%c[0m", 27);
            }

            for (it_ing = ingredient_list.begin();
                 it_ing != ingredient_list.end(); it_ing++) {
                ingred &contact_1 = *it_ing;

                if (contact_1.get_ingredient_location() == i) {
                    cout << "이름 : " << contact_1.get_ingredient_name()
                         << " / "
                         << "종류 : " << contact_1.get_ingredient_kind()
                         << " / "
                         << "개수 : " << contact_1.get_ingredient_quantity()
                         << " / "
                         << "유통기한 : " << contact_1.get_ingredient_duedate();
                    if ((contact_1.get_ingredient_duedate() - t) < 0) {
                        printf("%c[31m", 27);
                        cout << " (유통기한 지남!!!)";
                        printf("%c[0m", 27);
                    }
                    cout << endl;
                }
            }
        }
        cout << "----------------------------------------------------------"
             << endl;
    }

    do {
        cout << "메인메뉴로 돌아가려면 0을 입력하세요 : ";
        cin >> n;
    } while (n != 0);

    return;
}

// 요리보기
void show_6(list<Recipe> &recipe_list) {
    int n;
    int i = 1, j = 1;
    int menu = 0;

    vector<string>::iterator it;
    list<Recipe>::iterator it_rec = recipe_list.begin();

    while (true) {
        if (recipe_list.empty()) {
            clear();
            cout << "6. 요리 보기\n" << endl;
            cout << "----------------------------------------------------------"
                 << endl;
            cout << "요리 목록이 비어있습니다. " << endl;
            cout << "요리를 추가해주세요. (메뉴 3번)" << endl;
            cout << "----------------------------------------------------------"
                 << endl;
        } else {
            clear();
            cout << "6. 요리 보기\n" << endl;
            cout << "----------------------------------------------------------"
                 << endl;

            j = 1;
            Recipe &contact = *it_rec;
            vector<string> contents = contact.get_recipe_content();
            vector<string> ingredients = contact.get_recipe_ingredient();
            cout << i << "번 요리 - " << contact.get_recipe_name() << endl;
            cout << "\n요리 순서: " << endl;
            for (it = contents.begin(); it != contents.end(); ++it) {
                cout << "[" << j++ << "] " << *it << endl;
            }
            cout << "\n재료: ";
            for (it = ingredients.begin(); it != ingredients.end(); ++it) {
                cout << *it << " ";
            }
            cout << "\n\n난이도: " << contact.get_recipe_difficulty() << endl;
            cout << "\n요리 시간: " << contact.get_recipe_time() << "분"
                 << endl;
            cout << "----------------------------------------------------------"
                 << endl;
        }

        cout << "0. 메인메뉴로 돌아가기" << endl;
        cout << "1. 이전 요리 보기" << endl;
        cout << "2. 다음 요리 보기" << endl;
        cout << "\n번호를 입력하세요(0~2) : ";
        while (true) {
            cin >> menu;
            getchar();
            if (menu == 0)
                return;
            else if (menu == 1) {
                if (it_rec != recipe_list.begin()) {
                    --it_rec;
                    --i;
                }
                break;
            } else if (menu == 2) {
                ++it_rec;
                if (it_rec == recipe_list.end())
                    --it_rec;
                else
                    ++i;
                break;
            } else {
                printf("%c[31m", 27);
                cout << "0~2 사이의 번호를 입력해 주세요: ";
                printf("%c[0m", 27);
                continue;
            }
        }
    }
}

void show_7(const list<ingred> &ingredient_list,
            const list<Recipe> &recipe_list) {
    int n = 0;

    Cook cook(ingredient_list, recipe_list);
    cook.arrange_recipes();

    vector<Recipe> cookable = cook.get_cookable();
    vector<Recipe> uncookable = cook.get_uncookable();

    clear();
    cout << "cookable" << endl;
    for (int i = 0; i < cookable.size(); ++i)
        cout << cookable[i].get_recipe_name() << endl;
    cout << "uncookable" << endl;
    for (int i = 0; i < uncookable.size(); ++i)
        cout << uncookable[i].get_recipe_name() << endl;

    cin >> n;

    return;
}
