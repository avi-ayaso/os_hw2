
#include <linux/slab.h>
#include <linux/sched.h>

//extern int sc_policy;
/*
=== system call number 245 ===
	The syscall changes the regime for SCHED_CHANGEABLE processes.
	If val is 0, all CHANGEABLE processes should go back to behaving like
	regular OTHER processes. If val is 1, all CHANGEABLE processes should start
	following the regime specified previously.
*/
int sys_change(int val) {
	int _sc_policy = get_policy();
	switch(val) {
		case 0:	unset_policy(); 
		break;
		case 1:	set_policy();
		break;
		default:	return -EINVAL;
	}
	return 0;
}
