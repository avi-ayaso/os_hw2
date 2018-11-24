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
