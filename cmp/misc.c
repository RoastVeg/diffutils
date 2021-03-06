/*      $OpenBSD: misc.c,v 1.7 2018/03/05 16:53:39 cheloha Exp $      */
/*      $NetBSD: misc.c,v 1.2 1995/09/08 03:22:58 tls Exp $      */

/*-
 * Copyright (c) 1991, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/types.h>

#include <bsd/err.h>
#include <stdarg.h>
#include <bsd/stdio.h>
#include <bsd/stdlib.h>

#include "extern.h"

void
eofmsg(char *file)
{
	if (!sflag)
		warnx("EOF on %s", file);
	exit(DIFF_EXIT);
}

void
diffmsg(char *file1, char *file2, off_t byte, off_t line)
{
	if (!sflag)
		(void)printf("%s %s differ: char %lld, line %lld\n",
		    file1, file2, (long long)byte, (long long)line);
	exit(DIFF_EXIT);
}

void
fatal(const char *fmt, ...)
{
	va_list ap;

	if (!sflag) {
		va_start(ap, fmt);
		vwarn(fmt, ap);
		va_end(ap);
	}
	exit(ERR_EXIT);
}

void
fatalx(const char *fmt, ...)
{
	va_list ap;

	if (!sflag) {
		va_start(ap, fmt);
		vwarnx(fmt, ap);
		va_end(ap);
	}
	exit(ERR_EXIT);
}
