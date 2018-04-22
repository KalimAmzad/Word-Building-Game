#include "word_game.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

word_game::word_game()
{
    row=col=score[0]=score[1]=0;

    num=input_flag=1;
}

word_game::~word_game()
{
    //dtor
}

void word_game::set_dimension(int r,int c)
{
    row = r;
    col = c;
}
void word_game::set_player_name(string p,string q)
{
    player[0]=p;
    player[1]=q;
}
void word_game::set_replacing_character(char c)
{
    c=tolower(c);
    if(!(c>='a' && c<='z'))
        cout<<"you have to input only character.You miss your turn"<<endl;
    else if(!(num<=row*col))
        cout<<"Your entering box number excessing the block field.You miss your turn"<<endl;
    else if(replacing_char[num]=='\0')
    {
        input_flag=1;
        replacing_char[num]=c;
    }
    else
    {
        input_flag=0;
        cout<<"You can't replace which box has already been used or .You miss your turn"<<endl;
    }
}
void word_game::word_block()
{
    int i,j;

    num=1;

    for(i=1; i<=row*3; i++)
    {

        if(i%3==1)
        {
            for(j=1; j<=col*5; j++)
            {
                if(j%5==0)

                    cout<<"|";
                else if(i==1)

                    cout<<"-";
                else

                    cout<<" ";
            }
            if(i==1||i==4)

                cout<<"\t\t*******************";
        }

        else if(i%3==2)
        {
            for(j=1; j<=col*2; j++)
            {
                if(j%2==0)

                    cout<<"|";
                else
                {
                    cout<<" ";

                    cout.width(2);

                    if(replacing_char[num]=='\0')

                        cout<<num;
                    else

                        cout<<replacing_char[num];

                    cout<<" ";

                    num++;
                }

            }
            if(i==2)

                cout<<"\t\t*   SCORE BOARD   *";

            else if(i==8)

                cout<<"\t  "<<score[0]<<"\t\t\t  "<<score[1];
        }

        else if(i%3==0)
        {
            for(j=1; j<=col*5; j++)
            {
                if(j%5==0)

                    cout<<"|";

                else

                    cout<<"_";
            }
            if(i==3)

                cout<<"\t\t*\t\t  *";

            else if(i==6)

                cout<<"\t  "<<player[0]<<"\t\t\t"<<player[1];
        }

        cout<<endl;
    }
}

void playing_game(word_game &x)
{
    int playernum=0,boxnumber,point=0;

    char ch,c,a;

    ch='n';

    while(ch != 'y'||ch != 'Y')
    {
        playernum=(playernum%2)?1:0;

        cout<<endl<<x.player[playernum]<<",it's your time: "<<endl;

        cout<<"Enter box number: "<<endl;

        cin>>x.num;

        cout<<"put character: ";

        cin>>c;

        x.set_replacing_character(c);

        x.row_word_forming(playernum,x);

        x.column_word_forming(playernum,x);

        x.word_block();

        playernum++;

        if(x.exit())
        {
            break;
        }

        cout<<"Want to exit? Press y/n : ";

        scanf("%c",&ch);
    }

}

void word_game::row_word_forming(int playernum,word_game &x)
{
    int co,i=0;

    int duplicate_num=num;

    char word[30];

    if(input_flag)
    {

        if(num%col==1)
        {
            while(replacing_char[duplicate_num]!='\0')
            {
                word[i]=replacing_char[duplicate_num];

                i++;

                duplicate_num++;
            }

            word[i]='\0';

            cout<<"Forming Word in row: "<<word<<endl;
            int p ;
            p= x.CheckWord(word);

            if(p>1)
            {

                cout<<"\aCongratulation! "<<x.player[playernum]<<".You have got "<<p<<" point."<<endl;
                x.score[playernum]+=p;
            }
        }
        else if(num%col==0)
        {
            while(replacing_char[duplicate_num]!='\0')
            {
                duplicate_num--;
            }
            duplicate_num++;

            while(duplicate_num<=num)
            {
                word[i]=replacing_char[duplicate_num];

                i++;

                duplicate_num++;
            }
            word[i]='\0';

            cout<<"Forming Word in row: "<<word<<endl;
            int p ;
            p= x.CheckWord(word);

            if(p>1)
            {

                cout<<"\aCongratulation! "<<x.player[playernum]<<".You have got "<<p<<" point."<<endl;
                x.score[playernum]+=p;
            }
        }
        else
        {
            co=duplicate_num/col;

            while(duplicate_num>co*col)
            {
                if(replacing_char[duplicate_num]=='\0')

                    break;

                else

                    duplicate_num--;
            }
            duplicate_num++;

            while(duplicate_num<num)
            {
                word[i]=replacing_char[duplicate_num];

                i++;

                duplicate_num++;
            }

            while(duplicate_num<(co+1)*col)
            {
                word[i]=replacing_char[duplicate_num];

                i++;

                duplicate_num++;
            }
            word[i]='\0';

            cout<<"Forming Word in row: "<<word<<endl;

            int p ;
            p= x.CheckWord(word);

            if(p>1)
            {

                cout<<"\aCongratulation! "<<x.player[playernum]<<".You have got "<<p<<" point."<<endl;
                x.score[playernum]+=p;
            }


        }
    }
}

void word_game::column_word_forming(int playernum,word_game &x)
{
    int co,i=0;

    int duplicate_num=num;

    char word[30];

    int flag = 0;
    if(input_flag)
    {
        while(replacing_char[duplicate_num]!='\0')
        {
            if(duplicate_num<=col)
            {
                flag = 1;
                break;
            }
            duplicate_num-=col;
        }
        if(!flag)
            duplicate_num+=col;

        while(replacing_char[duplicate_num]!='\0')
        {
            word[i]=replacing_char[duplicate_num];

            i++;

            duplicate_num+=col;
        }
        word[i]='\0';

        cout<<"Forming Word in column: "<<word<<endl;

        int p ;
        p= x.CheckWord(word);

        if(p>1)
        {

            cout<<"\aCongratulation! "<<x.player[playernum]<<".You have got "<<p<<" point."<<endl;
            x.score[playernum]+=p;
        }
    }
}


int word_game::CheckWord(char* search)
{
    int offset;
    string line;
    ifstream Myfile;
    Myfile.open ("dictionary.txt");

    if(Myfile.is_open())
    {
        while(!Myfile.eof())
        {
            getline(Myfile,line);
            if (search==line)
            {
                int p=strlen(search);
                return p;
            }
        }
        Myfile.close();
    }
    else
        cout<<"Unable to open this file."<<endl;

    return false;
}

bool word_game::exit()
{
    char ch;
    cout<<endl<<"Want to exit? press y/n: ";
    cin>>ch;
    if (ch=='y' || ch=='Y')
    {
        winner();
        return true;
    }
    else
        return false;
}
void word_game::winner()
{
    if(score[0]>score[1])

        cout<<"\aCongratulation!!! "<<player[0]<<",YOU WIN THE GAME"<<endl;

    else if(score[0]<score[1])

        cout<<"\aCongratulation!!! "<<player[1]<<",YOU WIN THE GAME"<<endl;

    else

        cout<<"GAME IS DRAW"<<endl;
}

