#include "test.h"

/*
 *	This test checks the system calls with illegal input.
 */

int main() {
	start(1);
	
	int res, succ = 0, coun = 0;
	
	res = is_changeable(-1);
	CHECK((res == -1) && (errno == ESRCH), "is_changeable", "failing when pid is invalid");
	
	res = is_changeable(0);
	CHECK((res == -1) && (errno == ESRCH), "is_changeable", "failing when process is not CHANGEABLE");
	
	res = is_changeable(20000);
	CHECK((res == -1) && (errno == ESRCH), "is_changeable", "failing when pid is not exist");
	
	res = make_changeable(-1);
	CHECK((res == -1) && (errno == ESRCH), "make_changeable", "failing when pid is invalid");
	
	res = make_changeable(20000);
	CHECK((res == -1) && (errno == ESRCH), "make_changeable", "failing when pid is not exist");
	
	res = change(-1);
	CHECK((res == -1) && (errno == EINVAL), "change", "failing when val is lower");
	
	res = change(2);
	CHECK((res == -1) && (errno == EINVAL), "change", "failing when val is bigger");
	
	res = get_policy(-1);
	CHECK((res == -1) && (errno == ESRCH), "get_policy", "failing when pid is invalid");
	
	res = get_policy(0);
	CHECK((res == -1) && (errno == ESRCH), "get_policy", "failing when process is not CHANGEABLE");
	
	res = get_policy(20000);
	CHECK((res == -1) && (errno == ESRCH), "get_policy", "failing when pid is not exist");
	
	end(coun, succ);
}
