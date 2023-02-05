#include <bits/stdc++.h>
using namespace std;

class Character
{
protected:
    int hp;
    int x;
    int y;

public:
    // constructor set the value of x and y and hp to 0
    Character()
    {
        x = 0;
        y = 0;
        hp = 0;
    }
    Character(int hp, int x, int y)
    {
        this->hp = hp;
        this->x = x;
        this->y = y;
    }
    int getHp()
    {
        return this->hp;
    }
    void setHp(int hp)
    {
        this->hp = hp;
    }

    int getX(){
        return this->x;
    }
    void setX(int x){
        this->x = x;
    }
};

int main()
{
}