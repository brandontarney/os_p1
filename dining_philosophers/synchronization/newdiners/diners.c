
#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/sem.h>
#include	<unistd.h>
#include	<sched.h>
#include	<stdio.h>
#include	<errno.h>

#include "simp_sem.h"
#include "diners.h"
/*
 * Taken from "Operating Systems - Design and Implementation" by Tanenbaum
 * Section 2.3, page 91, Figure 2-10
 */
#define LEFT 		(i + N - 1) % N	/* i's left neighbor */
#define RIGHT 		(i + 1) % N	/* i's right neighbor */
#define THINKING	0		/* philosopher states */
#define HUNGRY		1
#define EATING		2

int state[N];
semaphore s[N];
semaphore mutex;


void take_forks (int);
void put_forks (int);
void test (int);
void print_state (int, char *);

void think (int);
void eat (int);

void *philosopher (void *in)
{
	int i = *(int *)in;
	int awhile = 5;

	while (awhile--)
	{
		think(i);
		take_forks(i);
		eat(i);
		put_forks (i);
	}
}

void
take_forks (int i)
{
	sem_wait (mutex);
	state[i] = HUNGRY;
	test(i);
	sem_signal (mutex);
	sem_wait (s[i]);
	print_state (i, "EAT");
}

void
put_forks (int i)
{
	sem_wait (mutex);
	print_state(i, "DONE");
	state[i] = THINKING;
	test(LEFT);
	test(RIGHT);
	sem_signal (mutex);
}

void
test (int i)
{
	if (state[i] == HUNGRY &&
		state[LEFT] != EATING &&
		state[RIGHT] != EATING)
	{
		print_state (i, "TAKE");
		state[i] = EATING;
		sem_signal (s[i]);
	}
	else
		print_state (i, "WAIT");
}

void think (int i)
{
/*	printf ("Philosopher %d thinking\n", i); */
	sleep (2);
/*	printf ("Philosopher %d done thinking\n", i); */
}

void eat (int i)
{
/*	printf ("Philosopher %d eating (%d, %d)\n", i, state[LEFT], state[RIGHT]); */
	sleep (1);
/*	printf ("Philosopher %d done eating\n", i); */
}

void
print_state (int i, char *state)
{
	while (i--)
	{
		printf ("	");
	}
	printf ("%s\n", state);
}
