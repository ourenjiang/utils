/*
** Copyright (c) 2015 Jason Ltd. All Rights Reserved.
** brief@@: need include -rdynamic option when complie.
** file@@@: backtrace.c
** author@: JasonPan@2015.09
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <execinfo.h>
#include "backtrace.h"

#ifndef _dbg_trace
#define eDBG_TRACE 1
#define _dbg_trace(a, b) do{if((a) > 0) printf b;}while(0)
#endif/*_dbg_trace*/

//------------------------------------------------------------------------------
/*
** brief@@ SIGSEGV signal cbk.
*/
void backtrace_gnu_call(int signo)
{
    #define BACKTRACE_SIZ 100
    void *array[BACKTRACE_SIZ];
    size_t size, i;
    char **strings;
    
    size = backtrace(array, BACKTRACE_SIZ);
    strings = backtrace_symbols(array, size);
    
    _dbg_trace(eDBG_TRACE, ("----segmentation fault----\n"));
    for (i = 0; i < size; ++i) 
    {
        _dbg_trace(eDBG_TRACE, ("%p : %s\n", array[i], strings[i]));
    }
    _dbg_trace(eDBG_TRACE, ("--------------------------\n"));
    
    free(strings);
    exit(0);
}

/*
** brief@@ install SIGSEGV signal for debug when segment error.
*/
void backtrace_init(void)
{
    signal(SIGSEGV, &backtrace_gnu_call);
}

