#include "./freetaskLib/freetask.h"
#include "_includes.h"




//ʾ����������
int freetask(){
    BlockUntil(1);

    return 0;
}

vex::task Task = vex::task(freetask);//ʾ������

int myCallback(void *arg) {
    int *intArg = static_cast<int *>(arg);
    std::cout << "Callback called with arg: " << *intArg << std::endl;
    return *intArg;
}
