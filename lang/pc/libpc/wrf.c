/*
 * (c) copyright 1983 by the Vrije Universiteit, Amsterdam, The Netherlands.
 *
 *          This product is part of the Amsterdam Compiler Kit.
 *
 * Permission to use, sell, duplicate or disclose this software must be
 * obtained in writing. Requests for such permissions may be sent to
 *
 *      Dr. Andrew S. Tanenbaum
 *      Wiskundig Seminarium
 *      Vrije Universiteit
 *      Postbox 7161
 *      1007 MC Amsterdam
 *      The Netherlands
 *
 */

/* Author: J.W. Stevenson */

#include	<pc_file.h>

extern		_wstrin();
extern char	*_fcvt();

#define	assert()	/* nothing */

#define	HUGE_DIG	39	/* log10(maxreal) */
#define	PREC_DIG	80	/* the maximum digits returned by _fcvt() */
#define	FILL_CHAR	'0'	/* char printed if all of _fcvt() used */
#define	BUFSIZE		HUGE_DIG + PREC_DIG + 2

_wrf(n,w,r,f) int n,w; double r; struct file *f; {
	char *p,*b; int s,d; char buf[BUFSIZE];

	p = buf;
	if (n > PREC_DIG)
		n = PREC_DIG;
	b = _fcvt(r,n,&d,&s);
	assert(abs(d) <= HUGE_DIG);
	if (s)
		*p++ = '-';
	if (d<=0)
		*p++ = '0';
	else
		do
			*p++ = (*b ? *b++ : FILL_CHAR);
		while (--d > 0);
	if (n > 0)
		*p++ = '.';
	while (++d <= 0) {
		if (--n < 0)
			break;
		*p++ = '0';
	}
	while (--n >= 0) {
		*p++ = (*b ? *b++ : FILL_CHAR);
		assert(p <= buf+BUFSIZE);
	}
	_wstrin(w,p-buf,buf,f);
}
