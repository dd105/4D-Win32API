/*
	File:		TextEdit.h

	Copyright:	� 1984-1993 by Apple Computer, Inc., all rights reserved.

	WARNING
	This file was auto generated by the interfacer tool. Modifications
	must be made to the master file.

*/

#ifndef __TEXTEDIT__
#define __TEXTEDIT__

#ifndef __QUICKDRAW__
#if LONG_FILENAMES
#include <Quickdraw.H>
#else
#include <Quickdra.H>
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

typedef struct TERec TERec, *TEPtr, **TEHandle;


/*
	The following ProcPtrs cannot be written in or called from a high-level
	language without the help of mixed mode or assembly glue because they
	use the following parameter-passing conventions:

	typedef pascal void (*HighHookProcPtr)(const Rect *r, TEPtr pTE);
	typedef pascal void (*CaretHookProcPtr)(const Rect *r, TEPtr pTE);

		In:
			=>	r			on stack
			=>	pTE			A3.L
		Out:
			none

	typedef pascal Boolean (*EOLHookProcPtr)(char theChar, TEPtr pTE, TEHandle hTE);

		In:
			=>	theChar			D0.B
			=>	pTE			A3.L
			=>	hTE			A4.L
		Out:
			<=	Boolean			Z bit of the CCR

	typedef pascal unsigned short (*WidthHookProcPtr)(unsigned short textLen,
	unsigned short textOffset, char *textBufferPtr, TEPtr pTE, TEHandle hTE);
	typedef pascal unsigned short (*TextWidthHookProcPtr)(unsigned short textLen,
	unsigned short textOffset, char *textBufferPtr, TEPtr pTE, TEHandle hTE);

		In:
			=>	textLen			D0.W
			=>	textOffset			D1.W
			=>	textBufferPtr			A0.L
			=>	pTE			A3.L
			=>	hTE			A4.L
		Out:
			<=	unsigned short			D1.W

	typedef pascal unsigned short (*NWidthHookProcPtr)(unsigned short styleRunLen,
	unsigned short styleRunOffset, short slop, short direction, char *textBufferPtr,
	short *lineStart, TEPtr pTE, TEHandle hTE);

		In:
			=>	styleRunLen			D0.W
			=>	styleRunOffset			D1.W
			=>	slop			D2.W (low)
			=>	direction			D2.W (high)
			=>	textBufferPtr			A0.L
			=>	lineStart			A2.L
			=>	pTE			A3.L
			=>	hTE			A4.L
		Out:
			<=	unsigned short			D1.W

	typedef pascal void (*DrawHookProcPtr)(unsigned short textOffset, unsigned short drawLen,
	char *textBufferPtr, TEPtr pTE, TEHandle hTE);

		In:
			=>	textOffset			D0.W
			=>	drawLen			D1.W
			=>	textBufferPtr			A0.L
			=>	pTE			A3.L
			=>	hTE			A4.L
		Out:
			none

	typedef pascal Boolean (*HitTestHookProcPtr)(unsigned short styleRunLen,
	unsigned short styleRunOffset, unsigned short slop, char *textBufferPtr,
	TEPtr pTE, TEHandle hTE, unsigned short *pixelWidth, unsigned short *charOffset,
	Boolean *pixelInChar);

		In:
			=>	styleRunLen			D0.W
			=>	styleRunOffset			D1.W
			=>	slop			D2.W
			=>	textBufferPtr			A0.L
			=>	pTE			A3.L
			=>	hTE			A4.L
		Out:
			<=	pixelWidth			D0.W (low)
			<=	Boolean			D0.W (high)
			<=	charOffset			D1.W
			<=	pixelInChar			D2.W

	typedef pascal void (*TEFindWordProcPtr)(unsigned short currentPos, short caller,
	TEPtr pTE, TEHandle hTE, unsigned short *wordStart, unsigned short *wordEnd);

		In:
			=>	currentPos			D0.W
			=>	caller			D2.W
			=>	pTE			A3.L
			=>	hTE			A4.L
		Out:
			<=	wordStart			D0.W
			<=	wordEnd			D1.W

	typedef pascal void (*TERecalcProcPtr)(TEPtr pTE, unsigned short changeLength,
	unsigned short *lineStart, unsigned short *firstChar, unsigned short *lastChar);

		In:
			=>	pTE			A3.L
			=>	changeLength			D7.W
		Out:
			<=	lineStart			D2.W
			<=	firstChar			D3.W
			<=	lastChar			D4.W

	typedef pascal void (*TEDoTextProcPtr)(TEPtr pTE, unsigned short firstChar, unsigned short lastChar,
	short selector, GrafPtr *currentGrafPort, short *charPosition);

		In:
			=>	pTE			A3.L
			=>	firstChar			D3.W
			=>	lastChar			D4.W
			=>	selector			D7.W
		Out:
			<=	currentGrafPort			A0.L
			<=	charPosition			D0.W

*/

