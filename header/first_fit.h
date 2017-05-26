#include <iostream>
#include <stdlib.h>
using namespace std;

/** first fit algorithm **/
class first_fit{
public:
    memory_init m;  /** initialize the memory **/

    /** constructing **/
    first_fit(memory_init data_memory, unsigned int process):
        m(data_memory){

            int i;

            /** check each block till the size of block is enough to allocating the process **/
            for(i=0 ; i<m.n ; i++){
                if(process <= m.data[i]){
                    m.alloc_process(i, process);
                    break;
                }
            }

            /** if more than max block, then it is failed **/
            if(i >= m.n){
                m.fail_alloc();
            }

            /** destructing the memory **/
            m.~memory_init();

    };

    /** destructing **/
    ~first_fit(){};

};
