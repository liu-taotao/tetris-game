#include "Block.h"
#include <stdlib.h>

IMAGE *Block::imgs[7] = {NULL};
int Block::size = 36;

Block::Block()
{
    if (imgs[0] == NULL) {
        IMAGE imgTmp;
        loadimage(&imgTmp, "/img/tiles.png");

        SetWorkingImage(&imgTmp);
        for (int i = 0; i < 7; i++) {
            imgs[i] = new IMAGE;
            getimage(imgs[i], i * size, 0, size, size);
        }
        SetWorkingImage();//恢复工作区
    }

    int blocks[7][4] = {
        1,3,5,7, // I
        2,4,5,7, // Z 1型
        3,5,4,6, // Z 2型
        3,5,4,7, // T
        2,3,5,7, // L
        3,5,7,6, // J
        2,3,4,5, // 田
    };
    
    //随机生成一种俄罗斯方块
    blockType = 1 + rand() % 7; //1 + 0...6 -> 1 .. 7

    //初始化 smallBlocks 坐标
    for (int i = 0; i < 4; i++) {
        int value = blocks[blockType - 1][i];
        smallBlocks[i].row = value / 2;
        smallBlocks[i].col = value % 2;
    }
    
    //本身图片
    img = imgs[blockType - 1];

}

//下降
void Block::drop()
{

}

//左移右移
void Block::moveLeftRight(int offset)
{

}

//旋转
void Block::retate()
{

}

//画方块边界 绘制
void Block::draw(int leftMargin, int topMargin)
{
    for (int i = 0; i < 4; i++) {
        int x = leftMargin + smallBlocks[i].col * size;
        int y = topMargin + smallBlocks[i].row * size;

        //绘制图像
        putimage(x, y, img);
    }
}