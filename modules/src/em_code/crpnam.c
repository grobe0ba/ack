#include "em_private.h"

/* $Id$ */

void
CC_crpnam(op, p)
	char *p;
{
	/*	CON or ROM with argument PNAM(p)
	*/
	PS(op);
	PNAM(p);
	CEND();
	NL();
}
