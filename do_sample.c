/* 
 * implementation of do_bjtHomework1() 
 * @Author Brandon Tarney
 * @Date 02/16/2017
 */

#include "kernel/system.h"
#include <minix/endpoint.h>
#include <stdio.h>

/*
   * do_sample()
   *
   * Just prints out a statement and return
   */
int do_sample(struct proc* caller_ptr, message* m_ptr)
{
        printf("\ndo_sample() method - kernel call\n");
        return(OK);
}

