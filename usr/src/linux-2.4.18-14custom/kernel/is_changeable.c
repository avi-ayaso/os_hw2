
#include "sys_calls_utills.h"

/*
=== system call number 243 ===
	The wrapper will return 1 if the given process is a CHANGEABLE process,
	or 0 if it is not.
	Possible errors:
	If no process with the corresponding PID exists - ESRCH
*/
int sys_is_changeable(pid_t pid) {
	if (pid < 0) {
		return -ESRCH;
	}
	task_t * p = find_task_by_pid(pid);
	if ( p == NULL ) {
		return -ESRCH;
	}
	return (p->policy == SCHED_CHANGEABLE);
}