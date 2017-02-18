/*
 * assert.c - diagnostics
 */

#include	<assert.h>
#include	<stdio.h>
#include <minix/com.h>

#include <sys/types.h>
#include <stdlib.h>
#include <minix/sysutil.h>
#include "syslib.h"

void
__assert13(file, line, function, failedexpr)
	const char *file, *function, *failedexpr;
	int line;
{
	(void)printf("%s:%d: assert \"%s\" failed", file, line, failedexpr);
	if(function) printf(", function \"%s\"", function);
	printf("\n");
	panic("assert failed");
	/* NOTREACHED */
}

void
__assert(file, line, failedexpr)
	const char *file, *failedexpr;
	int line;
{

	__assert13(file, line, NULL, failedexpr);
	/* NOTREACHED */
}

/*
//BJT added test code here
int sys_sample(void)
{
        message m;
        //Added for testing purposes
        printf("\n*Library Kernel Call*\n");
        return(_kernel_call(SYS_SAMPLE, &m));
}
*/
