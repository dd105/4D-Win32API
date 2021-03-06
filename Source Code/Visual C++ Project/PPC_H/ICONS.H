/*
	File:		Icons.h

	Copyright:	� 1984-1993 by Apple Computer, Inc., all rights reserved.

	WARNING
	This file was auto generated by the interfacer tool. Modifications
	must be made to the master file.

*/

#ifndef __ICONS__
#define __ICONS__

#ifndef __TYPES__
#include <MacTypes.H>
#endif

#ifndef __QUICKDRAW__
#if LONG_FILENAMES
#include <Quickdraw.H>
#else
#include <Quickdra.H>
#endif
#endif

enum  {
/* The following are icons for which there are both icon suites and SICNs. */
	genericDocumentIconResource	= -4000,
	genericStationeryIconResource = -3985,
	genericEditionFileIconResource = -3989,
	genericApplicationIconResource = -3996,
	genericDeskAccessoryIconResource = -3991,
	genericFolderIconResource	= -3999,
	privateFolderIconResource	= -3994,
	floppyIconResource			= -3998,
	trashIconResource			= -3993,
/* The following are icons for which there are SICNs only. */
	desktopIconResource			= -3992,
	openFolderIconResource		= -3997,
	genericHardDiskIconResource	= -3995,
	genericFileServerIconResource = -3972,
	genericSuitcaseIconResource	= -3970,
	genericMoverObjectIconResource = -3969,
/* The following are icons for which there are icon suites only. */
	genericPreferencesIconResource = -3971,
	genericQueryDocumentIconResource = -16506,
	genericExtensionIconResource = -16415,
	systemFolderIconResource	= -3983,
	appleMenuFolderIconResource	= -3982
};

/*
#define large1BitMask OST_ICNList

#define large4BitData OST_icl4

#define large8BitData OST_icl8

#define small1BitMask OST_icsList

#define small4BitData OST_ics4

#define small8BitData OST_ics8

#define mini1BitMask OST_icmList

#define mini4BitData OST_icm4

#define mini8BitData OST_icm8
*/

enum  {
	startupFolderIconResource	= -3981,
	ownedFolderIconResource		= -3980,
	dropFolderIconResource		= -3979,
	sharedFolderIconResource	= -3978,
	mountedFolderIconResource	= -3977,
	controlPanelFolderIconResource = -3976,
	printMonitorFolderIconResource = -3975,
	preferencesFolderIconResource = -3974,
	extensionsFolderIconResource = -3973,
	fontsFolderIconResource		= -3968,
	fullTrashIconResource		= -3984
};

enum {
	kLarge1BitMask				= OST_ICNLIST,
	kLarge4BitData				= OST_icl4,
	kLarge8BitData				= OST_icl8,
	kSmall1BitMask				= OST_icsLIST,
	kSmall4BitData				= OST_ics4,
	kSmall8BitData				= OST_ics8,
	kMini1BitMask				= OST_icmLIST,
	kMini4BitData				= OST_icm4,
	kMini8BitData				= OST_icm8
};

enum {
/* Obsolete. Use names defined above. */
	large1BitMask				=  kLarge1BitMask,
	large4BitData				=  kLarge4BitData,
	large8BitData				=  kLarge8BitData,
	small1BitMask				=  kSmall1BitMask,
	small4BitData				=  kSmall4BitData,
	small8BitData				=  kSmall8BitData,
	mini1BitMask				=  kMini1BitMask,
	mini4BitData				=  kMini4BitData,
	mini8BitData				=  kMini8BitData
};

