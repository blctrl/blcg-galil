/* C code for program exOpt_DuplOptTest, generated by snc from ../exOpt_DuplOpt.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"

/* Variable declarations */
# line 6 "../exOpt_DuplOpt.st"
static	float v;


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
}

/****** Code for state "low" in state set "ss1" ******/

/* Entry function for state "low" in state set "ss1" */
static void seqg_entry_ss1_0_low(SS_ID seqg_env)
{
# line 14 "../exOpt_DuplOpt.st"
	printf("Will do this on entry");
# line 15 "../exOpt_DuplOpt.st"
	printf("Another thing to do on entry");
}

/* Exit function for state "low" in state set "ss1" */
static void seqg_exit_ss1_0_low(SS_ID seqg_env)
{
# line 23 "../exOpt_DuplOpt.st"
	printf("Something to do on exit");
}

/* Event function for state "low" in state set "ss1" */
static seqBool seqg_event_ss1_0_low(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 17 "../exOpt_DuplOpt.st"
	if (v > 5.0)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 20 "../exOpt_DuplOpt.st"
	if (seq_delay(seqg_env, .1))
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "low" in state set "ss1" */
static void seqg_action_ss1_0_low(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 18 "../exOpt_DuplOpt.st"
			printf("now changing to high\n");
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "high" in state set "ss1" ******/

/* Event function for state "high" in state set "ss1" */
static seqBool seqg_event_ss1_0_high(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 28 "../exOpt_DuplOpt.st"
	if (v <= 5.0)
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 31 "../exOpt_DuplOpt.st"
	if (seq_delay(seqg_env, .1))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "high" in state set "ss1" */
static void seqg_action_ss1_0_high(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 29 "../exOpt_DuplOpt.st"
			printf("changing to low\n");
		}
		return;
	case 1:
		{
		}
		return;
	}
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"grw:xxxExample", (size_t)&v, "v", P_FLOAT, 1, 1, 0, 1, 0, 0},
};

/* Event masks for state set "ss1" */
static const seqMask seqg_mask_ss1_0_low[] = {
	0x00000002,
};
static const seqMask seqg_mask_ss1_0_high[] = {
	0x00000002,
};

/* State table for state set "ss1" */
static seqState seqg_states_ss1[] = {
	{
	/* state name */        "low",
	/* action function */   seqg_action_ss1_0_low,
	/* event function */    seqg_event_ss1_0_low,
	/* entry function */    seqg_entry_ss1_0_low,
	/* exit function */     seqg_exit_ss1_0_low,
	/* event mask array */  seqg_mask_ss1_0_low,
	/* state options */     (0)
	},
	{
	/* state name */        "high",
	/* action function */   seqg_action_ss1_0_high,
	/* event function */    seqg_event_ss1_0_high,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_ss1_0_high,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "ss1",
	/* states */            seqg_states_ss1,
	/* number of states */  2
	},
};

/* Program table (global) */
seqProgram exOpt_DuplOptTest = {
	/* magic number */      2002006,
	/* program name */      "exOpt_DuplOptTest",
	/* channels */          seqg_chans,
	/* num. channels */     1,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        0,
	/* exit func */         0,
	/* num. queues */       0
};

#define PROG_NAME exOpt_DuplOptTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void exOpt_DuplOptTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&exOpt_DuplOptTest);
}
epicsExportRegistrar(exOpt_DuplOptTestRegistrar);
