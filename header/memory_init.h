#include <iostream>
#include <stdlib.h>
using namespace std;

/** initialize the memory **/
class memory_init{
public:
    int n;                  /** max block **/
    unsigned int *data;     /** array of memory **/
    unsigned int *pos;      /** position the block in the memory **/
    unsigned int *total;    /** total size of memory **/

    /** constructing the memory **/
    memory_init(unsigned int *memory, int m, unsigned int *tot) :
        data(memory), n(m), total(tot){

            unsigned int last = 0;  /** make last position of memory is 0 **/

            /** allocating the array of position **/
            if((pos = new (nothrow) unsigned int[n]) == NULL){
                cout    << endl << "Memori is not enough" << endl;
                exit(1);
            }

            /** input size of memory block**/
            for(int i=0 ; i<n ; i++){
                cout    << "Block no. " << i+1 <<" = ";
                cin     >> data[i];

                pos[i]     = last + 1;              /** first position of this block **/
                last       = pos[i] + data[i] - 1;  /** last position of this block **/
            }

            /** total size of memory is last position of last block **/
            *total = last;
    };

    /** destructing the memory **/
    ~memory_init(){
    };

    /** display the memory status **/
    void cetak(){
        unsigned int last;

        /** title **/
        cout    << "\n\n----------\n\n";
        cout    << "No. Block" << "\t" << "Size" << "\t\t" << "Location" << "\n";

        /** display memory block **/
        for(int i=0 ; i<n ; i++){
            last    = pos[i] + data[i] - 1;

            if(data[i] > 0)
                cout    << i+1 << "\t\t" << data[i] << "\t\t" << pos[i] << "-" << last << "\n";
            else
                cout    << i+1 << "\t\t" << data[i] << "\t\t-\n";
        }

        cout    << "\n\n" << "Free memory = " << *total;
        cout    << "\n\n----------\n\n";
    };

    /** allocating the process  **/
    void alloc_process(int i, unsigned int process){
        unsigned int last = pos[i] + process - 1;   /** last position of this process **/

        cout    << "\n\n-- Allocating the process --\n";
        cout    << "Block no. : " << i+1 << "\n";
        cout    << "Location  : " << pos[i] << "-" << last << "\n";

        data[i] -= process;     /** size of block is updated **/
        pos[i]  += process;     /** first position of block is updated **/
        *total  -= process;     /** tota size of memory is updated **/
    };

    /** fail to allocating because the size of block less than the size of process **/
    void fail_alloc(){
        cout    << "\n\n-- Fail to Allocating the process to memory --\n\n";
    };
};