/*  alignment type values */
enum {
	kAlignNone					= 0x0,
	kAlignVerticalCenter		= 0x1,
	kAlignTop					= 0x2,
	kAlignBottom				= 0x3,
	kAlignHorizontalCenter		= 0x4,
	kAlignAbsoluteCenter		= kAlignVerticalCenter | kAlignHorizontalCenter,
	kAlignCenterTop				= kAlignTop | kAlignHorizontalCenter,
	kAlignCenterBottom			= kAlignBottom | kAlignHorizontalCenter,
	kAlignLeft					= 0x8,
	kAlignCenterLeft			= kAlignVerticalCenter | kAlignLeft,
	kAlignTopLeft				= kAlignTop | kAlignLeft,
	kAlignBottomLeft			= kAlignBottom | kAlignLeft,
	kAlignRight					= 0xC,
	kAlignCenterRight			= kAlignVerticalCenter | kAlignRight,
	kAlignTopRight				= kAlignTop | kAlignRight,
	kAlignBottomRight			= kAlignBottom | kAlignRight
};

/*  alignment type values  */

enum  {
	atNone			= 0x0,
	atVerticalCenter			= 0x1,
	atTop			= 0x2,
	atBottom			= 0x3,
	atHorizontalCenter			= 0x4,
	atAbsoluteCenter			= (atVerticalCenter|atHorizontalCenter),
	atCenterTop			= (atTop|atHorizontalCenter),
	atCenterBottom			= (atBottom|atHorizontalCenter),
	atLeft			= 0x8,
	atCenterLeft			= (atVerticalCenter|atLeft),
	atTopLeft			= (atTop|atLeft),
	atBottomLeft			= (atBottom|atLeft),
	atRight			= 0xC,
	atCenterRight			= (atVerticalCenter|atRight),
	atTopRight			= (atTop|atRight),
	atBottomRight			= (atBottom|atRight)
};

typedef short IconAlignmentType;


/*  transform type values  */

enum {
	kTransformNone				= 0x0,
	kTransformDisabled			= 0x1,
	kTransformOffline			= 0x2,
	kTransformOpen				= 0x3,
	kTransformLabel1			= 0x0100,
	kTransformLabel2			= 0x0200,
	kTransformLabel3			= 0x0300,
	kTransformLabel4			= 0x0400,
	kTransformLabel5			= 0x0500,
	kTransformLabel6			= 0x0600,
	kTransformLabel7			= 0x0700,
	kTransformSelected			= 0x4000,
	kTransformSelectedDisabled	= kTransformSelected | kTransformDisabled,
	kTransformSelectedOffline	= kTransformSelected | kTransformOffline,
	kTransformSelectedOpen		= kTransformSelected | kTransformOpen
};

enum  {
	ttNone			= 0x0,
	ttDisabled			= 0x1,
	ttOffline			= 0x2,
	ttOpen			= 0x3,
	ttLabel1			= 0x0100,
	ttLabel2			= 0x0200,
	ttLabel3			= 0x0300,
	ttLabel4			= 0x0400,
	ttLabel5			= 0x0500,
	ttLabel6			= 0x0600,
	ttLabel7			= 0x0700,
	ttSelected			= 0x4000,
	ttSelectedDisabled			= (ttSelected|ttDisabled),
	ttSelectedOffline			= (ttSelected|ttOffline),
	ttSelectedOpen			= (ttSelected|ttOpen)
};

typedef short IconTransformType;


/*  Selector mask values  */

enum {
	kSelectorLarge1Bit			= 0x00000001,
	kSelectorLarge4Bit			= 0x00000002,
	kSelectorLarge8Bit			= 0x00000004,
	kSelectorSmall1Bit			= 0x00000100,
	kSelectorSmall4Bit			= 0x00000200,
	kSelectorSmall8Bit			= 0x00000400,
	kSelectorMini1Bit			= 0x00010000,
	kSelectorMini4Bit			= 0x00020000,
	kSelectorMini8Bit			= 0x00040000,
	kSelectorAllLargeData		= 0x000000FF,
	kSelectorAllSmallData		= 0x0000FF00,
	kSelectorAllMiniData		= 0x00FF0000,
	kSelectorAll1BitData		= kSelectorLarge1Bit | kSelectorSmall1Bit | kSelectorMini1Bit,
	kSelectorAll4BitData		= kSelectorLarge4Bit | kSelectorSmall4Bit | kSelectorMini4Bit,
	kSelectorAll8BitData		= kSelectorLarge8Bit | kSelectorSmall8Bit | kSelectorMini8Bit,
	kSelectorAllAvailableData	= 0xFFFFFFFFL
};

