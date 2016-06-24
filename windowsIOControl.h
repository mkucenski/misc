// Copyright 2016 Matthew A. Kucenski
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _WINDOWSIOCONTROL_H_
#define _WINDOWSIOCONTROL_H_

#include <sys/types.h>
#include "misc/windowsTypes.h"

#define WINIOCTL_CODE(devType, function, method, access)	(((devType) << 16) | ((access) << 14) | ((function) << 2) | (method))

#define WINIOCTL_GET_DEVTYPE(winCtlCode)		(((DWORD)(winCtlCode & 0xffff0000)) >> 16)
#define WINIOCTL_GET_ACCESS(winCtlCode)		(((BYTE)(winCtlCode & 0xc000)) >> 14)
#define WINIOCTL_GET_FUNCTION(winCtlCode)		(((WORD)(winCtlCode & 0x3ffc)) >> 2)
#define WINIOCTL_GET_METHOD(winCtlCode)		((BYTE)(winCtlCode & 0x3))

#define WINIOCTL_METHOD_BUFFERED			0x0
#define WINIOCTL_METHOD_IN_DIRECT		0x1
#define WINIOCTL_METHOD_OUT_DIRECT		0x2
#define WINIOCTL_METHOD_NEITHER			0x3

#define WINIOCTL_ACCESS_FILE_ANY			0x0
#define WINIOCTL_ACCESS_FILE_READ		0x1
#define WINIOCTL_ACCESS_FILE_WRITE		0x2

typedef struct _WINIOCTL_SCSI_PASS_THROUGH_DIRECT {
	WORD	wLength;
	BYTE	bScsiStatus;
	BYTE	bPathId;
	BYTE	bTargetId;
	BYTE	bLun;
	BYTE	bCdbLength;
	BYTE	bSenseInfoLength;
	BYTE	bDataTransferType;
	BYTE	bPadding[3];
	DWORD	dwDataTransferLength;
	DWORD	dwTimeOutValue;
	DWORD	dwDataBufferPointer;
	DWORD	dwSenseInfoOffset;
	BYTE	bCdb[16];
} __attribute__((packed)) WINIOCTL_SCSI_PASS_THROUGH_DIRECT;

#define WINIOCTL_SCSI_DATA_IN				0x1
#define WINIOCTL_SCSI_DATA_OUT			0x0
#define WINOCTL_SCSI_DATA_UNSPECIFIED	0x2

#endif //_WINDOWSIOCONTROL_H_
