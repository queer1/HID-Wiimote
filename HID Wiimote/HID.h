/*

Copyright (C) 2013 Julian L�hr
All rights reserved.

Filename:
	HID.h

Abstract:
	Header file for HID.c
*/

#ifndef _HID_H_
#define _HID_H_

#include "HIDWiimote.h"

#include <hidport.h>

typedef struct _HID_DEVICE_CONTEXT 
{
	WDFQUEUE DefaultIOQueue;
	WDFQUEUE ReadBufferQueue;

	USHORT VendorID;
	USHORT ProductID;

	BOOLEAN PerformReadReportInstant;

} HID_DEVICE_CONTEXT, * PHID_DEVICE_CONTEXT;

typedef UCHAR HID_REPORT_DESCRIPTOR, *PHID_REPORT_DESCRIPTOR;

EVT_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL InternalDeviceControlCallback;

NTSTATUS PrepareHID(_In_ PDEVICE_CONTEXT DeviceContext);
NTSTATUS CreateQueues(_In_ WDFDEVICE Device, _In_ PHID_DEVICE_CONTEXT HIDContext);

NTSTATUS ReleaseHID(_In_ PDEVICE_CONTEXT DeviceContext);

NTSTATUS WiimoteStateUpdated(_In_ PDEVICE_CONTEXT DeviceContext);

#define IOCTL_WIIMOTE_ADDRESSES CTL_CODE(FILE_DEVICE_KEYBOARD, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

#endif