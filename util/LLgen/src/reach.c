/*
 * (c) copyright 1987 by the Vrije Universiteit, Amsterdam, The Netherlands.
 * See the copyright notice in the ACK home directory, in the file "Copyright".
 *
 */

/*
 *  L L G E N
 *
 *  An Extended LL(1) Parser Generator
 *
 *  Author : Ceriel J.H. Jacobs
 */

/*
 * reach.c
 * Determine which nonterminals are reachable, and also check that they
 * are all defined.
 */

# include "types.h"
# include "extern.h"
# include "io.h"
# include "assert.h"

# ifndef NORCSID
static string rcsid8 = "$Header$";
# endif

/* In this file the following routines are defined: */
extern co_reach();
STATIC reachable();
STATIC reachwalk();

co_reach() {
	/*
	 * Check for undefined or unreachable nonterminals.
	 */
	register p_nont		p;
	register p_start	st;
	register p_file		x;
	register p_order	s;

	/* Check for undefined nonterminals */
	for (p = nonterms; p < maxnt; p++) {
		if (! p->n_rule) {	/* undefined */
			f_input = p->n_string;
			error(p->n_lineno,"Nonterminal %s not defined",
				p->n_name);
		}
	}

	/*
	 * Walk the grammar rules, starting with the startsymbols
	 * Mark the nonterminals that are encountered with the flag
	 * REACHABLE, and walk their rules, if not done before
	 */
	for (st = start; st; st = st->ff_next) {
		reachable(&nonterms[st->ff_nont]);
	}
	/*
	 * Now check for unreachable nonterminals
	 */
	for (x = files; x < maxfiles; x++) {
	    f_input = x->f_name;
	    for (s = x->f_list; s; s = s->o_next) {
		p = &nonterms[s->o_index];
		if (! (p->n_flags & REACHABLE)) {
			warning(p->n_lineno,"nonterminal %s unreachable",
				p->n_name);
		}
	    }
	}
}

STATIC
reachable(p) register p_nont p; {
	/*
	 * Enter the fact that p is reachable, and look for implications
	 */
	if (! (p->n_flags & REACHABLE)) {
		p->n_flags |= REACHABLE;
		/*
		 * Now walk its grammar rule
		 */
		if (p->n_rule) reachwalk(p->n_rule);
	}
}

STATIC
reachwalk(p) register p_gram p; {
	/*
	 * Walk through rule p, looking for nonterminals.
	 * The nonterminals found are entered as reachable
	 */

	for (;;) {
		switch(g_gettype(p)) {
		  case ALTERNATION :
			reachwalk(g_getlink(p)->l_rule);
			break;
		  case TERM :
			reachwalk(g_getterm(p)->t_rule);
			break;
		  case NONTERM : {
			register p_nont n = &nonterms[g_getcont(p)];

			reachable(n);
			if (n->n_rule && g_gettype(n->n_rule) == EORULE &&
			    ! g_getnpar(p) && (getntparams(n) == 0)) {
				register p_gram np = p;
				do {
					*np = *(np + 1);
					np++;
				} while (g_gettype(np) != EORULE);
				continue;
			}
			break;
		  }
		  case EORULE :
			return;
		}
		p++;
	}
}
