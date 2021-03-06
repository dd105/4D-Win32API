/*
	File:		Displays.h

	Copyright:	� 1984-1993 by Apple Computer, Inc., all rights reserved.

	WARNING
	This file was auto generated by the interfacer tool. Modifications
	must be made to the master file.

*/

#ifndef __DISPLAYS__
#define __DISPLAYS__

#ifndef __TRAPS__
#include <Traps.h>
#endif

#ifndef __EVENTS__
#include <Events.H>
#endif

#ifndef __PROCESSES__
#include <Processes.H>
#endif

#ifndef __COMPONENTS__
#include <Components.H>
#endif

#ifndef __WINDOWS__
#include <WindowM.H>
#endif

#ifndef __APPLEEVENTS__
#include <AppleEvents.H>
#endif


/* AppleEvents Core Suite */

#define kAESystemConfigNotice OST_cnfg


/* Core Suite types */

#define kAEDisplayNotice OST_dspl

#define kAEDisplaySummary OST_dsum

#define keyDMConfigVersion OST_dmcv

#define keyDMConfigFlags OST_dmcf

#define keyDMConfigReserved OST_dmcr

#define keyDisplayID OST_dmid

#define keyDisplayComponent OST_dmdc

#define keyDisplayDevice OST_dmdd

#define keyDisplayFlags OST_dmdf

#define keyDisplayMode OST_dmdm

#define keyDisplayModeReserved OST_dmmr

#define keyDisplayReserved OST_dmdr

#define keyDisplayMirroredId OST_dmmi

#define keyDeviceFlags OST_dddf

#define keyDeviceDepthMode OST_dddm

#define keyDeviceRect OST_dddr

#define keyPixMapRect OST_dpdr

#define keyPixMapHResolution OST_dphr

#define keyPixMapVResolution OST_dpvr

#define keyPixMapPixelType OST_dppt

#define keyPixMapPixelSize OST_dpps

#define keyPixMapCmpCount OST_dpcc

#define keyPixMapCmpSize OST_dpcs

#define keyPixMapAlignment OST_dppa

#define keyPixMapResReserved OST_dprr

#define keyPixMapReserved OST_dppr

#define keyPixMapColorTableSeed OST_dpct

#define keySummaryMenubar OST_dsmb

#define keySummaryChanges OST_dsch

#define keyDisplayOldConfig OST_dold

#define keyDisplayNewConfig OST_dnew

#define dmOnlyActiveDisplays true

#define dmAllDisplays false

typedef unsigned long DisplayIDType;


/* Switch Flags */

enum  {
	kNoSwitchConfirmBit			= 0,			/* Flag indicating that there is no need to confirm a switch to this mode */
	kDepthNotAvailableBit
};


/* Summary Change Flags (sticky bits indicating an operation was performed) */


/* Note that moving a display, then moving it back will still set the kMovedDisplayBit */

enum  {
	kBeginEndConfigureBit		= 0,
	kMovedDisplayBit,
	kSetMainDisplayBit,
	kSetDisplayModeBit,
	kAddDisplayBit,
	kRemoveDisplayBit,
	kNewDisplayBit,
	kDisposeDisplayBit,
	kEnabledDisplayBit,
	kDisabledDisplayBit,
	kMirrorDisplayBit,
	kUnMirrorDisplayBit
};

typedef F_PASCAL_PTR(void,*DMNotificationProcPtr)(AppleEvent *theEvent);

enum {
	uppDMNotificationProcInfo = kPascalStackBased
		| STACK_ROUTINE_PARAMETER(1, SIZE_CODE(sizeof(AppleEvent*)))
};

#if USESROUTINEDESCRIPTORS
typedef UniversalProcPtr DMNotificationUPP;

#define CallDMNotificationProc(userRoutine, theEvent)		\
		CallUniversalProc((UniversalProcPtr)(userRoutine), uppDMNotificationProcInfo, (theEvent))
#define NewDMNotificationProc(userRoutine)		\
		(DMNotificationUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppDMNotificationProcInfo, GetCurrentISA())
#else
typedef DMNotificationProcPtr DMNotificationUPP;

#define CallDMNotificationProc(userRoutine, theEvent)		\
		(*(userRoutine))((theEvent))
#define NewDMNotificationProc(userRoutine)		\
		(DMNotificationUPP)(userRoutine)
#endif

#if 0
// lve have been moved to Errors.h
/* Display Manager Error Codes */

enum  {
	kDMGenErr			= -6220,			/* Unexpected Error */
/* Mirroring-Specific Errors */
	kDMMirroringOnAlreadyErr	= -6221,			/* Returned by all calls that need mirroring to be off to do their thing */
	kDMWrongNumberOfDisplaysErr	= -6222,			/* Can only handle 2 displays for now */
	kDMMirroringBlockedErr		= -6223,			/* DMBlockMirroring() has been called */
	kDMCantBlockErr			= -6224,			/* Mirroring is already on, can�t Block now (call DMUnMirror() first) */
	kDMMirroringNotOnErr		= -6225,			/* Returned by all calls that need mirroring to be on to do their thing */
/* Other Errors */
	kSysSWTooOldErr			= -6226,			/* Missing critical pieces of System Software */
	kDMSWNotInitializedErr		= -6227,			/* Required software not initialized (eg windowmanager or display mgr) */
	kDMDriverNotDisplayMgrAwareErr = -6228,			/* Video Driver does not support display manager */
	kDMDisplayNotFoundErr		= -6229,			/* Could not find item */
	kDMDisplayAlreadyInstalledErr = -6230			/* Attempt to add an already installed display */
};
#endif

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

