#include <iostream>
#include "header/memory_init.h"
#include "header/first_fit.h"
#include "header/next_fit.h"
#include "header/best_fit.h"
#include "header/worst_fit.h"
using namespace std;

int choice();   /** choice the memory management algorithm **/

int main(){
    int max_block;              /** max block of memory **/
    int max_process;            /** max process **/
    int next = 0;               /** flag for next fit, start at the first block **/
    int t;                      /** process is coming **/
    unsigned int *memory;       /** array of memory **/
    unsigned int total;         /** total size of memory **/
    unsigned int process;       /** size of process **/

    /** get the max blcok **/
    cout    << "Max Block = ";
    cin     >> max_block;

    /** allocating the array of memory **/
    if((memory = new (nothrow) unsigned int[max_block]) == NULL){
        cout    << endl << "Memori is not enough" << endl;
        exit(1);
    }

    /** initialize the memory **/
    memory_init data_memory(memory, max_block, &total);

    /** display the memory status **/
    data_memory.cetak();

    /** **/

    /** get the max process **/
    cout    << endl << "Max Proses = ";
    cin     >> max_process;

    for(t=1 ; t<=max_process ; t++){
        /** get the size of process **/
        cout    << "Process no. " << t << " = ";
        cin     >> process;

        /** choice the algorithm **/
        int i = choice();

        if(i == 1){
            first_fit nilai(data_memory, process);
            nilai.~first_fit();
        }
        else if(i == 2){
            next_fit nilai(data_memory, process, next);
            nilai.~next_fit();
        }
        else if(i == 3){
            best_fit nilai(data_memory, process);
            nilai.~best_fit();
        }
        else if(i == 4){
            worst_fit nilai(data_memory, process);
            nilai.~worst_fit();
        }
        else{ /** default **/
            first_fit nilai(data_memory, process);
            nilai.~first_fit();
        }

        /** display the memory status **/
        data_memory.cetak();
    }

    delete [] memory;
}


/** choice the memory management algorithm **/
int choice(){
    int i;

    cout    << "\nMemory Management :\n";
    cout    << "1. First Fit\n"
            << "2. Next Fit\n"
            << "3. Best Fit\n"
            << "4. Worst Fit\nChoice = ";

    cin     >> i;

    return i;
}
