/* C code for program foreignTypesTest, generated by snc from ../foreignTypes.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 3 "../foreignTypes.st"
#include "../testSupport.h"
# line 7 "../foreignTypes.st"
struct struct_t { int i; struct { double d; } s; };
# line 8 "../foreignTypes.st"
union union_t { int i; struct struct_t *p; };
# line 9 "../foreignTypes.st"
enum enum_t { zero, one, two };
# line 10 "../foreignTypes.st"
typedef short typedef_t;

/* Variable declarations */
# line 12 "../foreignTypes.st"
static	struct struct_t s;
# line 13 "../foreignTypes.st"
static	union union_t u;
# line 14 "../foreignTypes.st"
static	enum enum_t e;
# line 15 "../foreignTypes.st"
static	typedef_t t;


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 12 "../foreignTypes.st"
	static struct struct_t seqg_initvar_s = {1, {0.1}};
	memcpy(&s, &seqg_initvar_s, sizeof(seqg_initvar_s));
	}
	{
# line 13 "../foreignTypes.st"
	static union union_t seqg_initvar_u = {13};
	memcpy(&u, &seqg_initvar_u, sizeof(seqg_initvar_u));
	}
	{
# line 14 "../foreignTypes.st"
	static enum enum_t seqg_initvar_e = one;
	memcpy(&e, &seqg_initvar_e, sizeof(seqg_initvar_e));
	}
	{
# line 15 "../foreignTypes.st"
	static typedef_t seqg_initvar_t = 42;
	memcpy(&t, &seqg_initvar_t, sizeof(seqg_initvar_t));
	}
}

/* Program entry func */
static void seqg_entry(SS_ID seqg_env)
{
# line 18 "../foreignTypes.st"
	seq_test_init(24);
}

/****** Code for state "simple" in state set "simple" ******/

/* Event function for state "simple" in state set "simple" */
static seqBool seqg_event_simple_0_simple(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "simple" in state set "simple" */
static void seqg_action_simple_0_simple(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 24 "../foreignTypes.st"
			struct struct_t *ps = &s;
# line 25 "../foreignTypes.st"
			union union_t *pu = &u;
# line 26 "../foreignTypes.st"
			enum enum_t *pe = &e;
# line 27 "../foreignTypes.st"
			typedef_t *pt = &t;
# line 29 "../foreignTypes.st"
			testOk1(s.i == 1);
# line 30 "../foreignTypes.st"
			testOk1(s.s.d == 0.1);
# line 31 "../foreignTypes.st"
			testOk1(u.i == 13);
# line 32 "../foreignTypes.st"
			u.p = ps;
# line 33 "../foreignTypes.st"
			testOk1(u.p == ps);
# line 34 "../foreignTypes.st"
			testOk1(u.p->i == 1);
# line 35 "../foreignTypes.st"
			testOk1(u.p->s.d == 0.1);
# line 36 "../foreignTypes.st"
			u.i = 13;
# line 37 "../foreignTypes.st"
			testOk1(e == one);
# line 38 "../foreignTypes.st"
			testOk1(t == 42);
# line 40 "../foreignTypes.st"
			testOk1(ps->i == 1);
# line 41 "../foreignTypes.st"
			testOk1(ps->s.d == 0.1);
# line 42 "../foreignTypes.st"
			testOk1(pu->i == 13);
# line 43 "../foreignTypes.st"
			pu->p = ps;
# line 44 "../foreignTypes.st"
			testOk1(pu->p == ps);
# line 45 "../foreignTypes.st"
			testOk1(pu->p->i == 1);
# line 46 "../foreignTypes.st"
			testOk1(pu->p->s.d == 0.1);
# line 47 "../foreignTypes.st"
			pu->i = 13;
# line 48 "../foreignTypes.st"
			testOk1(*pe == one);
# line 49 "../foreignTypes.st"
			testOk1(*pt == 42);
# line 51 "../foreignTypes.st"
			ps->i++;
# line 52 "../foreignTypes.st"
			ps->s.d /= 3.0;
# line 53 "../foreignTypes.st"
			pu->i--;
# line 54 "../foreignTypes.st"
			*pe = two;
# line 55 "../foreignTypes.st"
			*pt %= 10;
# line 57 "../foreignTypes.st"
			testOk1(ps->i == 2);
# line 58 "../foreignTypes.st"
			testOk1(ps->s.d == 0.1 / 3.0);
# line 59 "../foreignTypes.st"
			testOk1(pu->i == 12);
# line 60 "../foreignTypes.st"
			pu->p = ps;
# line 61 "../foreignTypes.st"
			testOk1(pu->p == ps);
# line 62 "../foreignTypes.st"
			testOk1(pu->p->i == 2);
# line 63 "../foreignTypes.st"
			testOk1(pu->p->s.d == 0.1 / 3.0);
# line 64 "../foreignTypes.st"
			testOk1(*pe == two);
# line 65 "../foreignTypes.st"
			testOk1(*pt == 2);
		}
		return;
	}
}

/* Program exit func */
static void seqg_exit(SS_ID seqg_env)
{
# line 71 "../foreignTypes.st"
	seq_test_done();
}

#undef seqg_var

/************************ Tables ************************/

/* No channel definitions */
#define seqg_chans 0

/* Event masks for state set "simple" */
static const seqMask seqg_mask_simple_0_simple[] = {
	0x00000000,
};

/* State table for state set "simple" */
static seqState seqg_states_simple[] = {
	{
	/* state name */        "simple",
	/* action function */   seqg_action_simple_0_simple,
	/* event function */    seqg_event_simple_0_simple,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_simple_0_simple,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "simple",
	/* states */            seqg_states_simple,
	/* number of states */  1
	},
};

/* Program table (global) */
seqProgram foreignTypesTest = {
	/* magic number */      2002006,
	/* program name */      "foreignTypesTest",
	/* channels */          seqg_chans,
	/* num. channels */     0,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        seqg_entry,
	/* exit func */         seqg_exit,
	/* num. queues */       0
};

#define PROG_NAME foreignTypesTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void foreignTypesTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&foreignTypesTest);
}
epicsExportRegistrar(foreignTypesTestRegistrar);
