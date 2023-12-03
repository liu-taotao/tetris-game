#pragma once
#include <iostream>
using namespace std;
class Block
{
    public:
        Block();
        void drop();//下降
        void moveLeftRight(int offset);//左移右移
        void retate();//旋转
        void draw(int leftMargin, int topMargin);
};