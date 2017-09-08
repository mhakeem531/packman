#include <iostream>
#include <windows.h>
#include <ctime>
#include <stdlib.h>
#include <string>
//#include <vector>
using namespace std;
char pacman(char pacman)//==========>>to product the symbol of the pack man;
{
pacman= pacman+1;
return pacman;
};
char ghost(char ghost)//============>>to product the symbol of the ghost;
{
ghost= ghost+2;
return ghost;
};
char p;

char map[18][42]={"################################",
                  "#..............................#",
                  "#.............       ..........#",
                  "#     ########......########...#",
                  "#..............................#",
                  "#........################......#",
                  "#......#...................#   #",
                  "#......#           ........#   #",
                  "#      #.....######...###..#   #",
                  "#      #...................#...#",
                  "#......#...................#...#",
                  "#......#            #......#...#",
                  "#         ..........#..........#",
                  "#...................#..........#",
                  "#.....###########...#.....######",
                  "#...........       ............#",
                  "#                              #",
                  "################################",
};
void show_map()
{
   for(int i=0;i<18;i++)
   {
       cout<<map[i]<<endl;
   }
};
char map2[18][42]={"################################",
                  "#..............................#",
                  "#.............       ..........#",
                  "#     ########......########...#",
                  "#                              #",
                  "#........################......#",
                  "#......#...................#   #",
                  "#......#           ........#   #",
                  "#      #.....######...###..#   #",
                  "#      #                   #...#",
                  "#......#                   #...#",
                  "#......#            #......#...#",
                  "#         ..........#..........#",
                  "#...................#          #",
                  "#.....###########...#.....######",
                  "#...........       ............#",
                  "#                              #",
                  "################################",
};
	void showmap2()//====>>>the function of printing it;
	{
	    for (int i=0 ; i<18 ; i++)
        {
            cout<<map2[i]<<endl;
        }
	};

void gotoxy(int x,int y)
{
   HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
   COORD position={x,y};
   SetConsoleCursorPosition(hStdout,position);
}


