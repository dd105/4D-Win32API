/*
	File:		Lists.h

	Copyright:	� 1984-1993 by Apple Computer, Inc., all rights reserved.

	WARNING
	This file was auto generated by the interfacer tool. Modifications
	must be made to the master file.

*/

#ifndef __LISTS__
#define __LISTS__

#ifndef __TYPES__
#include <MacTypes.H>
#endif

#ifndef __CONTROLS__
#include <Controls.H>
#endif

#ifndef __MEMORY__
#if MACVER
#include <Memory.h>
#else
#include <MemoryM.h>
#endif
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

#if MACVER
enum {

	lDoVAutoscroll		= 2,
	lDoHAutoscroll		= 1,
#if WINVER	// Altura uses the upper byte of this for other secret stuff
		//   and the whole thing is a UWORD, so make this unsigned
	lOnlyOne		  = 128,
#else
	lOnlyOne		 = -128,
#endif
	lExtendDrag		= 64,
	lNoDisjoint		= 32,
	lNoExtend		= 16,
	lNoRect			= 8,
	lUseSense		= 4,
	lNoNilHilite		= 2,
	lInitMsg		= 0,
	lDrawMsg		= 1,
	lHiliteMsg		= 2,
	lCloseMsg		= 3
};
#else
// ours uses the upper byte of this for other secret stuff and the whole
// thing is a UWORD, make this stuff unsigned too.
enum {

    lDoVAutoscroll = 2,
    lDoHAutoscroll = 1,
    lOnlyOne = 128,
    lExtendDrag = 64,
    lNoDisjoint = 32,
    lNoExtend = 16,
    lNoRect = 8,
    lUseSense = 4,
    lNoNilHilite = 2,
    lInitMsg = 0,
    lDrawMsg = 1,
    lHiliteMsg = 2,
    lCloseMsg = 3
};
#endif

typedef Point Cell;

typedef char DataArray[32001], *DataPtr, **DataHandle;

typedef short (pascal *ListSearchProcPtr)(Ptr aPtr, Ptr bPtr, short aLen, short bLen);

enum {
	uppListSearchProcInfo = kPascalStackBased
		| RESULT_SIZE(SIZE_CODE(sizeof(short)))
		| STACK_ROUTINE_PARAMETER(1, SIZE_CODE(sizeof(Ptr)))
		| STACK_ROUTINE_PARAMETER(2, SIZE_CODE(sizeof(Ptr)))
		| STACK_ROUTINE_PARAMETER(3, SIZE_CODE(sizeof(short)))
		| STACK_ROUTINE_PARAMETER(4, SIZE_CODE(sizeof(short)))
};

#if USESROUTINEDESCRIPTORS
typedef UniversalProcPtr ListSearchUPP;

#define CallListSearchProc(userRoutine, aPtr, bPtr, aLen, bLen)		\
		CallUniversalProc((UniversalProcPtr)(userRoutine), uppListSearchProcInfo, (aPtr), (bPtr), (aLen), (bLen))
#define NewListSearchProc(userRoutine)		\
		(ListSearchUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppListSearchProcInfo, GetCurrentISA())
#else
typedef ListSearchProcPtr ListSearchUPP;

#define CallListSearchProc(userRoutine, aPtr, bPtr, aLen, bLen)		\
		(*(userRoutine))((aPtr), (bPtr), (aLen), (bLen))
#define NewListSearchProc(userRoutine)		\
		(ListSearchUPP)(userRoutine)
#endif

typedef Boolean (*ListClickLoopProcPtr)(void);

enum {
	uppListClickLoopProcInfo = kCStackBased
		| RESULT_SIZE(SIZE_CODE(sizeof(Boolean)))
};

#if USESROUTINEDESCRIPTORS
typedef UniversalProcPtr ListClickLoopUPP;

#define CallListClickLoopProc(userRoutine)		\
		CallUniversalProc((UniversalProcPtr)(userRoutine), uppListClickLoopProcInfo)