enum  {
	uppHighHookProcInfo			= SPECIAL_CASE_PROCINFO(kSpecialCaseHighHook),
	uppCaretHookProcInfo		= SPECIAL_CASE_PROCINFO(kSpecialCaseCaretHook),
	uppEOLHookProcInfo			= SPECIAL_CASE_PROCINFO(kSpecialCaseEOLHook),
	uppWidthHookProcInfo		= SPECIAL_CASE_PROCINFO(kSpecialCaseWidthHook),
	uppNWidthHookProcInfo		= SPECIAL_CASE_PROCINFO(kSpecialCaseNWidthHook),
	uppTextWidthHookProcInfo	= SPECIAL_CASE_PROCINFO(kSpecialCaseTextWidthHook),
	uppDrawHookProcInfo			= SPECIAL_CASE_PROCINFO(kSpecialCaseDrawHook),
	uppHitTestHookProcInfo		= SPECIAL_CASE_PROCINFO(kSpecialCaseHitTestHook),
	uppTEFindWordProcInfo		= SPECIAL_CASE_PROCINFO(kSpecialCaseTEFindWord),
	uppTERecalcProcInfo			= SPECIAL_CASE_PROCINFO(kSpecialCaseTERecalc),
	uppTEDoTextProcInfo			= SPECIAL_CASE_PROCINFO(kSpecialCaseTEDoText)
};

#if USESROUTINEDESCRIPTORS
typedef void (pascal *HighHookProcPtr)(const Rect *r, TEPtr pTE);

typedef UniversalProcPtr HighHookUPP;

#define CallHighHookProc(userRoutine, r, pTE)  \
	CallUniversalProc((UniversalProcPtr)(userRoutine), uppHighHookProcInfo, (r), (pTE))

#define NewHighHookProc(userRoutine)  \
	(HighHookUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppHighHookProcInfo, GetCurrentISA())

typedef void (pascal *CaretHookProcPtr)(const Rect *r, TEPtr pTE);

typedef UniversalProcPtr CaretHookUPP;

#define CallCaretHookProc(userRoutine, r, pTE)  \
	CallUniversalProc((UniversalProcPtr)(userRoutine), uppCaretHookProcInfo, (r), (pTE))

#define NewCaretHookProc(userRoutine)  \
	(CaretHookUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppCaretHookProcInfo, GetCurrentISA())

typedef Boolean (pascal *EOLHookProcPtr)(char theChar, TEPtr pTE, TEHandle hTE);

typedef UniversalProcPtr EOLHookUPP;

#define CallEOLHookProc(userRoutine, theChar, pTE, hTE)  \
	CallUniversalProc((UniversalProcPtr)(userRoutine), (uppEOLHookProcInfo), (theChar), (pTE), (hTE))

#define NewEOLHookProc(userRoutine)  \
	(EOLHookUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppEOLHookProcInfo, GetCurrentISA())

typedef unsigned short (pascal *WidthHookProcPtr)(unsigned short textLen, unsigned short textOffset, char *textBufferPtr, TEPtr pTE, TEHandle hTE);

typedef UniversalProcPtr WidthHookUPP;

#define CallWidthHookProc(userRoutine, textLen, textOffset, textBufferPtr, pTE, hTE)  \
	CallUniversalProc((UniversalProcPtr)(userRoutine), (uppWidthHookProcInfo), (textLen),  \
	(textOffset), (textBufferPtr), (pTE), (hTE))

#define NewWidthHookProc(userRoutine)  \
	(WidthHookUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppWidthHookProcInfo, GetCurrentISA())

