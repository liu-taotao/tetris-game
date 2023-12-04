# 🌟tetris-game
vscode中编译工程出现问题
---------------------------------------------

* 注意去查找在vscode中多个Cpp文件编译出现的问题，这里我找到了解决方案。[vscode编译多个Cpp文件](https://blog.csdn.net/m0_50609661/article/details/126330155)

* 这些都好了以后，还需要配置 easyx库。同理，这个也很简单。[参考现有的文章解释，点击](https://blog.csdn.net/m0_73676501/article/details/130421076)

* 发现一个有趣的事情，实现左右移动的时候要对着vscode的命令窗口，而不是图形窗口。
* 笔记本缩放比例默认125%，调成100%，就可以正常显示窗口大小了。
* 在使用mciSendString()播放音频函数时要添加包含的库和记得在`task.json` 中的`args` 中添加编译选项  **"-lwinmm"** ，否则会报错。

功能
-------

* 实现左右移动、降落
* 实现消除，方块变化
* 实现关卡、消除行数、得分
* 实现永久记录最高分
* 游戏结束动画、音效........

掌握了什么呢？
-------------------

* 什么叫面向对象
* 如何搭架构
* 虽然没有涉及到多态，继承。但是涉及到了私有、公共的关系，也掌握了easyx库的使用

最终效果
------------

#### 其他的后续再补充，有用的话记得点星星⭐~

* 游戏进行

![final](./img/final.png)

* 游戏结束

![final](./img/gameover.png)

* 终端

  ![final](./img/output.png)

