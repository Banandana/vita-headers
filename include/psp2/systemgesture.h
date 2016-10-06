/**
 * \file systemgesture.h
 * \brief Header file which defines gesture related variables and functions
 *
 * Copyright (C) 2016 VITASDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PSP2_SYSTEMGESTURE_H_
#define _PSP2_SYSTEMGESTURE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <psp2/types.h>
#include <psp2/touch.h>

#define SCE_SYSTEM_GESTURE_ERROR_INVALID_ARGUMENT 0x80890001
#define SCE_SYSTEM_GESTURE_ERROR_NOT_SUPPORTED_GESTURE 0x80890002
#define SCE_SYSTEM_GESTURE_ERROR_NOT_INITIALIZED 0x80890003
#define SCE_SYSTEM_GESTURE_ERROR_INDEX_OUT_OF_ARRAY 0x80890004
#define SCE_SYSTEM_GESTURE_ERROR_EVENT_DATA_NOT_FOUND 0x80890005

typedef enum SceSystemGestureTouchState
{
	SCE_SYSTEM_GESTURE_TOUCH_STATE_INACTIVE	= 0x00000000,
	SCE_SYSTEM_GESTURE_TOUCH_STATE_BEGIN	= 0x00000001,
	SCE_SYSTEM_GESTURE_TOUCH_STATE_ACTIVE	= 0x00000002,
	SCE_SYSTEM_GESTURE_TOUCH_STATE_END		= 0x00000003

} SceSystemGestureTouchState;

typedef enum SceSystemGestureType
{
	SCE_SYSTEM_GESTURE_TYPE_TAP				= 0x00000001,
	SCE_SYSTEM_GESTURE_TYPE_DRAG			= 0x00000002,
	SCE_SYSTEM_GESTURE_TYPE_TAP_AND_HOLD	= 0x00000004,
	SCE_SYSTEM_GESTURE_TYPE_PINCH_OUT_IN	= 0x00000008
} SceSystemGestureType;

typedef struct SceSystemGestureVector2
{
	SceInt16 x;
	SceInt16 y;

} SceSystemGestureVector2;

typedef struct SceSystemGestureRectangle
{
	SceInt16 x;
	SceInt16 y;
	SceInt16 width;
	SceInt16 height;

} SceSystemGestureRectangle;

typedef struct SceSystemGesturePrimitiveTouchEvent
{
	/* state of primitive touch event */
	SceSystemGestureTouchState eventState;

	/* logical add of touch panel port(higher 8bit) and touch ID(lower 8bit) */
	SceUInt16 primitiveID;

	/* pressed time position */
	SceSystemGestureVector2 pressedPosition;
	
	/* force value of pressed time */
	SceInt16 pressedForce;

	/* current finger position */
	SceSystemGestureVector2 currentPosition;

	/* current force value */
	SceInt16 currentForce;

	/* distance from previous updated position */
	SceSystemGestureVector2 deltaVector;

	/* force value difference from previous updated time */
	SceInt16 deltaForce;

	/* elapsed time from previous update (microseconds) */
	SceUInt64 deltaTime;

	/* elapsed tiem from when finger pressed (microseconds) */
	SceUInt64 elapsedTime;

	SceUInt8 reserved[56];

} SceSystemGesturePrimitiveTouchEvent;

typedef struct SceSystemGesturePrimitiveTouchRecognizerParameter
{
	SceUInt8 reserved[ 64 ];

} SceSystemGesturePrimitiveTouchRecognizerParameter;

typedef struct SceSystemGestureTouchRecognizer
{
	SceUInt64 reserved[ 307 ];
} SceSystemGestureTouchRecognizer;

/**
 * The data structure for receiving touch gesture recognizer information
 **/
typedef struct SceSystemGestureTouchRecognizerInformation
{
	/* touch gesture type */
	SceSystemGestureType gestureType;

	/* target touch panel port */
	SceUInt32 touchPanelPortID;

	/* target rectangle */
	SceSystemGestureRectangle rectangle;

	/* last updated time */
	SceUInt64 updatedTime;

	SceUInt8 reserved[ 256 ];
} SceSystemGestureTouchRecognizerInformation;

