/*
	File:		CursorDevices.h

	Copyright:	� 1984-1993 by Apple Computer, Inc., all rights reserved.

	WARNING
	This file was auto generated by the interfacer tool. Modifications
	must be made to the master file.

*/

#ifndef __CURSORDEVICES__
#define __CURSORDEVICES__

#ifndef __TYPES__
#include <MacTypes.H>
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
/* Button Operations */

enum  {
	kButtonNoOp			= 0,			/* No action for this button */
	kButtonSingleClick			= 1,			/* Normal mouse button */
	kButtonDoubleClick			= 2,			/* Click-release-click when pressed */
	kButtonClickLock			= 3,			/* Click on press, release on next press */
	kButtonCharStroke			= 4,			/* A keystroke, data=(modifiers, char code) */
	kButtonAppleScript			= 5,			/* An AppleScript */
	kButtonCustom			= 6			/* Custom behavior, data=proc pointer */
};


/* Device Classes */

enum  {
	kDeviceClassAbsolute		= 0,			/* a flat-response device */
	kDeviceClassMouse			= 1,			/* mechanical or optical mouse */
	kDeviceClassTrackball		= 2,			/* trackball */
	kDeviceClassScratchPad		= 3,			/* (midas) */
	kDeviceClassJoystick		= 4,			/* (homeRow) */
	kDeviceClassRelTablet		= 5			/* relative tablet */
};


/* Structures used in Cursor Device Manager calls */

typedef struct CrsrData CrsrData, *CrsrDataPtr;

struct CrsrData {
	CrsrDataPtr			nextCrsrData;			/* next in global list */
	Ptr			displayInfo;			/* unused (reserved for future) */
	Fixed			whereX;			/* horizontal position */
	Fixed			whereY;			/* vertical position */
	Point			where;			/* the pixel position */
	Boolean			isAbs;			/* has been stuffed with absolute coords */
	unsigned char			ButtonCount;			/* number of buttons currently pressed */
	unsigned short			ScreenRes;			/* pixels per inch on the current display */
};
typedef struct CrsrDevice CrsrDevice, *CrsrDevicePtr;

struct CrsrDevice {
	CrsrDevicePtr			nextCrsrDev;			/* pointer to next record in linked list */
	CrsrDataPtr			whichCursor;			/* pointer to data for target cursor */
	long			refCon;			/* applicaiton-defined */
	long			unused;			/* reserved for future */
	OSType			devID;			/* device identifier (from ADB reg 1) */
	Fixed			resolution;			/* units/inch (orig. from ADB reg 1) */
	unsigned char			devClass;			/* device class (from ADB reg 1) */
	unsigned char			cntButtons;			/* number of buttons (from ADB reg 1) */
	char			spare1;			/* reserved for future */
	unsigned char			buttons;			/* state of all buttons */
	unsigned char			buttonOp[8];			/* action performed per button */
	unsigned long			buttonTicks[8];			/* ticks when button last went up (for debounce) */
	long			buttonData[8];			/* data for the button operation */
	unsigned long			doubleClickTime;			/* device-specific double click speed */
	Fixed			acceleration;			/* current acceleration */
	short			privateFields[15];			/* fields used internally to CDM */
};
#ifdef __cplusplus
extern "C" {
#endif

extern OSErr pascal CrsrDevMove(CrsrDevicePtr ourDevice, long deltaX, long deltaY);
extern OSErr pascal CrsrDevMoveTo(CrsrDevicePtr ourDevice, long absX, long absY);
extern OSErr pascal CrsrDevFlush(CrsrDevicePtr ourDevice);
extern OSErr pascal CrsrDevButtons(CrsrDevicePtr ourDevice);
extern OSErr pascal CrsrDevButtonDown(CrsrDevicePtr ourDevice);
extern OSErr pascal CrsrDevButtonUp(CrsrDevicePtr ourDevice);
extern OSErr pascal CrsrDevButtonOp(CrsrDevicePtr ourDevice);
extern OSErr pascal CrsrDevSetButtons(CrsrDevicePtr ourDevice);
extern OSErr pascal CrsrDevSetAcceleration(CrsrDevicePtr ourDevice);
extern OSErr pascal CrsrDevDoubleTime(CrsrDevicePtr ourDevice);
extern OSErr pascal CrsrDevUnitsPerInch(CrsrDevicePtr ourDevice);
extern OSErr pascal CrsrDevNextDevice(CrsrDevicePtr *ourDevice);
extern OSErr pascal CrsrDevNewDevice(CrsrDevicePtr *ourDevice);
extern OSErr pascal CrsrDevDisposeDevice(CrsrDevicePtr ourDevice);
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