extern F_PASCAL(GDHandle) DMGetFirstScreenDevice(Boolean activeOnly);
extern F_PASCAL(GDHandle) DMGetNextScreenDevice(GDHandle theDevice, Boolean activeOnly);
extern F_PASCAL(void) DMDrawDesktopRect(Rect *globalRect);
extern F_PASCAL(void) DMDrawDesktopRegion(RgnHandle globalRgn);
extern F_PASCAL(OSErr) DMGetGDeviceTablecloth(GDHandle displayDevice, ComponentInstance *tableclothInstance);
extern F_PASCAL(OSErr) DMSetGDeviceTablecloth(GDHandle displayDevice, ComponentInstance tableclothInstance);
extern F_PASCAL(OSErr) DMBeginConfigureDisplays(Handle *displayState);
extern F_PASCAL(OSErr) DMEndConfigureDisplays(Handle displayState);
extern F_PASCAL(OSErr) DMAddDisplay(GDHandle newDevice, short driver, unsigned long mode, unsigned long reserved, unsigned long displayID, ComponentInstance displayComponent, Handle displayState);
extern F_PASCAL(OSErr) DMMoveDisplay(GDHandle moveDevice, short x, short y, Handle displayState);
extern F_PASCAL(OSErr) DMDisableDisplay(GDHandle disableDevice, Handle displayState);
extern F_PASCAL(OSErr) DMEnableDisplay(GDHandle enableDevice, Handle displayState);
extern F_PASCAL(OSErr) DMRemoveDisplay(GDHandle removeDevice, Handle displayState);
extern F_PASCAL(OSErr) DMGetComponentAnimateTicks(ComponentInstance animationComponent, unsigned long *goodDelay, unsigned long *maxDelay);
extern F_PASCAL(OSErr) DMSetComponentAnimateTicks(ComponentInstance animationComponent, unsigned long goodDelay, unsigned long maxDelay);
extern F_PASCAL(OSErr) DMGetNextAnimateTime(unsigned long *nextAnimateTime);
extern F_PASCAL(OSErr) DMSetMainDisplay(GDHandle newMainDevice, Handle displayState);
extern F_PASCAL(OSErr) DMSetDisplayMode(GDHandle theDevice, unsigned long mode, unsigned long *depthMode, unsigned long reserved, Handle displayState);
extern F_PASCAL(OSErr) DMCheckDisplayMode(GDHandle theDevice, unsigned long mode, unsigned long depthMode, unsigned long *switchFlags, unsigned long reserved, Boolean *modeOk);
extern F_PASCAL(OSErr) DMGetDeskRegion(RgnHandle *desktopRegion);
extern F_PASCAL(OSErr) DMRegisterNotifyProc(DMNotificationUPP notificationProc, ProcessSerialNumberPtr whichPSN);
extern F_PASCAL(OSErr) DMRemoveNotifyProc(DMNotificationUPP notificationProc, ProcessSerialNumberPtr whichPSN);
extern F_PASCAL(OSErr) DMQDIsMirroringCapable(Boolean *qdIsMirroringCapable);
extern F_PASCAL(OSErr) DMCanMirrorNow(Boolean *canMirrorNow);
extern F_PASCAL(OSErr) DMIsMirroringOn(Boolean *isMirroringOn);
extern F_PASCAL(OSErr) DMMirrorDevices(GDHandle gD1, GDHandle gD2, Handle displayState);
extern F_PASCAL(OSErr) DMUnmirrorDevice(GDHandle gDevice, Handle displayState);
extern F_PASCAL(OSErr) DMGetNextMirroredDevice(GDHandle gDevice, GDHandle *mirroredDevice);
extern F_PASCAL(OSErr) DMBlockMirroring(void);
extern F_PASCAL(OSErr) DMUnblockMirroring(void);
extern F_PASCAL(OSErr) DMGetDisplayMgrA5World(unsigned long *dmA5);
extern F_PASCAL(OSErr) DMGetDisplayIDByGDevice(GDHandle displayDevice, DisplayIDType *displayID, Boolean failToMain);
extern F_PASCAL(OSErr) DMGetGDeviceByDisplayID(DisplayIDType displayID, GDHandle *displayDevice, Boolean failToMain);
extern F_PASCAL(OSErr) DMSetDisplayComponent(GDHandle theDevice, ComponentInstance displayComponent);
extern F_PASCAL(OSErr) DMGetDisplayComponent(GDHandle theDevice, ComponentInstance *displayComponent);
extern F_PASCAL(OSErr) DMNewDisplay(GDHandle *newDevice, short driverRefNum, unsigned long mode, unsigned long reserved, DisplayIDType displayID, ComponentInstance displayComponent, Handle displayState);
extern F_PASCAL(OSErr) DMDisposeDisplay(GDHandle disposeDevice, Handle displayState);
extern F_PASCAL(OSErr) DMResolveDisplayComponents(void);
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


