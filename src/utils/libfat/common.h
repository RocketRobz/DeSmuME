/*
 common.h
 Common definitions and included files for the FATlib

 Copyright (c) 2006 Michael "Chishm" Chisholm
	
 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation and/or
     other materials provided with the distribution.
  3. The name of the author may not be used to endorse or promote products derived
     from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _COMMON_H
#define _COMMON_H

#define BYTES_PER_READ 512
#include <stddef.h>
#ifndef _MSC_VER
#include <stdint.h>
#endif

#include "types.h"

// When compiling for NDS, make sure NDS is defined
#ifndef NDS
 #if defined ARM9 || defined ARM7
  #define NDS
 #endif
#endif

// Platform specific includes
#if defined(__gamecube__) || defined (__wii__)
   #include <gctypes.h>
   #include <ogc/disc_io.h>
   #include <gccore.h>
#elif defined(NDS)
   #include <nds/ndstypes.h>
   #include <nds/system.h>
   #include <nds/disc_io.h>
#elif defined(GBA)
   #include <gba_types.h>
   #include <disc_io.h>
#elif defined(__3DS__)
  #include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dirent.h>
#include <sys/iosupport.h>
#include <sys/param.h>
#include <unistd.h>
#endif

// Platform specific options
#if   defined (__wii__)
   #define DEFAULT_CACHE_PAGES 4
   #define DEFAULT_SECTORS_PAGE 64
   #define USE_LWP_LOCK
   #define USE_RTC_TIME
#elif defined (__gamecube__)
   #define DEFAULT_CACHE_PAGES 4
   #define DEFAULT_SECTORS_PAGE 64
   #define USE_LWP_LOCK
   #define USE_RTC_TIME
#elif defined (NDS) || defined (__3DS__)
   #define DEFAULT_CACHE_PAGES 4
   #define DEFAULT_SECTORS_PAGE 8
   #define USE_RTC_TIME
#elif defined (GBA)
   #define DEFAULT_CACHE_PAGES 2
   #define DEFAULT_SECTORS_PAGE 8
   #define LIMIT_SECTORS 128
#else
   #define LIBFAT_PC 1

	//any particular reason for this?
   #define DEFAULT_CACHE_PAGES 4
   #define DEFAULT_SECTORS_PAGE 8
#endif

#include "libfat_pc.h"

#include "fat.h"

#endif // _COMMON_H