typedef unsigned short (pascal *NWidthHookProcPtr)(unsigned short styleRunLen, unsigned short styleRunOffset, short slop, short direction, char *textBufferPtr, short *lineStart, TEPtr pTE, TEHandle hTE);

typedef UniversalProcPtr NWidthHookUPP;

#define CallNWidthHookProc(userRoutine, styleRunLen, styleRunOffset, slop, direction, textBufferPtr, lineStart, pTE, hTE)  \
	CallUniversalProc((UniversalProcPtr)(userRoutine), (uppNWidthHookProcInfo), (styleRunLen),  \
	(styleRunOffset), (slop), (direction), (textBufferPtr), (lineStart), (pTE), (hTE))

#define NewNWidthHookProc(userRoutine)  \
	(NWidthHookUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppNWidthHookProcInfo, GetCurrentISA())

typedef unsigned short (pascal *TextWidthHookProcPtr)(unsigned short textLen, unsigned short textOffset, char *textBufferPtr, TEPtr pTE, TEHandle hTE);

typedef UniversalProcPtr TextWidthHookUPP;

#define CallTextWidthHookProc(userRoutine, textLen, textOffset, textBufferPtr, pTE, hTE)  \
	CallUniversalProc((UniversalProcPtr)(userRoutine), (uppTextWidthHookProcInfo), (textLen),  \
	(textOffset), (textBufferPtr), (pTE), (hTE))

#define NewTextWidthHookProc(userRoutine)  \
	(TextWidthHookUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppTextWidthHookProcInfo, GetCurrentISA())

typedef void (pascal *DrawHookProcPtr)(unsigned short textOffset, unsigned short drawLen, char *textBufferPtr, TEPtr pTE, TEHandle hTE);

typedef UniversalProcPtr DrawHookUPP;

#define CallDrawHookProc(userRoutine, textOffset, drawLen, textBufferPtr, pTE, hTE)  \
	CallUniversalProc((UniversalProcPtr)(userRoutine), (uppDrawHookProcInfo), (textOffset),  \
	(drawLen), (textBufferPtr), (pTE), (hTE))

#define NewDrawHookProc(userRoutine)  \
	(DrawHookUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppDrawHookProcInfo, GetCurrentISA())

typedef Boolean (pascal *HitTestHookProcPtr)(unsigned short styleRunLen, unsigned short styleRunOffset, unsigned short slop, char *textBufferPtr, TEPtr pTE, TEHandle hTE, unsigned short *pixelWidth, unsigned short *charOffset, Boolean *pixelInChar);

typedef UniversalProcPtr HitTestHookUPP;

#define CallHitTestHookProc(userRoutine, styleRunLen, styleRunOffset, slop, textBufferPtr, pTE, hTE, pixelWidth, charOffset, pixelInChar)  \
	CallUniversalProc((UniversalProcPtr)(userRoutine), uppHitTestHookProcInfo, (styleRunLen),  \
	(styleRunOffset), (slop), (textBufferPtr), (pTE), (hTE), (pixelWidth),  \
	(charOffset), (pixelInChar))

#define NewHitTestHookProc(userRoutine)  \
	(HitTestHookUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppHitTestHookProcInfo, GetCurrentISA())

typedef void (pascal *TEFindWordProcPtr)(unsigned short currentPos, short caller, TEPtr pTE, TEHandle hTE, unsigned short *wordStart, unsigned short *wordEnd);

typedef UniversalProcPtr TEFindWordUPP;

#define CallTEFindWordProc(userRoutine, currentPos, caller, pTE, hTE, wordStart, wordEnd)  \
	CallUniversalProc((UniversalProcPtr)(userRoutine), uppTEFindWordProcInfo, (currentPos),  \
	(caller), (pTE), (hTE), (wordStart), (wordEnd))

#define NewTEFindWordProc(userRoutine)  \
	(TEFindWordUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppTEFindWordProcInfo, GetCurrentISA())

typedef void (pascal *TERecalcProcPtr)(TEPtr pTE, unsigned short changeLength, unsigned short *lineStart, unsigned short *firstChar, unsigned short *lastChar);

typedef UniversalProcPtr TERecalcUPP;