enum  {
	svLarge1Bit			= 0x0001,
	svLarge4Bit			= 0x0002,
	svLarge8Bit			= 0x0004,
	svSmall1Bit			= 0x0100,
	svSmall4Bit			= 0x0200,
	svSmall8Bit			= 0x0400,
#define svMini1Bit	0x00010000
#define svMini4Bit	0x00020000
#define svMini8Bit	0x00040000
	svAllLargeData			= 0x00ff,
#define svAllSmallData	0xff00
#define svAllMiniData	0x00ff0000
	svAll1BitData			= (svLarge1Bit|svSmall1Bit|svMini1Bit),
	svAll4BitData			= (svLarge4Bit|svSmall4Bit|svMini4Bit),
	svAll8BitData			= (svLarge8Bit|svSmall8Bit|svMini8Bit),
	svAllAvailableData			= (long)0xffffffff
};

typedef unsigned long IconSelectorValue;

typedef F_PASCAL_PTR(OSErr, *IconActionProcPtr)(ResType theType, Handle *theIcon, void *yourDataPtr);

enum {
	uppIconActionProcInfo = kPascalStackBased
		| RESULT_SIZE(SIZE_CODE(sizeof(OSErr)))
		| STACK_ROUTINE_PARAMETER(1, SIZE_CODE(sizeof(ResType)))
		| STACK_ROUTINE_PARAMETER(2, SIZE_CODE(sizeof(Handle*)))
		| STACK_ROUTINE_PARAMETER(3, SIZE_CODE(sizeof(void*)))
};

#if USESROUTINEDESCRIPTORS
typedef UniversalProcPtr IconActionUPP;

#define CallIconActionProc(userRoutine, theType, theIcon, yourDataPtr)		\
		CallUniversalProc((UniversalProcPtr)(userRoutine), uppIconActionProcInfo, (theType), (theIcon), (yourDataPtr))
#define NewIconActionProc(userRoutine)		\
		(IconActionUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppIconActionProcInfo, GetCurrentISA())
#else
typedef IconActionProcPtr IconActionUPP;

#define CallIconActionProc(userRoutine, theType, theIcon, yourDataPtr)		\
		(*(userRoutine))((theType), (theIcon), (yourDataPtr))
#define NewIconActionProc(userRoutine)		\
		(IconActionUPP)(userRoutine)
#endif

typedef IconActionProcPtr IconAction;

typedef F_PASCAL_PTR(Handle, *IconGetterProcPtr)(ResType theType, void *yourDataPtr);

enum {
	uppIconGetterProcInfo = kPascalStackBased
		| RESULT_SIZE(SIZE_CODE(sizeof(Handle)))
		| STACK_ROUTINE_PARAMETER(1, SIZE_CODE(sizeof(ResType)))
		| STACK_ROUTINE_PARAMETER(2, SIZE_CODE(sizeof(void*)))
};

#if USESROUTINEDESCRIPTORS
typedef UniversalProcPtr IconGetterUPP;

#define CallIconGetterProc(userRoutine, theType, yourDataPtr)		\
		CallUniversalProc((UniversalProcPtr)(userRoutine), uppIconGetterProcInfo, (theType), (yourDataPtr))
#define NewIconGetterProc(userRoutine)		\
		(IconGetterUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppIconGetterProcInfo, GetCurrentISA())
#else
typedef IconGetterProcPtr IconGetterUPP;

#define CallIconGetterProc(userRoutine, theType, yourDataPtr)		\
		(*(userRoutine))((theType), (yourDataPtr))
#define NewIconGetterProc(userRoutine)		\
		(IconGetterUPP)(userRoutine)
#endif

typedef IconGetterProcPtr IconGetter;

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

