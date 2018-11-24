#ifndef _SYS_CALLS_H_
#define _SYS_CALLS_H_

#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
 #include <unistd.h>
#include <sched.h>


/*
=== system call number 243 ===
	The wrapper will return 1 if the given process is a CHANGEABLE process,
	or 0 if it is not.
	Possible errors:
	If no process with the corresponding PID exists - ESRCH
*/
int is_changeable(pid_t pid) { 
	// wrapper
	int res = 0;
	errno = 0;
	__asm__ (
		"int $0x80;"
		: "=a" (res)		// output should be in eax -> res
		: "0" (243) , "b" (pid)	// eax ; ebx
		: "memory"
	);
	if (res < 0) {
		errno= -res ;
		res= -1 ;
	}

	return res ;
}


/*
=== system call number 244 ===
	If the caller process and the target process are both not CHANGEABLE,
	the wrapper should return 0 and the process whose PID is pid should
	become CHANGEABLE. Note that upon success the target process must
	immediately be informed whether the regime is enabled or disabled for
	CHANGEABLE processes, i.e. whether SC processes are currently
	maintaining FIFO order or not, and act accordingly.
	In other words, if there is at least one CHANGEABLE process alive
	at the time the target process becomes CHANGEABLE, regardless of its
	state- whether it is running or not, the target process should act the
	same. If no such processes exist, the neophyte process should consider the
	regime disabled. It is your responsibility to make sure that at any given
	time all CHANGEABLE processes conform to the same regime. Possible errors:
	If no process with the corresponding PID exists - ESRCH
	if the given process or the calling process is a CHANGEABLE process - EINVAL
*/
int make_changeable(pid_t pid) {
// wrapper
	int res = 0;
	errno = 0;
	__asm__ (
		"int $0x80;"
		: "=a" (res)		// output should be in eax -> res
		: "0" (244) , "b" (pid)	// eax ; ebx
		: "memory"
	);
	if (res < 0) {
		errno= -res ;
		res= -1 ;
	}
	return res;
}

/*
=== system call number 245 ===
	The syscall changes the regime for SCHED_CHANGEABLE processes.
	If val is 0, all CHANGEABLE processes should go back to behaving like
	regular OTHER processes. If val is 1, all CHANGEABLE processes should start
	following the regime specified previously.
*/
int change(int val) {
	// wrapper
	int res = 0;
	errno = 0;
	__asm__ (
		"int $0x80;"
		: "=a" (res)		// output should be in eax -> res
		: "0" (245) , "b" (val)	// eax ; ebx
		: "memory"
	);
	if (res < 0) {
		errno= -res ;
		res= -1 ;
	}

	return res ;
}

/*
=== system call number 246 ===
	If the process with PID=pid is CHANGEABLE, the wrapper returns 0 if the
	policy is disabled and 1 if it is enabled.
	Possible errors:
	If no process with the corresponding PID exists - ESRCH
	If the target process is not CHANGEABLE – EINVAL
*/
int get_policy(pid_t pid) { 
	int res = 0;
	errno = 0;
	__asm__ (
		"int $0x80;"
		: "=a" (res)		// output should be in eax -> res
		: "0" (246) , "b" (pid)	// eax ; ebx
		: "memory"
	);
	if (res < 0) {
		errno= -res ;
		res= -1 ;
	}

	return res ;
}

#endif /* _SYS_CALLS_H_ */