#define CallTERecalcProc(userRoutine, pTE, changeLength, lineStart, firstChar, lastChar)  \
	CallUniversalProc((UniversalProcPtr) (userRoutine), uppTERecalcProcInfo, (pTE),	\
	(changeLength), (lineStart), (firstChar), (lastChar))

#define NewTERecalcProc(userRoutine)  \
	(TERecalcUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppTERecalcProcInfo, GetCurrentISA())

typedef void (pascal *TEDoTextProcPtr)(TEPtr pTE, unsigned short firstChar, unsigned short lastChar, short selector, GrafPtr *currentGrafPort, short *charPosition);

typedef UniversalProcPtr TEDoTextUPP;

#define CallTEDoTextProc(userRoutine, pTE, firstChar, lastChar, selector, currentGrafPort, charPosition)  \
	CallUniversalProc((UniversalProcPtr) (userRoutine), uppTEDoTextProcInfo, (pTE),	\
	(firstChar), (lastChar), (selector), (currentGrafPort), (charPosition))

#define NewTEDoTextProc(userRoutine)  \
	(TEDoTextUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppTEDoTextProcInfo, GetCurrentISA())

#else
typedef ProcPtr HighHookUPP;

#define NewHighHookProc(userRoutine)  \
	(HighHookUPP)(userRoutine)

typedef ProcPtr CaretHookUPP;

#define NewCaretHookProc(userRoutine)  \
	(CaretHookUPP)(userRoutine)

typedef ProcPtr EOLHookUPP;

#define NewEOLHookProc(userRoutine)  \
	(EOLHookUPP)(userRoutine)

typedef ProcPtr WidthHookUPP;

#define NewWidthHookProc(userRoutine)  \
	(WidthHookUPP)(userRoutine)

typedef ProcPtr NWidthHookUPP;

#define NewNWidthHookProc(userRoutine)  \
	(NWidthHookUPP)(userRoutine)

typedef ProcPtr TextWidthHookUPP;

#define NewTextWidthHookProc(userRoutine)  \
	(TextWidthHookUPP)(userRoutine)

typedef ProcPtr DrawHookUPP;

#define NewDrawHookProc(userRoutine)  \
	(DrawHookUPP)(userRoutine)

typedef ProcPtr HitTestHookUPP;

#define NewHitTestHookProc(userRoutine)  \
	(HitTestHookUPP)(userRoutine)

typedef ProcPtr TEFindWordUPP;

#define NewTEFindWordProc(userRoutine)  \
	(TEFindWordUPP)(userRoutine)

typedef ProcPtr TERecalcUPP;

#define NewTERecalcProc(userRoutine)  \
	(TERecalcUPP)(userRoutine)

typedef ProcPtr TEDoTextUPP;

#define NewTEDoTextProc(userRoutine)  \
	(TEDoTextUPP)(userRoutine)

#endif

enum  {
/* Justification (word alignment) styles */
	teJustLeft			= 0,
	teJustCenter			= 1,
	teJustRight			= -1,
	teForceLeft			= -2,
/* new names for the Justification (word alignment) styles */
	teFlushDefault			= 0,			/*flush according to the line direction */
	teCenter			= 1,			/*center justify (word alignment) */
	teFlushRight			= -1,			/*flush right for all scripts */
	teFlushLeft			= -2,			/*flush left for all scripts */
/* Set/Replace style modes */
	fontBit			= 0,			/*set font*/
	faceBit			= 1,			/*set face*/
	sizeBit			= 2,			/*set size*/
	clrBit			= 3,			/*set color*/
	addSizeBit			= 4,			/*add size mode*/
	toggleBit			= 5,			/*set faces in toggle mode*/
	toglBit			= 5,			/* obsolete.  use toggleBit */
/* TESetStyle/TEContinuousStyle modes */
	doFont			= 1,			/* set font (family) number*/
	doFace			= 2,			/*set character style*/
	doSize			= 4,			/*set type size*/
	doColor			= 8,			/*set color*/
	doAll			= 15,			/*set all attributes*/
	addSize			= 16			/*adjust type size*/
};

