#include "./freetaskLib/freetask.h"
#include "_includes.h"




//示例创建任务
int freetask(){
    BlockUntil(1);

    return 0;
}

vex::task Task = vex::task(freetask);//示例调用

int myCallback(void *arg) {
    int *intArg = static_cast<int *>(arg);
    std::cout << "Callback called with arg: " << *intArg << std::endl;
    return *intArg;
}
