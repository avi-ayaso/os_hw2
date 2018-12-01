/*
- parallel processes
	* make some processes, every process will do some forbidden activities,
	  and then we will check that every process has it and only it forbidden activities in its log
 */
#include "test.h"

int main()
{
        int retval;
               //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        int father1=getpid();
        int son1;
        int son2;
        retval=fork();
        if(retval==0){//son1
                son1=getpid();
                retval=fork();
                if(retval==0){//son2
                        son2=getpid();
                        TASSERT((retval=make_changeable(father1)) ==0,
                                "unexpected error in enable_policy (retval=%d)",retval);
                        
                        TASSERT((retval=make_changeable(son1)) ==0,
                                "unexpected error in set_process_capabilities (retval=%d)",retval);
                  } else{//son1
			wait(NULL);
			int i=0;
			for(;i<10;i++)fork();
                }
        }else{//father1
                     wait(NULL); 
			fork();                       
        }
	make_changeable(getpid());
//printf("is changeable: %d\n",is_changeable(father1));
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
printf("success");
        return 0;
}
