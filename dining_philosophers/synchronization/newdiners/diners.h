/*
 * Header file for the diners.  Note that the semaphore variables are defined
 * here as global variables.
 */
#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/sem.h>
#include	<sched.h>
#include	<stdio.h>
#include	<errno.h>

#include "simp_sem.h"

#define N 		5		/* number of philosophers */

typedef int semaphore;
extern semaphore mutex;
extern semaphore s[N];

void *philosopher (void *);
