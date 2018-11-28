
#include "sys_calls_utills.h"

extern sc_policy;
/*
=== system call number 245 ===
	The syscall changes the regime for SCHED_CHANGEABLE processes.
	If val is 0, all CHANGEABLE processes should go back to behaving like
	regular OTHER processes. If val is 1, all CHANGEABLE processes should start
	following the regime specified previously.
*/
int sys_change(int val) {
	switch(val) {
		case 0:	sc_policy = 0; break;
		case 1:	sc_policy = 1; break;
		default:	return -EINVAL;
	}
	return 0;
}