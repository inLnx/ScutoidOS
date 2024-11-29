 /*
00002  * Copyright (c) 1990 The Regents of the University of California.
00003  * All rights reserved.
00004  *
00005  * Redistribution and use in source and binary forms are permitted
00006  * provided that the above copyright notice and this paragraph are
00007  * duplicated in all such forms and that any documentation,
00008  * advertising materials, and other materials related to such
00009  * distribution and use acknowledge that the software was developed
00010  * by the University of California, Berkeley.  The name of the
00011  * University may not be used to endorse or promote products derived
00012  * from this software without specific prior written permission.
00013  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
00014  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
00015  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
00016  *
00017  *      @(#)stdio.h     5.3 (Berkeley) 3/15/86
00018  */
 
 /*
00021  * NB: to fit things in six character monocase externals, the
00022  * stdio code uses the prefix `__s' for stdio objects, typically
00023  * followed by a three-character attempt at a mnemonic.
00024  */
 
 #ifndef _STDIO_H_
 #ifdef __cplusplus
 extern "C" {
 #endif
 #define _STDIO_H_
 
 #define _FSTDIO                 /* ``function stdio'' */
 
 #define __need_size_t
 #include <stddef.h>
 #define __need___va_list
 #include <stdarg.h>
 
 /*
00041  * <sys/reent.h> defines __sFILE, _fpos_t.
00042  * They must be defined there because struct _reent needs them (and we don't
00043  * want reent.h to include this file.
00044  */
 
 struct __sFile 
 {
   int unused;
 };
   
 typedef struct __sFILE FILE;
 
 #define __SLBF  0x0001          /* line buffered */
 #define __SNBF  0x0002          /* unbuffered */
 #define __SRD   0x0004          /* OK to read */
 #define __SWR   0x0008          /* OK to write */
         /* RD and WR are never simultaneously asserted */
 #define __SRW   0x0010          /* open for reading & writing */
 #define __SEOF  0x0020          /* found EOF */
 #define __SERR  0x0040          /* found error */
 #define __SMBF  0x0080          /* _buf is from malloc */
 #define __SAPP  0x0100          /* fdopen()ed in append mode - so must  write to end */
 #define __SSTR  0x0200          /* this is an sprintf/snprintf string */
 #define __SOPT  0x0400          /* do fseek() optimisation */
 #define __SNPT  0x0800          /* do not do fseek() optimisation */
 #define __SOFF  0x1000          /* set iff _offset is in fact correct */
 #define __SMOD  0x2000          /* true => fgetline modified _p text */
 #if defined(__CYGWIN__) || defined(__CYGWIN__)
 #define __SCLE  0x4000          /* convert line endings CR/LF <-> NL */
 #endif
 
 /*
00073  * The following three definitions are for ANSI C, which took them
00074  * from System V, which stupidly took internal interface macros and
00075  * made them official arguments to setvbuf(), without renaming them.
00076  * Hence, these ugly _IOxxx names are *supposed* to appear in user code.
00077  *
00078  * Although these happen to match their counterparts above, the
00079  * implementation does not rely on that (so these could be renumbered).
00080  */
 #define _IOFBF  0               /* setvbuf should set fully buffered */
 #define _IOLBF  1               /* setvbuf should set line buffered */
 #define _IONBF  2               /* setvbuf should set unbuffered */
 
 #ifndef NULL
 #define NULL    0
 #endif
 
 #define BUFSIZ  1024
 #define EOF     (-1)
 
 #define FOPEN_MAX       20      /* must be <= OPEN_MAX <sys/syslimits.h> */
 #define FILENAME_MAX    1024    /* must be <= PATH_MAX <sys/syslimits.h> */
 #define L_tmpnam        1024    /* XXX must be == PATH_MAX */
 #ifndef __STRICT_ANSI__
 #define P_tmpdir        "/tmp"
 #endif
 
 #ifndef SEEK_SET
 #define SEEK_SET        0       /* set file offset to offset */
 #endif
 #ifndef SEEK_CUR
 #define SEEK_CUR        1       /* set file offset to current plus offset */
 #endif
 #ifndef SEEK_END
 #define SEEK_END        2       /* set file offset to EOF plus offset */
 #endif
 
 #define TMP_MAX         26
 
 #define stdin   (_impure_ptr->_stdin)
 #define stdout  (_impure_ptr->_stdout)
 #define stderr  (_impure_ptr->_stderr)
 
 #define _stdin_r(x)     ((x)->_stdin)
 #define _stdout_r(x)    ((x)->_stdout)
 #define _stderr_r(x)    ((x)->_stderr)
 
 /*
00120  * Functions defined in ANSI C standard.
00121  */
 
 #ifdef __GNUC__
 #define __VALIST __gnuc_va_list
 #else
 #define __VALIST char*
 #endif
 #ifndef _EXFUN
 # define _EXFUN(N,P) N P
 #endif
 
 int     _EXFUN(printf, (const char *, ...));
 int     _EXFUN(scanf, (const char *, ...));
 int     _EXFUN(sscanf, (const char *, const char *, ...));
 int     _EXFUN(vfprintf, (FILE *, const char *, __VALIST));
 int     _EXFUN(vprintf, (const char *, __VALIST));
 int     _EXFUN(vsprintf, (char *, const char *, __VALIST));
 int     _EXFUN(vsnprintf, (char *, size_t, const char *, __VALIST));
 int     _EXFUN(fgetc, (FILE *));
 char *  _EXFUN(fgets, (char *, int, FILE *));
 int     _EXFUN(fputc, (int, FILE *));
 int     _EXFUN(fputs, (const char *, FILE *));
 int     _EXFUN(getc, (FILE *));
 int     _EXFUN(getchar, (void));
 char *  _EXFUN(gets, (char *));
 int     _EXFUN(putc, (int, FILE *));
 int     _EXFUN(putchar, (int));
 int     _EXFUN(puts, (const char *));
 int     _EXFUN(ungetc, (int, FILE *));
 size_t  _EXFUN(fread, (void *, size_t _size, size_t _n, FILE *));
 size_t  _EXFUN(fwrite, (const void *, size_t _size, size_t _n, FILE *));
 
 int     _EXFUN(sprintf, (char *, const char *, ...));
 int     _EXFUN(snprintf, (char *, size_t, const char *, ...));
 
 #ifdef __cplusplus
 }
 #endif
 #endif /* _STDIO_H_ */