/**
 * parameters for Tap gesture recgonizer
 **/
typedef struct SceSystemGestureTapRecognizerParameter
{
	/* maximum tap counts to be recognized */
	SceUInt8 maxTapCount;

	SceUInt8 reserved[ 63 ];

} SceSystemGestureTapRecognizerParameter;

/**
 * parameters for Drag gesture recgonizer
 **/
typedef struct SceSystemGestureDragRecognizerParameter
{
	SceUInt8 reserved[ 64 ];
} SceSystemGestureDragRecognizerParameter;

/**
 * parameters for Tap and Hold gesture recgonizer
 **/
typedef struct SceSystemGestureTapAndHoldRecognizerParameter
{
	/* time to invoke this touch event (ms) */
	SceUInt64 timeToInvokeEvent;

	SceUInt8 reserved[ 56 ];
} SceSystemGestureTapAndHoldRecognizerParameter;

/**
 * parameters for Pinch Out/In gesture recgonizer
 **/
typedef struct SceSystemGesturePinchOutInRecognizerParameter
{
	SceUInt8 reserved[ 64 ];
} SceSystemGesturePinchOutInRecognizerParameter;

/**
 * union of gesture recgonizers' parameters
 **/
typedef union SceSystemGestureTouchRecognizerParameter
{
	SceUInt8 parameterBuf[ 64 ];

	/* parameters for Tap gesture recgonizer */
	SceSystemGestureTapRecognizerParameter tap;

	/* parameters for Drag gesture recgonizer */
	SceSystemGestureDragRecognizerParameter drag;

	/* parameters for Tap and Hold gesture recgonizer */
	SceSystemGestureTapAndHoldRecognizerParameter tapAndHold;

	/* parameters for Pinch Out/In gesture recgonizer */
	SceSystemGesturePinchOutInRecognizerParameter pinchOutIn;

} SceSystemGestureTouchRecognizerParameter;

/**
 * properties for Tap event
 **/
typedef struct SceSystemGestureTapEventProperty {

	/* primitive touch event ID related with this event */
	SceUInt16 primitiveID;

	/* tapped position */
	SceSystemGestureVector2 position;

	/* tapped count */
	SceUInt8 tappedCount;

	SceUInt8 reserved[ 57 ];
} SceSystemGestureTapEventProperty;

/**
 * properties for Drag event
 **/
typedef struct SceSystemGestureDragEventProperty {
	/* primitive touch event ID related with this event */
	SceUInt16 primitiveID;

	/* distance from previous updated position */
	SceSystemGestureVector2 deltaVector;

	/* current finger position */
	SceSystemGestureVector2 currentPosition;

	/* pressed time position */
	SceSystemGestureVector2 pressedPosition;

	SceUInt8 reserved[ 50 ];
} SceSystemGestureDragEventProperty;

/**
 * properties for Tap and Hold event
 **/
typedef struct SceSystemGestureTapAndHoldEventProperty {

	/* primitive touch event ID related with this event */
	SceUInt16 primitiveID;

	/* position of pressed time */
	SceSystemGestureVector2 pressedPosition;

	SceUInt8 reserved[ 58 ];
} SceSystemGestureTapAndHoldEventProperty;

/**
 * properties for Pinch Out/In event
 **/
typedef struct SceSystemGesturePinchOutInEventProperty {

	/* scale factor relative to the positions at when two fingers were paired  */
	float scale;

	struct {
		/* primitive touch event ID related with this event */
		SceUInt16 primitiveID;

		/* position of pressed time */
		SceSystemGestureVector2 currentPosition;

		/* distance from previous updated position */
		SceSystemGestureVector2 deltaVector;

		/* position at when two fingers were paired */
		SceSystemGestureVector2 pairedPosition;
	} primitive[2];
	/* touch datas related with this event */

	SceUInt8 reserved[ 32 ];
} SceSystemGesturePinchOutInEventProperty;

