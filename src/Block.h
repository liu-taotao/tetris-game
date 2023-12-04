#pragma once
#include <iostream>
#include <graphics.h>
#include <vector>
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
        static IMAGE **getImages();
        Block &operator=(const Block& other);

        bool blockInMap(const vector<vector<int>>&map);
        //Point* getSmallBlock();

        //固化函数
        void solidify(vector<vector<int>>&map);

    private:
        int blockType;  
        Point smallBlocks[4];
        IMAGE *img;

        static IMAGE *imgs[7];
        static int size;
};