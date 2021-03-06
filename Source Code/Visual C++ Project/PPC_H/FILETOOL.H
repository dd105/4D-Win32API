/*
	File:		FileTransferTools.h

	Copyright:	� 1984-1993 by Apple Computer, Inc., all rights reserved.

	WARNING
	This file was auto generated by the interfacer tool. Modifications
	must be made to the master file.

*/

#ifndef __FILETRANSFERTOOLS__
#define __FILETRANSFERTOOLS__

#ifdef __cplusplus
extern "C" {
#endif
#if PRAGMA_IMPORT
#pragma import on
#endif

#if PRAGMA_STRUCT_ALIGN
	#pragma options align=mac68k
#elif PRAGMA_STRUCT_PACKPUSH
	#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
	#pragma pack(2)
#endif

#ifndef __DIALOGS__
#include <Dialogs.H>
#endif

#ifndef __FILETRANSFERS__
#if LONG_FILENAMES
#include <FileTransfers.H>
#else
#include <FileTran.H>
#endif
#endif


/* DEFs */

#define fdefType OST_fdef

#define fsetType OST_fset

#define fvalType OST_fval

#define flocType OST_floc

#define fscrType OST_fscr

#define fbndType OST_fbnd

#define fverType OST_vers

enum  {
/* Control */
	ftInitMsg			= 0,
	ftDisposeMsg			= 1,
	ftSuspendMsg			= 2,
	ftResumeMsg			= 3,
	ftMenuMsg			= 4,
	ftEventMsg			= 5,
	ftActivateMsg			= 6,
	ftDeactivateMsg			= 7,
	ftGetErrorStringMsg			= 8,
	ftAbortMsg			= 52,
	ftStartMsg			= 100,
	ftExecMsg			= 102,
	ftSendMsg			= 103,
	ftReceiveMsg			= 104,
/*Setup */
	ftSpreflightMsg			= 0,
	ftSsetupMsg			= 1,
	ftSitemMsg			= 2,
	ftSfilterMsg			= 3,
	ftScleanupMsg			= 4,
/* validate */
	ftValidateMsg			= 0
};

enum  {
	ftDefaultMsg			= 1,
/* scripting */
	ftMgetMsg			= 0,
	ftMsetMsg			= 1,
/* localization */
	ftL2English			= 0,
	ftL2Intl			= 1
};

struct FTSetupStruct {
	DialogPtr			theDialog;			/* the dialog form the application */
	short			count;			/* first appended item */
	Ptr			theConfig;			/* the config record to setup */
	short			procID;			/* procID of the tool */
};
typedef struct FTSetupStruct FTSetupStruct;

typedef FTSetupStruct *FTSetupPtr;

#if PRAGMA_STRUCT_ALIGN
	#pragma options align=reset
#elif PRAGMA_STRUCT_PACKPUSH
	#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
	#pragma pack()
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif
#ifdef __cplusplus
}
#endif

#endif
