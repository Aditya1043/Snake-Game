#include<iostream>
#include<vector>
#include<stdlib.h>
#include<conio.h>
using namespace std;
char board[21][81];
class food
{
    public:
    int x;
    int y;
    char value;
};
class snake
{
    public:
    int x;
    int y;
    char value;
};
void enter_snake(vector<class snake> &v)
{
    int k=70;
    for(int i=0;i<4;i++)
    {
        v[i].x=10;
        v[i].y=k++;
        v[i].value='#';
    }
    v[0].value='H';
    v[3].value='T';
}
void print_board()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<80;j++)
        {
            cout<<board[i][j];
        }
    }
}
void enter_snake_(vector<class snake> v)
{
    for(int i=0;i<v.size();i++)
    {
       board[v[i].x][v[i].y]=v[i].value;
    }
}
void shift(vector<class snake> &v)
{
    int g=v[v.size()-1].x;
    int h=v[v.size()-1].y;
    for(int i=v.size()-1;i>0;i--)
    {
        v[i].x=v[i-1].x;
        v[i].y=v[i-1].y;
    }
    board[g][h]=' ';
}
void modify_snake(vector<class snake> &v)
{
    v[v.size()-1].value= v[v.size()-2].value;
    snake s;
    s.value='T';
    s.x=v[v.size()-1].x;
    s.y=v[v.size()-1].y;
    v.push_back(s);
    enter_snake_(v);
}
int main()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<80;j++)
        {
            if(i==0||j==79||i==19||j==0)
            {
                board[i][j]='%';
            }
        }
    }
    food f;
    f.x=rand() % 20;
    f.y=rand() % 80;
    f.value='F';
    board[f.x][f.y]=f.value;
    snake s;
    vector<class snake> v(4);
    enter_snake(v);
    enter_snake_(v);
    char ch='a';
    while(1)
    {
        int flag=0;
        for(int i=1;i<v.size();i++)
        {
            if(v[0].x==v[i].x&&v[0].y==v[i].y)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"out";
            break;
        }
        if(v[0].y==0)
        {
            v[0].y=80;
            shift(v);
            enter_snake_(v);
        }
        else if(v[0].y==80)
        {
            v[0].y=0;
            shift(v);
            enter_snake_(v);
        }
        else if(v[0].x==0)
        {
            v[0].x=20;
            shift(v);
            enter_snake_(v);
        }
        else if(v[0].x==20)
        {
            v[0].x=0;
            shift(v);
            enter_snake_(v);
        }
        print_board();
        system("CLS");
        if(kbhit())
            ch = _getch();
        if(ch=='w')
        {
            shift(v);
            v[0].x=v[0].x-1;
            enter_snake_(v);
        }
        else if(ch=='a')
        {
            shift(v);
            v[0].y=v[0].y-1;
            enter_snake_(v);
        }
        else if(ch=='s')
        {
            shift(v);
            v[0].x=v[0].x+1;
            enter_snake_(v);
        }
        else if(ch=='d')
        {
            shift(v);
            v[0].y=v[0].y+1;
            enter_snake_(v);
        }
        else
          {
              cout<<"wrong key";
            break;
          }
          if(f.x==v[0].x&&f.y==v[0].y)
          {
              f.x=rand() % 20;
              f.y=rand() % 80;
              board[f.x][f.y]=f.value;
              modify_snake(v);
          }
    }
}
