#include <stdlib.h>
#include <stdio.h>

#include "../inc/destroyer.h"
#include "../inc/global.h"
#include "../inc/buffers.h"
#include "../inc/threads.h"
#include "../inc/logger.h"

//What: Calls every initializing function in the entire program
//What for: So there won't be any access errors when the program starts
static void initialize(void){
    initializeSigaction();
    initializeGlobalVariables();
    initializeMutexes();
    initializeSemaphores();
    initializeLogger("logs","logs.txt");
    allocateBufferMemory();
    createThreads();
}


int main(){

    initialize();
    joinThreads();

}
