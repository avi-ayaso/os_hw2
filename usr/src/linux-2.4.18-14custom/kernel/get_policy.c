/*
=== system call number 246 ===
	If the process with PID=pid is CHANGEABLE, the wrapper returns 0 if the
	policy is disabled and 1 if it is enabled.
	Possible errors:
	If no process with the corresponding PID exists - ESRCH
	If the target process is not CHANGEABLE – EINVAL
*/
int get_policy(pid_t pid) {
}