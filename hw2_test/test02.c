#include "test.h"

/*
 *	This test checks the synchronization between the system calls to them self.
 */

int main() {
	start(2);
	
	int res, succ = 0, coun = 0;
	
	pid_t pid = getpid();
	
	res = is_changeable(pid);
	CHECK(res == 0, "is_changeable", "failing when process is not CHANGEABLE");
	
	res = get_policy(pid);
	CHECK((res == -1) && (errno == EINVAL), "get_policy", "failing when process is not CHANGEABLE");
	
	res = change(1);
	CHECK(res == 0, "change", "failing when all good");
	
	res = make_changeable(pid);
	CHECK(res == 0, "make_changeable", "failing when all good");
	
	res = make_changeable(pid);
	CHECK((res == -1) && (errno == EINVAL), "make_changeable", "failing when process is CHANGEABLE");
	
	res = is_changeable(pid);
	CHECK(res == 1, "is_changeable", "failing when process is CHANGEABLE");
	
	res = get_policy(pid);
	CHECK(res == 0, "get_policy", "failing when the policy does not exist because all processes are not CHANGEABLE");
	
	res = change(1);
	CHECK(res == 0, "change", "failing when the input is 1");
	
	res = get_policy(pid);
	CHECK(res == 1, "get_policy", "failing when the policy exist");
	
	res = change(0);
	CHECK(res == 0, "change", "failing when the input is 0");
	
	res = get_policy(pid);
	CHECK(res == 0, "get_policy", "failing when the policy does not exist");
	
	end(coun, succ);
}
