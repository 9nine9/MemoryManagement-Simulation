#include <iostream>
#include <stdlib.h>
using namespace std;

/** best fit algorithm **/
class best_fit{
public:
    memory_init m;  /** initialize the memory **/

    /** constructing **/
    best_fit(memory_init data_memory, unsigned int process):
        m(data_memory){

            int i, flag = 0;
            unsigned int best_size = m.data[flag];  /** initialize the best size of block is first block **/

            /** check till max block for the best size **/
            for(i=1 ; i<m.n ; i++){
                if(best_size > m.data[i] && process <= m.data[i]){
                    flag = i;
                    best_size = m.data[flag];
                }
            }

            if(best_size >= process){
                m.alloc_process(flag, process); /** allocating the process **/
            }
            else{
                m.fail_alloc(); /** fail **/
            }

            /** destructing the memory **/
            m.~memory_init();

    };

    /** destructing **/
    ~best_fit(){};

};
