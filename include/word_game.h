#ifndef PLAYING_H
#define PLAYING_H
#include <string>
using namespace std;
class word_game
{
private:

    int row;
    int col;
    int num;
    int score[2];
    int input_flag;
    string player[2];

    char replacing_char[100] = {'\0'};

public:
    word_game();
    virtual ~word_game();

    void set_dimension(int r,int c);

    void set_player_name(string p,string q);

    void set_replacing_character(char c);

    void winner();

    void row_word_forming(int ,word_game &x);

    void column_word_forming(int ,word_game &x);

    void word_block();

    friend void playing_game (word_game &x);

    int CheckWord(char* search);

    bool exit();
};

#endif // PLAYING_H