enum  {
	doToggle			= 32,			/*toggle mode for TESetStyle*/
/* offsets into TEDispatchRec */
	EOLHook			= 0,			/*[UniversalProcPtr] TEEOLHook*/
	DRAWHook			= 4,			/*[UniversalProcPtr] TEWidthHook*/
	WIDTHHook			= 8,			/*[UniversalProcPtr] TEDrawHook*/
	HITTESTHook			= 12,			/*[UniversalProcPtr] TEHitTestHook*/
	nWIDTHHook			= 24,			/*[UniversalProcPtr] nTEWidthHook*/
	TextWidthHook			= 28,			/*[UniversalProcPtr] TETextWidthHook*/
/* selectors for TECustomHook */
	intEOLHook			= 0,			/*TEIntHook value*/
	intDrawHook			= 1,			/*TEIntHook value*/
	intWidthHook			= 2,			/*TEIntHook value*/
	intHitTestHook			= 3,			/*TEIntHook value*/
	intNWidthHook			= 6,			/*TEIntHook value for new version of WidthHook*/
	intTextWidthHook			= 7,			/*TEIntHook value for new TextWidthHook*/
/* feature or bit definitions for TEFeatureFlag */
	teFAutoScroll			= 0,			/*00000001b*/
	teFAutoScr			= 0,			/*00000001b  obsolete. use teFAutoScroll*/
	teFTextBuffering			= 1,			/*00000010b*/
	teFOutlineHilite			= 2,			/*00000100b*/
	teFInlineInput			= 3,			/*00001000b */
	teFUseTextServices			= 4,			/*00010000b */
/* action for the new "bit (un)set" interface, TEFeatureFlag */
	TEBitClear			= 0,
	TEBitSet			= 1			/*set the selector bit*/
};

enum  {
	TEBitTest			= -1,			/*no change; just return the current setting*/
	teBitClear			= 0,
	teBitSet			= 1,			/*set the selector bit*/
	teBitTest			= -1,			/*no change; just return the current setting*/
/*constants for identifying the routine that called FindWord */
	teWordSelect			= 4,			/*clickExpand to select word*/
	teWordDrag			= 8,			/*clickExpand to drag new word*/
	teFromFind			= 12,			/*FindLine called it ($0C)*/
	teFromRecal			= 16,			/*RecalLines called it ($10)	obsolete */
/*constants for identifying TEDoText selectors */
	teFind			= 0,			/*TEDoText called for searching*/
	teHighlight			= 1,			/*TEDoText called for highlighting*/
	teDraw			= -1,			/*TEDoText called for drawing text*/
	teCaret			= -2			/*TEDoText called for drawing the caret*/
};


/*
	WordBreakProcs and TEClickLoopProcs cannot be written in or called from a
	high-level language without the help of mixed mode or assembly glue
	because they use the following parameter-passing conventions:

	typedef pascal Boolean (*WordBreakProcPtr)(Ptr text, short charPos);

		In:
			=>	text			A0.L
			=>	charPos			D0.W
		Out:
			<=	Boolean			Z bit of the CCR

	typedef pascal Boolean (*TEClickLoopProcPtr)(TEPtr pTE);

		In:
			=>	pTE			A3.L
		Out:
			<=	Boolean			D0.B
*/

#define	uppWordBreakProcInfo	(kRegisterBased|REGISTER_RESULT_LOCATION(kCCRegisterZBit)|REGISTER_ROUTINE_PARAMETER(1,kRegisterA0,kFourByteCode)|REGISTER_ROUTINE_PARAMETER(2,kRegisterD0,kTwoByteCode))
#define	uppTEClickLoopProcInfo	(kRegisterBased|RESULT_SIZE(kOneByteCode)|REGISTER_RESULT_LOCATION(kRegisterD0)|REGISTER_ROUTINE_PARAMETER(1,kRegisterA3,kFourByteCode))

#if USESROUTINEDESCRIPTORS
typedef Boolean (pascal *WordBreakProcPtr)(Ptr text, short charPos);

typedef UniversalProcPtr WordBreakUPP;

#define CallWordBreakProc(userRoutine, text, charPos)  \
	CallUniversalProc((UniversalProcPtr)(userRoutine), uppWordBreakProcInfo, (text), (charPos))

#define NewWordBreakProc(userRoutine)  \
	(WordBreakUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppWordBreakProcInfo, GetCurrentISA())

