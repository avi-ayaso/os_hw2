/*
=== system call number 245 ===
	The syscall changes the regime for SCHED_CHANGEABLE processes.
	If val is 0, all CHANGEABLE processes should go back to behaving like
	regular OTHER processes. If val is 1, all CHANGEABLE processes should start
	following the regime specified previously.
*/
int change(int val) {
}