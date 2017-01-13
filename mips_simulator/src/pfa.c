#include <stdio.h>
#include <stdlib.h>
#include <mips.h>

void pfa_init(PFA *pfa, Path *a, Path *b, Path *carryin, Path *g, Path *p, Path *s){
	pfa -> agate1 = (ANDGate *)malloc(sizeof(ANDGate));
	pfa -> ogate1 = (ORGate *)malloc(sizeof(ORGate));
	pfa -> f1 = (FA *)malloc(sizeof(FA));

	andgate_init(pfa -> agate1, a, b, g);
	orgate_init(pfa -> ogate1, a, b, p);
	fa_init(pfa -> f1, a, b, carryin, s, NULL);			// the second s is not used
}

void pfa_run(PFA *pfa){
	andgate_run(pfa -> agate1);
	orgate_run(pfa -> ogate1);
	fa_run(pfa -> f1);
}

void pfa_release(PFA *pfa){
	free(pfa -> agate1);
	free(pfa -> ogate1);
	free(pfa -> f1);
}


