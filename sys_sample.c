/* system library funciton to make kernel cal
   *
   * @Author Brandon Tarney
   * @Date 02/17/2017
   */

#include "syslib.h"

int sys_sample(void)
{
        message m;
        //Added for testing purposes
        printf("\n*Library Kernel Call*\n");
        return(_kernel_call(SYS_SAMPLE, &m));
}

