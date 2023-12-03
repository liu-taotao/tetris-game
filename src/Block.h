#pragma once
#include <iostream>
#include <graphics.h>
using namespace std;

//方块的行 列
struct Point {
    int row;
    int col;
};
class Block
{
    public:
        Block();
        void drop();//下降
        void moveLeftRight(int offset);//左移右移
        void retate();//旋转
        void draw(int leftMargin, int topMargin);


    private:
        int blockType;  
        Point smallBlocks[4];
        IMAGE *img;

        static IMAGE *imgs[7];
        static int size;
};