typedef Boolean (pascal *TEClickLoopProcPtr)(TEPtr pTE);

typedef UniversalProcPtr TEClickLoopUPP;

#define CallTEClickLoopProc(userRoutine, pTE)  \
	CallUniversalProc((UniversalProcPtr)(userRoutine), uppTEClickLoopProcInfo, (pTE))

#define NewTEClickLoopProc(userRoutine)  \
	(TEClickLoopUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppTEClickLoopProcInfo, GetCurrentISA())

#else
#if WINVER
typedef Boolean (pascal * WordBreakUPP)(Ptr text, short charPos);
#else
typedef ProcPtr WordBreakUPP;
#endif

#define NewWordBreakProc(userRoutine)  \
	(WordBreakUPP)(userRoutine)

#if WINVER
// --- FM 12/01/2001 to be compliant with Mac API
// typedef Boolean (pascal * TEClickLoopUPP)(void);
typedef Boolean (pascal * TEClickLoopUPP)(TEPtr pTE);
// ----

#else
typedef ProcPtr TEClickLoopUPP;
#endif

#define NewTEClickLoopProc(userRoutine)  \
	(TEClickLoopUPP)(userRoutine)

#endif

#pragma PRAGMA_PACK_1

struct TERec {
	Rect			destRect;
	Rect			viewRect;
	Rect			selRect;
	short			lineHeight;
	short			fontAscent;
	Point			selPoint;
	short			selStart;
	short			selEnd;
	short			active;
	WordBreakUPP			wordBreak;
	TEClickLoopUPP			clickLoop;
	long			clickTime;
	short			clickLoc;
	long			caretTime;
	short			caretState;
	short			just;
	short			teLength;
	Handle			hText;
/* short recalBack;		*/
/* short recalLines;	*/
	long			hDispatchRec;			/* added to replace recalBack & recalLines.  it's a handle anyway */
	short			clikStuff;
	short			crOnly;
	short			txFont;
	Style			txFace;			/*txFace is unpacked byte*/
	char			filler;
	short			txMode;
	short			txSize;
	GrafPtr			inPort;
	HighHookUPP			highHook;
	CaretHookUPP			caretHook;
	short			nLines;
	short			lineStarts[16001];
};
typedef char Chars[32001];

typedef char *CharsPtr, **CharsHandle;

struct StyleRun {
	short			startChar;			/*starting character position*/
	short			styleIndex;			/*index in style table*/
};
typedef struct StyleRun StyleRun;

struct STElement {
	short			stCount;			/*number of runs in this style*/
	short			stHeight;			/*line height*/
	short			stAscent;			/*font ascent*/
	short			stFont;			/*font (family) number*/
	Style			stFace;			/*character Style*/
	char			filler;			/*stFace is unpacked byte*/
	short			stSize;			/*size in points*/
	RGBColor			stColor;			/*absolute (RGB) color*/
};
typedef struct STElement STElement;

typedef STElement TEStyleTable[1777], *STPtr, **STHandle;

struct LHElement {
	short			lhHeight;			/*maximum height in line*/
	short			lhAscent;			/*maximum ascent in line*/
};
typedef struct LHElement LHElement;


/* ARRAY [0..8000] OF LHElement */

typedef LHElement LHTable[8001], *LHPtr, **LHHandle;

struct ScrpSTElement {
	long			scrpStartChar;			/*starting character position*/
	short			scrpHeight;			/*starting character position*/
	short			scrpAscent;
	short			scrpFont;
	Style			scrpFace;			/*unpacked byte*/
	char			filler;			/*scrpFace is unpacked byte*/
	short			scrpSize;
	RGBColor			scrpColor;
};
typedef struct ScrpSTElement ScrpSTElement;


/* ARRAY [0..1600] OF ScrpSTElement */

typedef ScrpSTElement ScrpSTTable[1601];

struct StScrpRec {
	short			scrpNStyles;			/*number of styles in scrap*/
	ScrpSTTable			scrpStyleTab;			/*table of styles for scrap*/
};
typedef struct StScrpRec StScrpRec;

typedef StScrpRec *StScrpPtr, **StScrpHandle;

struct NullStRec {
	long			teReserved;			/*reserved for future expansion*/
	StScrpHandle			nullScrap;			/*handle to scrap style table*/
};
typedef struct NullStRec NullStRec;

