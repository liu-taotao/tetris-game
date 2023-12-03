#include "Tetris.h"
#include <time.h>
#include <stdlib.h>
/**
 * @brief Construct a new Tetris:: Tetris object
 * 
 * @param rows 多少行
 * @param cols 多少列
 * @param left 左边界
 * @param top 右边界
 * @param blockSize 方块大小
 */
Tetris::Tetris(int rows, int cols, int left, int top, int blockSize)
{

}

//初始化
void Tetris::init()
{
    delay = 30;

    //配置随机种子
    srand(time(NULL));
}

//开始游戏
void Tetris::play()
{
    init();

    int timer = 0;
    while(1) {
        //接收用户输入
        keyEven();

        timer += getDelay();
        if (timer > delay) {
            timer = 0;
            //方块往下动 下降
            drop();
            //渲染游戏画面
            update = true;
        }

        if (update) {
            update = false;
            //更新游戏的画面
            updateWindow();

            //更新游戏数据
            clearLine();
        }

    }
}

void Tetris::keyEven()
{

}

void Tetris::updateWindow()
{

}

int Tetris::getDelay()
{

}
void Tetris::drop()
{

}

void Tetris::clearLine()
{

}