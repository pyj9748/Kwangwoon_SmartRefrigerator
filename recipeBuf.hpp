#ifndef __RECIPEBUF_H__
#define __RECIPEBUF_H__

#include <string>

#define MAX_DATA_LENGTH 32

using namespace std;

class recipeBuf {
  public:
    recipeBuf();
    recipeBuf(const string &name, const string &diff, int time);

    void setName(const string &name);
    void setDifficulty(const string &diff);
    void setTime(int time);

    string getName();
    string getDifficulty();
    int getTime();

  private:
    char name[MAX_DATA_LENGTH + 1];
    char difficulty[MAX_DATA_LENGTH + 1];
    int time;
};

#endif