#define NewListClickLoopProc(userRoutine)		\
		(ListClickLoopUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppListClickLoopProcInfo, GetCurrentISA())
#else
typedef ListClickLoopProcPtr ListClickLoopUPP;

#define CallListClickLoopProc(userRoutine)		\
		(*(userRoutine))()
#define NewListClickLoopProc(userRoutine)		\
		(ListClickLoopUPP)(userRoutine)
#endif

struct ListRec {
	Rect			rView;
	GrafPtr			port;
	Point			indent;
	Point			cellSize;
	Rect			visible;
	ControlHandle			vScroll;
	ControlHandle			hScroll;
	char			selFlags;
	Boolean			lActive;
	char			lReserved;
	char			listFlags;
	long			clikTime;
	Point			clikLoc;
	Point			mouseLoc;
	ListClickLoopUPP			lClickLoop;
	Cell			lastClick;
	long			refCon;
	Handle			listDefProc;
	Handle			userHandle;
	Rect			dataBounds;
	DataHandle			cells;
	short			maxIndex;
	short			cellArray[1];
};
typedef struct ListRec ListRec;

typedef ListRec *ListPtr, **ListHandle;

typedef void (pascal *ListDefProcPtr)(short lMessage, Boolean lSelect, Rect *lRect, Cell lCell, short lDataOffset, short lDataLen, ListHandle lHandle);

#define	uppListDefProcInfo	\
		( kPascalStackBased \
		| STACK_ROUTINE_PARAMETER(1, SIZE_CODE(sizeof(short))) \
		| STACK_ROUTINE_PARAMETER(2, SIZE_CODE(sizeof(Boolean))) \
		| STACK_ROUTINE_PARAMETER(3, SIZE_CODE(sizeof(Rect*))) \
		| STACK_ROUTINE_PARAMETER(4, SIZE_CODE(sizeof(Cell))) \
		| STACK_ROUTINE_PARAMETER(5, SIZE_CODE(sizeof(short))) \
		| STACK_ROUTINE_PARAMETER(6, SIZE_CODE(sizeof(short))) \
		| STACK_ROUTINE_PARAMETER(7, SIZE_CODE(sizeof(ListHandle))) )

#if USESROUTINEDESCRIPTORS
typedef UniversalProcPtr ListDefUPP;

#define CallListDefProc(userRoutine, lMessage, lSelect, lRect, lCell, lDataOffset, lDataLen, lHandle)		\
		CallUniversalProc((UniversalProcPtr)(userRoutine), uppListDefProcInfo, \
		(lMessage), (lSelect), (lRect), (lCell), (lDataOffset), (lDataLen), (lHandle))
#define NewListDefProc(userRoutine)		\
		(ListDefUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppListDefProcInfo, GetCurrentISA())
#else
typedef ListDefProcPtr ListDefUPP;

#define CallListDefProc(userRoutine, lMessage, lSelect, lRect, lCell, lDataOffset, lDataLen, lHandle)		\
		(*(userRoutine))((lMessage), (lSelect), (lRect), (lCell), (lDataOffset), (lDataLen), (lHandle))
#define NewListDefProc(userRoutine)		\
		(ListDefUPP)(userRoutine)
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern ListHandle lnew(Rect *rView, Rect *dataBounds, Point *cSize, short theProc, \
	WindowPtr theWindow, Boolean drawIt, Boolean hasGrow, Boolean scrollHoriz, Boolean scrollVert);
extern ListHandle pascal LNew(const Rect *rView, const Rect *dataBounds, Point cSize, \
	short theProc, WindowPtr theWindow, Boolean drawIt, Boolean hasGrow, Boolean scrollHoriz, Boolean scrollVert);
extern void pascal LDispose(ListHandle lHandle);
extern short pascal LAddColumn(short count, short colNum, ListHandle lHandle);
extern short pascal LAddRow(short count, short rowNum, ListHandle lHandle);
extern void pascal LDelColumn(short count, short colNum, ListHandle lHandle);
extern void pascal LDelRow(short count, short rowNum, ListHandle lHandle);
extern Boolean pascal LGetSelect(Boolean next, Cell *theCell, ListHandle lHandle);
	// Add LongLastClick with long return value (instead of Cell) to
	//    avoid compiler dependencies on how structures are returned