/**
 * The data structure for touch event data
 **/
typedef struct SceSystemGestureTouchEvent
{
	/* touch gesture event ID */
	SceUInt32 eventID;

	/* touch gesture state */
	SceSystemGestureTouchState eventState;

	/* touch gesture type */
	SceSystemGestureType gestureType;

	SceUInt8 padding[4];

	/* last updated time */
	SceUInt64 updatedTime;

	union {
		/* buffer */
		SceUInt8 propertyBuf[ 64 ];

		/* property for Tap event */
		SceSystemGestureTapEventProperty tap;

		/* property for Drag event */
		SceSystemGestureDragEventProperty drag;

		/* property for Tap and Hold event */
		SceSystemGestureTapAndHoldEventProperty tapAndHold;

		/* property for Pinch Out/In event */
		SceSystemGesturePinchOutInEventProperty pinchOutIn;
	} property;

	SceUInt8 reserved[56];

} SceSystemGestureTouchEvent;

int sceSystemGestureInitializePrimitiveTouchRecognizer(SceSystemGesturePrimitiveTouchRecognizerParameter* parameter);

int sceSystemGestureFinalizePrimitiveTouchRecognizer();

int sceSystemGestureResetPrimitiveTouchRecognizer();

int sceSystemGestureUpdatePrimitiveTouchRecognizer(const SceTouchData* pFrontData , const SceTouchData* pBackData);

int sceSystemGestureGetPrimitiveTouchEvents(SceSystemGesturePrimitiveTouchEvent* primitiveEventBuffer, const SceUInt32 capacityOfBuffer, SceUInt32* numberOfEvent);

int sceSystemGestureGetPrimitiveTouchEventsCount();

int sceSystemGestureGetPrimitiveTouchEventByIndex(const SceUInt32 index, SceSystemGesturePrimitiveTouchEvent* primitiveTouchEvent);

int sceSystemGestureGetPrimitiveTouchEventByPrimitiveID(const SceUInt16 primitiveID, SceSystemGesturePrimitiveTouchEvent* primitiveTouchEvent);

int sceSystemGestureCreateTouchRecognizer(SceSystemGestureTouchRecognizer* touchRecognizer, const SceSystemGestureType gestureType, const SceUInt8 touchPanelPortID, const SceSystemGestureRectangle* rectangle, const SceSystemGestureTouchRecognizerParameter* touchRecognizerParameter );

int sceSystemGestureGetTouchRecognizerInformation(const SceSystemGestureTouchRecognizer* touchRecognizer, SceSystemGestureTouchRecognizerInformation* information);

int sceSystemGestureResetTouchRecognizer( SceSystemGestureTouchRecognizer* touchRecognizer );

int sceSystemGestureUpdateTouchRecognizer( SceSystemGestureTouchRecognizer* touchRecognizer );

int sceSystemGestureUpdateTouchRecognizerRectangle( SceSystemGestureTouchRecognizer* touchRecognizer, const SceSystemGestureRectangle* rectangle );

int sceSystemGestureGetTouchEvents( const SceSystemGestureTouchRecognizer* touchRecognizer, SceSystemGestureTouchEvent* eventBuffer, const SceUInt32 capacityOfBuffer, SceUInt32* numberOfEvent);

int sceSystemGestureGetTouchEventsCount( const SceSystemGestureTouchRecognizer* touchRecognizer );

int sceSystemGestureGetTouchEventByIndex( const SceSystemGestureTouchRecognizer* touchRecognizer, const SceUInt32 index, SceSystemGestureTouchEvent* touchEvent);

int sceSystemGestureGetTouchEventByEventID( const SceSystemGestureTouchRecognizer* touchRecognizer, const SceUInt32 eventID, SceSystemGestureTouchEvent* touchEvent);


#ifdef __cplusplus
}
#endif

#endif
