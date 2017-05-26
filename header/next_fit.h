#include <iostream>
#include <stdlib.h>
using namespace std;

/** next fit algorithm **/
class next_fit{
public:
    memory_init m;  /** initialize the memory **/

    /** constructing **/
    next_fit(memory_init data_memory, unsigned int process, int &next):
        m(data_memory){
            int i;

            /** check each block **/
            for(i=0 ; i<m.n ; i++){

                /** if more than max block, go to the first block **/
                if(next >= m.n){
                    next = 0;
                }


                /** allocating the process **/
                if(process <= m.data[next]){
                    m.alloc_process(next, process);
                    break;
                }
                next++;
            }


            /** failed **/
            if(i >= m.n){
                m.fail_alloc();
            }

            /** destructing the memory **/
            m.~memory_init();

    };

    /** destructing **/
    ~next_fit(){};
};
