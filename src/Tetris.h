#pragma once
#include <iostream>
#include <vector>
#include <graphics.h>
using namespace std;
class Tetris
{
    public:
        //构造函数
        Tetris(int rows, int cols, int left, int top, int blockSize);
        void init();//初始化
        void play();//开始游戏

    private:
        int delay;
        bool update; //是否更新

        //int map[20][10];
        //二维数组
        //0: 空白, 没有任何方块
        //5: 是第五种俄罗斯方块
        vector<vector<int>> map;
        int rows;
        int cols;
        int leftMargin;
        int topMargin;
        int blockSize;
        IMAGE imgBg;
        

        void keyEven();    
        void updateWindow();   
        //返回距离上一次调用该函数，间隔了多少秒
        //第一次调用该函数，返回0    
        int getDelay();
        void drop();
        void clearLine();
        
    
};