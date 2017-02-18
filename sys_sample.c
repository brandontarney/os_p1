/*
   * BJT Kernel Call Library
   * @Author Brandon Tarney
   * @Date 02/18/2017
   */

#include "syslib.h"

int sys_sample(void)
{
        message m;
        return(_kernel_call(SYS_SAMPLE, &m));
}

