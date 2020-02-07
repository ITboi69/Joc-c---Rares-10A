#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

int Secret, Guess,nr=0,maxx=0;
char a[26],yes[4];

int main ()
{
    do
    {
        srand (time(NULL));
        Secret = rand() % 100 + 1;
        system("cls");
        nr=0;
        do
        {
            cout<<"Choose your difficulty:"<<"\n"<<"\n";
            cout<<"Very easy: 10 tries"<<"\n";
            cout<<"Easy: 8 tries"<<"\n";
            cout<<"Medium: 6 tries"<<"\n";
            cout<<"Hard: 4 tries"<<"\n";
            cout<<"Very hard: 2 tries"<<"\n";
            cout<<"Insane: 1 try"<<"\n"<<"\n";
            cin.getline(a, 26);
            cout<<"\n";

            for(int i=0; a[i]!=0; i++)
                if(islower(a[i]) && isalpha(a[i]))
                    a[i]-=32;

            if(strcmp(a,"VERY EASY")==0)
                maxx=10;
            else if(strcmp(a,"EASY")==0)
                maxx=8;
            else if(strcmp(a,"MEDIUM")==0)
                maxx=6;
            else if(strcmp(a,"HARD")==0)
                maxx=4;
            else if(strcmp(a,"VERY HARD")==0)
                maxx=2;
            else if(strcmp(a,"INSANE")==0)
                maxx=1;
            system("cls");
        }
        while(maxx==0);
        system("cls");

        do
        {
            nr++;
            cout<<"Guess the number (1 to 100): ";
            cin>>Guess;
            if (Secret<Guess)
                cout<<"The secret number is lower"<<"\n";
            else if (Secret>Guess)
                cout<<"The secret number is higher"<<"\n";
            cout<<"Tries left: "<<maxx-nr<<"\n"<<"\n";
        }
        while (Secret!=Guess && nr<maxx);

        system("cls");
        if(nr==maxx)
            cout<<"GAME OVER!"<<"\n"<<"The secret number was "<<Secret<<"\n";
        else
            cout<<"Congratulations!"<<"\n"<<"The secret number was "<<Secret<<"\n";

        cout<<"Want to try again ? (Yes/No)  ";
        cin>>yes;
        for(int i=0; yes[i]!=0; i++)
            if(islower(yes[i]) && !isdigit(yes[i]))
                yes[i]-=32;
    }
    while(strcmp(yes,"YES")==0);
    return 0;
}
