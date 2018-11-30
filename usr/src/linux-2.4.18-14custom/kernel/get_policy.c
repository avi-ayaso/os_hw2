
#include <linux/slab.h>
#include <linux/sched.h>

/*
=== system call number 246 ===
	If the process with PID=pid is CHANGEABLE, the wrapper returns 0 if the
	policy is disabled and 1 if it is enabled.
	Possible errors:
	If no process with the corresponding PID exists - ESRCH
	If the target process is not CHANGEABLE – EINVAL
*/
int sys_get_policy(pid_t pid) {
	int res = sys_is_changeable(pid);
	int _sc_policy = get_policy();
	switch(res) {
		case 0:	res=-EINVAL; break;
		case 1:	res=_sc_policy; break;
		default:	
	}
	return res;
}
