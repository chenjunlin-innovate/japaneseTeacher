#include "make_problems.h"

make_problems::make_problems():pos(0)
{
    MainManagement=new management;
    MainManagement->readfile();

}