#ifdef __BORLANDC__
F_PASCAL( long ) LongLastClick(ListHandle lHandle); 
#define LLastClick(l) LongLastClick(l)
#else
F_PASCAL( long ) LongLastClick(ListHandle lHandle); 
F_PASCAL( Cell ) LLastClick(ListHandle lHandle); 
#endif
extern Boolean pascal LNextCell(Boolean hNext, Boolean vNext, Cell *theCell, ListHandle lHandle);
extern Boolean pascal LSearch(const void *dataPtr, short dataLen, ListSearchUPP searchProc, Cell *theCell, ListHandle lHandle);
extern void pascal LSize(short listWidth, short listHeight, ListHandle lHandle);
extern void pascal LSetDrawingMode(Boolean drawIt, ListHandle lHandle);
extern void pascal LScroll(short dCols, short dRows, ListHandle lHandle);
extern void pascal LAutoScroll(ListHandle lHandle);
extern void pascal LUpdate(RgnHandle theRgn, ListHandle lHandle);
extern void pascal LActivate(Boolean act, ListHandle lHandle);
extern void pascal LCellSize(Point cSize, ListHandle lHandle);
extern Boolean pascal LClick(Point pt, short modifiers, ListHandle lHandle);
extern void pascal LAddToCell(const void *dataPtr, short dataLen, Cell theCell, ListHandle lHandle);
extern void pascal LClrCell(Cell theCell, ListHandle lHandle);
extern void pascal LGetCell(void *dataPtr, short *dataLen, Cell theCell, ListHandle lHandle);
extern void pascal LGetCellDataLocation(short *offset, short *len, Cell theCell, ListHandle lHandle);
extern void pascal LRect(Rect *cellRect, Cell theCell, ListHandle lHandle);
extern void pascal LSetCell(const void *dataPtr, short dataLen, Cell theCell, ListHandle lHandle);
extern void pascal LSetSelect(Boolean setIt, Cell theCell, ListHandle lHandle);
extern void pascal LDraw(Cell theCell, ListHandle lHandle);
extern void laddtocell(Ptr dataPtr, short dataLen, Cell *theCell, ListHandle lHandle);
extern void lclrcell(Cell *theCell, ListHandle lHandle);
extern void lgetcelldatalocation(short *offset, short *len, Cell *theCell, ListHandle lHandle);
extern void lgetcell(Ptr dataPtr, short *dataLen, Cell *theCell, ListHandle lHandle);
extern ListHandle lnew(Rect *rView, Rect *dataBounds, Point *cSize, short theProc, \
	WindowPtr theWindow, Boolean drawIt, Boolean HasGrow, Boolean ScrollHoriz, Boolean ScrollVert);
extern void lrect(Rect *cellRect, Cell *theCell, ListHandle lHandle);
extern void lsetcell(Ptr dataPtr, short dataLen, Cell *theCell, ListHandle lHandle);
extern void lsetselect(Boolean setIt, Cell *theCell, ListHandle lHandle);
extern void ldraw(Cell *theCell, ListHandle lHandle);
extern Boolean lclick(Point *pt, short modifiers, ListHandle lHandle);
extern void lcellsize(Point *cSize, ListHandle lHandle);
#if OLDROUTINENAMES
#define LDoDraw(drawIt, lHandle) LSetDrawingMode(drawIt, lHandle)

#define LFind(offset, len, theCell, lHandle)  \
	LGetCellDataLocation(offset, len, theCell, lHandle)


/* loic
#define lfind(offset, len, theCell, lHandle)  \
	lgetcelldatalocation(offset, len, theCell, lHandle)
*/

#endif

#ifdef __cplusplus
}
#endif

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

#endif
