#ifndef __THREAD_DEFINITION_H__
#define	__THREAD_DEFINITION_H__
////////////////////////////////////////////////////
#if (defined(_WIN32) || defined(_WIN64))
// Includes ----------------------
#include <Windows.h>
// Macros ----------------------

#define ThreadHandle	HANDLE
#define InvalidThread	INVALID_HANDLE_VALUE
#define CloseThread(t)	if(InvalidThread != t){CloseHandle(t); t = InvalidThread;}
#define ThreadReturn(res)	res
// Type definition --------------


#else
// Includes ----------------------
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
// Macros ----------------------

#define ThreadHandle	pthread_t*
#define ThreadObject	pthread_t
#define InvalidThread	(ThreadHandle)nullptr
#define CloseThread(t)	if(InvalidThread != t){delete t; t = InvalidThread;}
#define Sleep(milisec)	sleep(milisec/1000)
#define ThreadReturn(res)	reinterpret_cast<void*>(res)
#define HANDLE			int
#define CloseHandle(h)	close(h)

// Type definition --------------

#endif
///////////////////////////////////////////////////
#endif	//__THREAD_DEFINITION_H__