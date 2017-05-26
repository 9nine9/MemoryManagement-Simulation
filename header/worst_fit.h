#include <iostream>
#include <stdlib.h>
using namespace std;

/** worst fit algorithm **/
class worst_fit{
public:
    memory_init m;  /** initialize the memory **/

    worst_fit(memory_init data_memory, unsigned int process):
        m(data_memory){

            int i, flag = 0;
            unsigned int worst_size = m.data[flag];     /** initialize the worst size of block is first block **/

            /** check till max block for the worst size **/
            for(i=1 ; i<m.n ; i++){
                if(worst_size < m.data[i] && process <= m.data[i]){
                    flag = i;
                    worst_size = m.data[flag];
                }
            }

            if(worst_size >= process){
                m.alloc_process(flag, process); /** allocating the process **/
            }
            else{
                m.fail_alloc(); /** fail **/
            }

            /** destructing the memory **/
            m.~memory_init();

    };

    /** destructing **/
    ~worst_fit(){};

};