extern F_PASCAL(OSErr) PlotIconID(const Rect *theRect, IconAlignmentType align, IconTransformType transform, short theResID);
extern F_PASCAL(OSErr) NewIconSuite(Handle *theIconSuite);
extern F_PASCAL(OSErr) AddIconToSuite(Handle theIconData, Handle theSuite, ResType theType);
extern F_PASCAL(OSErr) GetIconFromSuite(Handle *theIconData, Handle theSuite, ResType theType);
extern F_PASCAL(OSErr) ForEachIconDo(Handle theSuite, IconSelectorValue selector, IconActionUPP action, void *yourDataPtr);
extern F_PASCAL(OSErr) GetIconSuite(Handle *theIconSuite, short theResID, IconSelectorValue selector);
extern F_PASCAL(OSErr) DisposeIconSuite(Handle theIconSuite, Boolean disposeData);
extern F_PASCAL(OSErr) PlotIconSuite(const Rect *theRect, IconAlignmentType align, IconTransformType transform, Handle theIconSuite);
extern F_PASCAL(OSErr) MakeIconCache(Handle *theHandle, IconGetterUPP makeIcon, void *yourDataPtr);
extern F_PASCAL(OSErr) LoadIconCache(const Rect *theRect, IconAlignmentType align, IconTransformType transform, Handle theIconCache);
extern F_PASCAL(OSErr) PlotIconMethod(const Rect *theRect, IconAlignmentType align, IconTransformType transform, IconGetterUPP theMethod, void *yourDataPtr);
extern F_PASCAL(OSErr) GetLabel(short labelNumber, RGBColor *labelColor, Str255 labelString);
extern F_PASCAL(Boolean) PtInIconID(Point testPt, const Rect *iconRect, IconAlignmentType align, short iconID);
extern F_PASCAL(Boolean) PtInIconSuite(Point testPt, const Rect *iconRect, IconAlignmentType align, Handle theIconSuite);
extern F_PASCAL(Boolean) PtInIconMethod(Point testPt, const Rect *iconRect, IconAlignmentType align, IconGetterUPP theMethod, void *yourDataPtr);
extern F_PASCAL(Boolean) RectInIconID(const Rect *testRect, const Rect *iconRect, IconAlignmentType align, short iconID);
extern F_PASCAL(Boolean) RectInIconSuite(const Rect *testRect, const Rect *iconRect, IconAlignmentType align, Handle theIconSuite);
extern F_PASCAL(Boolean) RectInIconMethod(const Rect *testRect, const Rect *iconRect, IconAlignmentType align, IconGetterUPP theMethod, void *yourDataPtr);
extern F_PASCAL(OSErr) IconIDToRgn(RgnHandle theRgn, const Rect *iconRect, IconAlignmentType align, short iconID);
extern F_PASCAL(OSErr) IconSuiteToRgn(RgnHandle theRgn, const Rect *iconRect, IconAlignmentType align, Handle theIconSuite);
extern F_PASCAL(OSErr) IconMethodToRgn(RgnHandle theRgn, const Rect *iconRect, IconAlignmentType align, IconGetterUPP theMethod, void *yourDataPtr);
extern F_PASCAL(OSErr) SetSuiteLabel(Handle theSuite, short theLabel);
extern F_PASCAL(short) GetSuiteLabel(Handle theSuite);
extern F_PASCAL(OSErr) GetIconCacheData(Handle theCache, void **theData);
extern F_PASCAL(OSErr) SetIconCacheData(Handle theCache, void *theData);
extern F_PASCAL(OSErr) GetIconCacheProc(Handle theCache, IconGetterUPP *theProc);
extern F_PASCAL(OSErr) SetIconCacheProc(Handle theCache, IconGetterUPP theProc);
extern F_PASCAL(OSErr) PlotIconHandle(const Rect *theRect, IconAlignmentType align, IconTransformType transform, Handle theIcon);
extern F_PASCAL(OSErr) PlotSICNHandle(const Rect *theRect, IconAlignmentType align, IconTransformType transform, Handle theSICN);
extern F_PASCAL(OSErr) PlotCIconHandle(const Rect *theRect, IconAlignmentType align, IconTransformType transform, CIconHandle theCIcon);
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


