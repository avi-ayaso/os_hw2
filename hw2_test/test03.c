#include <sched.h>
#include "test.h"
#include <unistd.h>

#define NUM_PRO 10

int main(){
	start(3);
	
	int res, succ = 0, coun = 0;
	
	res = make_changeable(getpid());
	CHECK(res == 0, "make_changeable", "failing when all good");
	
	res = change(1);
	CHECK(res == 0, "change", "failing when all good");
	
    FILE* file = fopen("check","w");
	
	end(succ, succ);
	
    int i;
    for(i=0;i < NUM_PRO; i++){
        fork();
    }
    fprintf(file,"%d\n",getpid());
	
    return 0;
}
