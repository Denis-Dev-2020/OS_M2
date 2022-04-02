Description
The C library function void (*signal(int sig, void (*func)(int)))(int) sets a function to handle signal i.e. a signal handler with signal number sig.

Declaration
Following is the declaration for signal() function.

void (*signal(int sig, void (*func)(int)))(int)
Parameters
sig − This is the signal number to which a handling function is set. The following are few important standard signal numbers −

Sr.No.	Macro & Signal
1	
SIGABRT

(Signal Abort) Abnormal termination, such as is initiated by the function.

2	
SIGFPE

(Signal Floating-Point Exception) Erroneous arithmetic operation, such as zero divide or an operation resulting in overflow (not necessarily with a floating-point operation).

3	
SIGILL

(Signal Illegal Instruction) Invalid function image, such as an illegal instruction. This is generally due to a corruption in the code or to an attempt to execute data.

4	
SIGINT

(Signal Interrupt) Interactive attention signal. Generally generated by the application user.

5	
SIGSEGV

(Signal Segmentation Violation) Invalid access to storage − When a program tries to read or write outside the memory it is allocated for it.

6	
SIGTERM

(Signal Terminate) Termination request sent to program.

func − This is a pointer to a function. This can be a function defined by the programmer or one of the following predefined functions −