typedef NullStRec *NullStPtr, **NullStHandle;

struct TEStyleRec {
	short			nRuns;			/*number of style runs*/
	short			nStyles;			/*size of style table*/
	STHandle			styleTab;			/*handle to style table*/
	LHHandle			lhTab;			/*handle to line-height table*/
	long			teRefCon;			/*reserved for application use*/
	NullStHandle			nullStyle;			/*Handle to style set at null selection*/
	StyleRun			runs[8001];			/*ARRAY [0..8000] OF StyleRun*/
};
typedef struct TEStyleRec TEStyleRec;

typedef TEStyleRec *TEStylePtr, **TEStyleHandle;

struct TextStyle {
	short			tsFont;			/*font (family) number*/
	Style			tsFace;			/*character Style*/
	char			filler;			/*tsFace is unpacked byte*/
	short			tsSize;			/*size in point*/
	RGBColor			tsColor;			/*absolute (RGB) color*/
};
typedef struct TextStyle TextStyle;

typedef TextStyle *TextStylePtr, **TextStyleHandle;

typedef short TEIntHook;

#pragma PRAGMA_PACK_RESET

#ifdef __cplusplus
extern "C" {
#endif

#if USESCODEFRAGMENTS
extern F_PASCAL(Handle) TEScrapHandle(void);
extern F_PASCAL(long) TEGetScrapLength(void);
#else
#endif

extern F_PASCAL(void) TEInit(void);
extern F_PASCAL(TEHandle) TENew(const Rect *destRect, const Rect *viewRect);
extern F_PASCAL(void) TEDispose(TEHandle hTE);
extern F_PASCAL(void) TESetText(const void *text, long length, TEHandle hTE);
extern F_PASCAL(CharsHandle) TEGetText(TEHandle hTE);
extern F_PASCAL(void) TEIdle(TEHandle hTE);
extern F_PASCAL(void) TESetSelect(long selStart, long selEnd, TEHandle hTE);
extern F_PASCAL(void) TEActivate(TEHandle hTE);
extern F_PASCAL(void) TEDeactivate(TEHandle hTE);
extern F_PASCAL(void) TEKey(short key, TEHandle hTE);
extern F_PASCAL(void) TECut(TEHandle hTE);
extern F_PASCAL(void) TECopy(TEHandle hTE);
extern F_PASCAL(void) TEPaste(TEHandle hTE);
extern F_PASCAL(void) TEDelete(TEHandle hTE);
extern F_PASCAL(void) TEInsert(const void *text, long length, TEHandle hTE);
extern F_PASCAL(void) TESetAlignment(short just, TEHandle hTE);
extern F_PASCAL(void) TEUpdate(const Rect *rUpdate, TEHandle hTE);
extern F_PASCAL(void) TETextBox(const void *text, long length, const Rect *box, short just);
extern F_PASCAL(void) TEScroll(short dh, short dv, TEHandle hTE);
extern F_PASCAL(void) TESelView(TEHandle hTE);
extern F_PASCAL(void) TEPinScroll(short dh, short dv, TEHandle hTE);
extern F_PASCAL(void) TEAutoView(Boolean fAuto, TEHandle hTE);
extern F_PASCAL(void) TECalText(TEHandle hTE);
extern F_PASCAL(short) TEGetOffset(Point pt, TEHandle hTE);

// pp util

extern F_PASCAL( short ) ACI_TE_Next_Char(TEHandle te_h, short selection);
extern F_PASCAL( short ) ACI_TE_Prev_Char(TEHandle te_h, short selection);


#if __MWERKS__
// return long so CW compiler will look for it in the register
// metrowerks and VC++ are not compatible for functions returning structs
// so we need to use a stub to adapt VC++ to MWERKS 
extern F_PASCAL(long) TEGetPoint(short offset, TEHandle hTE);
extern F_PASCAL(Point) MWERKSTEGetPoint(short offset, TEHandle hTE);
#define TEGetPoint MWERKSTEGetPoint
#else
extern F_PASCAL(Point) TEGetPoint(short offset, TEHandle hTE);
#endif
extern F_PASCAL(void) TEClick(Point pt, Boolean fExtend, TEHandle h);
extern F_PASCAL(TEHandle) TEStyleNew(const Rect *destRect, const Rect *viewRect);
extern F_PASCAL(void) TESetStyleHandle(TEStyleHandle theHandle, TEHandle hTE);
extern TEStyleHandle pascal TEGetStyleHandle(TEHandle hTE);
extern F_PASCAL(void) TEGetStyle(short offset, TextStyle *theStyle, short *lineHeight, short *fontAscent, TEHandle hTE);
extern F_PASCAL(void) TEStylePaste(TEHandle hTE);
extern F_PASCAL(void) TESetStyle(short mode, const TextStyle *newStyle, Boolean fRedraw, TEHandle hTE);
extern F_PASCAL(void) TEReplaceStyle(short mode, const TextStyle *oldStyle, const TextStyle *newStyle, Boolean fRedraw, TEHandle hTE);
extern StScrpHandle pascal TEGetStyleScrapHandle(TEHandle hTE);
extern F_PASCAL(void) TEStyleInsert(const void *text, long length, StScrpHandle hST, TEHandle hTE);
extern F_PASCAL(long) TEGetHeight(long endLine, long startLine, TEHandle hTE);
extern F_PASCAL(Boolean) TEContinuousStyle(short *mode, TextStyle *aStyle, TEHandle hTE);
extern F_PASCAL(void) TEUseStyleScrap(long rangeStart, long rangeEnd, StScrpHandle newStyles, Boolean fRedraw, TEHandle hTE);
extern F_PASCAL(void) TECustomHook(TEIntHook which, UniversalProcPtr *addr, TEHandle hTE);
extern F_PASCAL(long) TENumStyles(long rangeStart, long rangeEnd, TEHandle hTE);
extern F_PASCAL(short) TEFeatureFlag(short feature, short action, TEHandle hTE);
extern F_PASCAL(OSErr) TEGetHiliteRgn(RgnHandle rgn, TEHandle hTE)
THREEWORDINLINE(0x3F3C, 0x000F, 0xA83D);
extern F_PASCAL(void) TESetScrapLength(long length);
extern OSErr pascal TEFromScrap(void);
extern OSErr pascal TEToScrap(void);
extern F_PASCAL(void) TESetClickLoop(TEClickLoopUPP clikProc, TEHandle hTE);
extern F_PASCAL(void) TESetWordBreak(WordBreakUPP wBrkProc, TEHandle hTE);
extern void teclick(Point *pt, Boolean fExtend, TEHandle h);
#if OLDROUTINENAMES
#define TESetJust(just, hTE) TESetAlignment(just, hTE)

#define TextBox(text, length, box, just) TETextBox(text, length, box, just)

#define TEStylNew(destRect, viewRect) TEStyleNew(destRect, viewRect)

#define SetStylHandle(theHandle, hTE) TESetStyleHandle(theHandle, hTE)

#define SetStyleHandle(theHandle, hTE) TESetStyleHandle (theHandle, hTE)

#define GetStylHandle(hTE) TEGetStyleHandle(hTE)

#define GetStyleHandle(hTE) TEGetStyleHandle(hTE)

#define TEStylPaste(hTE) TEStylePaste(hTE)

#define GetStylScrap(hTE) TEGetStyleScrapHandle(hTE)

#define GetStyleScrap(hTE) TEGetStyleScrapHandle(hTE)

#define SetStylScrap(rangeStart, rangeEnd, newStyles, redraw, hTE)  \
	TEUseStyleScrap(rangeStart, rangeEnd, newStyles, redraw, hTE)

#define SetStyleScrap(rangeStart, rangeEnd, newStyles, redraw, hTE)  \
	TEUseStyleScrap(rangeStart, rangeEnd, newStyles, redraw, hTE)

#define TEStylInsert(text, length, hST, hTE) TEStyleInsert(text, length, hST, hTE)

#define TESetScrapLen(length) TESetScrapLength(length)

//loic
#define TEGetScrapLen TEGetScrapLength

#define SetClikLoop(clikProc, hTE) TESetClickLoop(clikProc, hTE)

#define SetWordBreak(wBrkProc, hTE) TESetWordBreak(wBrkProc, hTE)

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

#ifdef __cplusplus
}
#endif

#endif