int main()
{
    bool run=true;
    bool run2=true;
    int scores=305;//====>>counter of level 1;
    int pointes=0;//===>>counter of level 2;
    int c=(rand()%15+1);//===>>for the ghost of level 1;
    int d=(rand()%37+1);
    int g=(rand()%15+1);
    int h=(rand()%37+1);//===>>for the first ghost of level 2;
    int e=(rand()%15+1);
    int f=(rand()%36+1);//====>>for the second ghost ~ ~ ~;
    int a=15;//===>>the location of the pack man;
    int b=15;
    //=========the beginning==========;
    gotoxy(5 , 2);
    cout<<"****************HELLO******************"<<endl;
    gotoxy(5,10);
    cout<<"       NOW OUR GAME WILL STAST"<<endl;
    gotoxy(5,22);
    cout<<"___________GOOD LUKE___________________"<<endl;
   Sleep(2500);
   system("CLS");
   srand(time(0));
 while(run)
 {
  srand(time(0));
  show_map();
  cout<<"the score is :"<<scores<<"\n";
  gotoxy(d,c);
  cout<<ghost(p);//====>>the symbol of the ghost;
   gotoxy(a,b);
cout<<pacman(p);//=====>>the symbol of the pack man;
  while(map[c][d]!='#')
  {
   c--;
  }
  while(d==30)
  {
//srand(time(0));
     d=(rand()%28)+1;
     c=(rand()%15)+1;

  }
  if(c==16)
  {
      c=c-1;
  }

  if(GetAsyncKeyState(VK_UP))
  {
      if(map[b-1][a]=='.')
      {
         b--;
         scores++;
      }
      else
        if(map[b-1][a]==' ')
      {
         b--;
      }
      map[b][a]=' ';
  }
  if(GetAsyncKeyState(VK_DOWN))
  {
      if(map[b+1][a]=='.')
      {
         b++;
         scores++;
      }
      else
        if(map[b+1][a]==' ')
      {
         b++;
      }
      map[b][a]=' ';
  }
  if(GetAsyncKeyState(VK_LEFT))
  {
      if(map[b][a-1]=='.')
      {
         a--;
         scores++;
      }
      else
        if(map[b][a-1]==' ')
      {
         a--;
      }
      map[b][a]=' ';
  }
  if(GetAsyncKeyState(VK_RIGHT))
  {
      if(map[b][a+1]=='.')
      {
         a++;
         scores++;
      }
      else
        if(map[b][a+1]==' ')
      {
         a++;
      }
      map[b][a]=' ';
  }
  c++;
  d++;
Sleep(150);//====>>to move the ghost and the pack man;
if(b==c&&a==d)
{   gotoxy(18,18);
    cout<<"sorry you failed ****** you have no another try"<<endl;
    Sleep(1000);
    cout<<"your score is : "<<scores<<endl;//=====>>if the ghost and the pack man int the same place;
    Sleep(1000);
    break;
};
/*if(c==b&&d==a-1)//====if the move
{
   gotoxy(18,18);
    cout<<"sorry you failed you have no another try"<<endl;
    Sleep(1000);
    cout<<"your score is : "<<scores<<endl;//=====>>if the ghost and the pack man int the same place;
    Sleep(1000);
    break;
};//*******************/
/*c++;
d++;*/
if (scores==305)
{   system("CLS");
    gotoxy(15,19);
    cout<<"congratulation you won and will go to level two"<<endl;//====>>if you win this message will appear;
    Sleep(5000);
    system("cls");
    cout<<"the next level will begin *************** GOOD LUK"<<endl;
    Sleep(3500);
//===========>>>>>>>>>>>=============THE BEGINING OF THE LEVEL 2============>>>>>>>>>>=================;
    system("CLS");
    srand(time(0));
    while(run2)
    {
      srand(time(0));
      showmap2();
      cout<<"the points now is : "<<pointes<<endl;
      gotoxy(f,e);
      cout<<ghost(p);//=====>>appear of the first ghost;
      gotoxy(a , b);
      cout<<pacman(p);//======>>appear of pack man;
      gotoxy(h,g);
      cout<<ghost(p);//======>>appear of the second ghost;
      while(map[g][h]!='#')
     {
        g--;
     }
     while(map[e][f]!='#')
  {
   e--;
  }
  while(h==30)
  {

     h=(rand()%28)+1;
     g=(rand()%15)+1;

  }
  while(f==30)
  {

     f=(rand()%28)+1;
     e=(rand()%15)+1;

  }
  if(g==16)
  {
      g=g-1;
  }
  if(e==16)
  {
      e=e-1;
  }

  if(GetAsyncKeyState(VK_UP))
  {
      if(map2[b-1][a]=='.')
      {
         b--;
         pointes++;
      }
      else
        if(map2[b-1][a]==' ')
      {
         b--;
      }
      map2[b][a]=' ';
  }
  if(GetAsyncKeyState(VK_DOWN))
  {
      if(map2[b+1][a]=='.')
      {
         b++;
         pointes++;
      }
      else
        if(map2[b+1][a]==' ')
      {
         b++;
      }
      map2[b][a]=' ';
  }
  if(GetAsyncKeyState(VK_LEFT))
  {
      if(map2[b][a-1]=='.')
      {
         a--;
         pointes++;
      }
      else
        if(map2[b][a-1]==' ')
      {
         a--;
      }
      map2[b][a]=' ';
  }
  if(GetAsyncKeyState(VK_RIGHT))
  {
      if(map2[b][a+1]=='.')
      {
         a++;
         pointes++;
      }
      else
        if(map2[b][a+1]==' ')
      {
         a++;
      }
      map2[b][a]=' ';
  }

  Sleep(100);//====>>to move the ghost and the pack man;
e++;
f++;
g++;
h++;
  if(b==g&&a==h )
{   gotoxy(18,18);
    cout<<"sorry you failed ****** you have no another try"<<endl;
    Sleep(1000);
    cout<<"your score is : "<<pointes<<endl;//=====>>if the ghost and the pack man in the same place;
   Sleep(1000);
exit(0);
   break;
}
 if(b==e && a==f)
{
 gotoxy(18,18);
 cout<<"sorry you failed ****** you have no another try"<<endl;
 Sleep(1000);
 cout<<"your score is : "<<pointes<<endl;//=====>>if the ghost and the pack man int the same place;
 Sleep(1000);
system("cls");
gotoxy(1, 20);
cout<<"________________*GAME OVER*_______________"<<endl;
Sleep(500);
cin.get();
  exit(0);
};
if (pointes==227)
{   gotoxy(18,18);
    cout<<"congratulation you won and you have finished the game"<<endl;//====>>if you win this message will appear;
    Sleep(5000);//====>>if you win this message will appear;
    system("cls");
    //break;
    cin.get();
    exit(0);

    }

system("CLS");
}//===========================>>nested while
 system("CLS");
 }//==========================>>if in the main while*/
system("CLS");
//cin.get();
//exit(0);

 }//========================>>the main while;
cin.get();

    return 0;
}






KIDS

learning android application

===================================

This app list arabic , english alphabets (list for letters only and another letters with words) and arabic numbers with abality of listening to the sound of the letter and the word but the app doesn't be completed yet...only you can use (arabic letter) button and (arabic letters words button)

Pre-requisites

Android SDK v23
Android Build Tools v23.0.2
Android Support Repository v23.3.0