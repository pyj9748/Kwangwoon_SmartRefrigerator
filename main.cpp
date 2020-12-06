#include "recipeBuf.hpp"
#include "show.hpp"
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define PERMS 0777
#define MAX_CONTENT_LENGTH 128

using namespace std;

// 데이터 불러오기
void data_load();
// 데이터 저장
void data_save();

void signalHandler(int signum);

list<Ingredient> ingredient_list;
list<Recipe> recipe_list;

int main() {

    signal(SIGINT, signalHandler);

    data_load();

    int menu = 0;

    while (true) {
        menu = show_main();

        switch (menu) {
        case 1: // 재료 추가
            show_1(ingredient_list);
            break;
        case 2: // 재료 삭제
            show_2(ingredient_list);
            break;
        case 3: // 레시피 추가
            show_3(recipe_list);
            break;
        case 4: // 레시피 삭제
            show_4(recipe_list);
            break;
        case 5: // 재료 보기
            show_5(ingredient_list);
            break;
        case 6: // 레시피 보기
            show_6(recipe_list);
            break;
        case 7: // 요리하기
            show_7(ingredient_list, recipe_list);
            break;
        case 8: // 프로그램 종료
            clear();
            data_save();
            return 0;
        default:
            continue;
        }
    }
}

// 데이터 불러오기
void data_load() {
    vector<vector<string>> contentData;
    vector<vector<string>> ingredientData;
    vector<recipeBuf> otherData;
    ifstream ifs;
    string data_path;
    recipeBuf recipe;
    Ingredient ingredient;
    int fd = 0;
    int rSize = 0;
    int recipeCnt = 0;

    mkdir("./Refrigerator_Data", PERMS);
    mkdir("./Refrigerator_Data/Recipe_Contents", PERMS);
    mkdir("./Refrigerator_Data/Recipe_Ingredients", PERMS);

    data_path = "./Refrigerator_Data/ingredients.dat";
    fd = open(data_path.c_str(), O_CREAT | O_RDWR, PERMS);
    while (true) {
        memset(&ingredient, 0x00, sizeof(Ingredient));
        rSize = read(fd, &ingredient, sizeof(Ingredient));
        if (rSize == 0)
            break;
        else
            ingredient_list.push_back(ingredient);
    }
    close(fd);

    data_path = "./Refrigerator_Data/recipes.dat";
    fd = open(data_path.c_str(), O_CREAT | O_RDWR, PERMS);
    while (true) {
        memset(&recipe, 0x00, sizeof(recipeBuf));
        rSize = read(fd, &recipe, sizeof(recipeBuf));
        if (rSize == 0)
            break;
        else
            otherData.push_back(recipe);
    }
    close(fd);

    data_path = "./Refrigerator_Data/numberOfRecipes.txt";
    ifs.open(data_path);
    ifs >> recipeCnt;
    ifs.close();

    for (int i = 0; i < recipeCnt; ++i) {
        vector<string> contents;
        data_path =
            "./Refrigerator_Data/Recipe_Contents/" + to_string(i) + ".txt";
        ifs.open(data_path);
        while (!ifs.eof()) {
            string content;
            getline(ifs, content);
            contents.push_back(content);
            if (content == "완성")
                break;
        }
        contentData.push_back(contents);
        ifs.close();

        vector<string> ingredients;
        data_path =
            "./Refrigerator_Data/Recipe_Ingredients/" + to_string(i) + ".txt";
        ifs.open(data_path);
        while (!ifs.eof()) {
            string ingredient;
            getline(ifs, ingredient);
            if (ingredient.size() == 0)
                break;
            else
                ingredients.push_back(ingredient);
        }
        ingredientData.push_back(ingredients);
        ifs.close();
    }

    for (int i = 0; i < recipeCnt; ++i) {
        recipe_list.push_back(
            Recipe(otherData[i].getName(), contentData[i], ingredientData[i],
                   otherData[i].getDifficulty(), otherData[i].getTime()));
    }

    return;
}

// 데이터 저장
void data_save() {
    vector<vector<string>> contentData;
    vector<vector<string>> ingredientData;
    vector<recipeBuf> otherData;
    ofstream ofs;
    int fd = 0;

    list<Recipe>::iterator it_rec;
    for (it_rec = recipe_list.begin(); it_rec != recipe_list.end(); ++it_rec) {
        contentData.push_back(it_rec->get_recipe_content());
        ingredientData.push_back(it_rec->get_recipe_ingredient());
        otherData.push_back(recipeBuf(it_rec->get_recipe_name(),
                                      it_rec->get_recipe_difficulty(),
                                      it_rec->get_recipe_time()));
    }
    int recipeCnt = recipe_list.size();

    string data_path = "./Refrigerator_Data/ingredients.dat";
    fd = open(data_path.c_str(), O_CREAT | O_WRONLY, PERMS);
    list<Ingredient>::iterator it_ing;
    for (it_ing = ingredient_list.begin(); it_ing != ingredient_list.end();
         ++it_ing)
        write(fd, &(*it_ing), sizeof(Ingredient));
    close(fd);

    data_path = "./Refrigerator_Data/recipes.dat";
    fd = open(data_path.c_str(), O_CREAT | O_WRONLY, PERMS);
    vector<recipeBuf>::iterator it_data;
    for (it_data = otherData.begin(); it_data != otherData.end(); ++it_data)
        write(fd, &(*it_data), sizeof(recipeBuf));
    close(fd);

    for (int i = 0; i < recipeCnt; ++i) {
        vector<string>::iterator it_str;

        data_path =
            "./Refrigerator_Data/Recipe_Contents/" + to_string(i) + ".txt";
        ofs.open(data_path);
        for (it_str = contentData[i].begin(); it_str != contentData[i].end();
             ++it_str)
            ofs << *it_str << endl;
        ofs.close();

        data_path =
            "./Refrigerator_Data/Recipe_Ingredients/" + to_string(i) + ".txt";
        ofs.open(data_path);
        for (it_str = ingredientData[i].begin();
             it_str != ingredientData[i].end(); ++it_str)
            ofs << *it_str << endl;
        ofs.close();
    }

    data_path = "./Refrigerator_Data/numberOfRecipes.txt";
    ofs.open(data_path);
    ofs << recipeCnt << endl;
    ofs.close();
    return;
}

void signalHandler(int signum) {
    if (signum == SIGINT) {
        data_save();
        exit(0);
    }
}
