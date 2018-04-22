
#include "word_game.h"

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int a,b;

    string pl1,pl2;

    word_game english;

    cout<<"\t\t WELCOME TO ENGLISH VOCABUILDER GAME\n";

    cout<<"Enter 1st player name: ";

    cin>>pl1;

    cout<<"Enter 2nd player name: ";

    cin>>pl2;

    english.set_player_name(pl1,pl2);

    cout<<endl<<"Hi, "<<pl1<<" and "<<pl2<<endl<<endl;

    cout<<" To create block field..."<<endl;

    cout<<"Enter the the total row number : ";

    cin>>a;

    cout<<"Enter the the total column number : ";

    cin>>b;

    english.set_dimension(a,b);

    cout<<"Game block field is created"<<endl<<endl;

    english.word_block();

    playing_game(english);


    return 0;
}

