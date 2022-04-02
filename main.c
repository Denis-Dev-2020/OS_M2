#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int invoke_SIGFPE() {
	return 123 / 0;
}
int invoke_SIGCHLD() {
	if (!(fork()))
	{
		exit(1);
	}
	return 0;
}
int invoke_SIGSEG() {
	int a[4];
	for (int i = 0 ; i < 2000000 ; i++) {
		a[i] = i + 1;
	}
}
void sig_handler(int signum)
{
	switch (signum)
	{

	case SIGCHLD:
		printf("\nI am in SIGCHLD - %d\n", getpid());
		fflush(stdout);
		invoke_SIGSEG();
	case SIGFPE:
		printf("\nI am in SIGFPE - %d\n", getpid());
		fflush(stdout);
		asm("ud2");
	case SIGILL:
		printf("\nI am in SIGILL - %d\n", getpid());
		raise(SIGINT);
		fflush(stdout);
	case SIGSEGV:
		printf("\nI am in SIGSEGV  - %d\n", getpid());
		fflush(stdout);
		invoke_SIGFPE();
		raise(SIGTERM);
	case SIGINT:
		printf("\nI am in SIGINT  - %d\n", getpid());
		exit(1);

	}
}
int SignalMatch_ToHandlers() {
	signal(SIGCHLD, sig_handler);
	signal(SIGSEGV, sig_handler);
	signal(SIGFPE, sig_handler);
	signal(SIGILL, sig_handler);
	signal(SIGINT, sig_handler);
}
int main()
{
	int status;
	SignalMatch_ToHandlers();
	invoke_SIGCHLD();
	wait(&status);
}