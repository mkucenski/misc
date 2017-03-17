// Copyright 2007 Matthew A. Kucenski
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

#ifndef _WINDOWSTYPES_H_
#define _WINDOWSTYPES_H_

#include <sys/types.h>

typedef u_int8_t  BYTE;
typedef u_int16_t WORD;
typedef u_int32_t DWORD;
typedef u_int64_t DWORDLONG;
typedef wchar_t   WCHAR;
typedef int64_t   LARGE_INTEGER;
typedef u_int64_t QWORD;

typedef struct _FILETIME {
	DWORD dwLowDateTime;
	DWORD dwHighDateTime;
} __attribute__((packed)) FILETIME;

// FILE ATTRIBUTE CONSTANTS (https://msdn.microsoft.com/en-us/library/gg258117(v=vs.85).aspx)
#define FILE_ATTRIBUTE_ARCHIVE					0x20
#define FILE_ATTRIBUTE_COMPRESSED				0x800
#define FILE_ATTRIBUTE_DEVICE						0x40
#define FILE_ATTRIBUTE_DIRECTORY					0x10
#define FILE_ATTRIBUTE_ENCRYPTED					0x4000
#define FILE_ATTRIBUTE_HIDDEN						0x2
#define FILE_ATTRIBUTE_INTEGRITY_STREAM		0x8000
#define FILE_ATTRIBUTE_NORMAL						0x80
#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED	0x2000
#define FILE_ATTRIBUTE_NO_SCRUB_DATA			0x20000
#define FILE_ATTRIBUTE_OFFLINE					0x1000
#define FILE_ATTRIBUTE_READONLY					0x1
#define FILE_ATTRIBUTE_REPARSE_POINT			0x400
#define FILE_ATTRIBUTE_SPARSE_FILE				0x200
#define FILE_ATTRIBUTE_SYSTEM						0x4
#define FILE_ATTRIBUTE_TEMPORARY					0x100
#define FILE_ATTRIBUTE_VIRTUAL					0x10000

// SID STRUCTURE (https://blogs.msdn.microsoft.com/larryosterman/2004/09/01/what-is-this-thing-called-sid/)
// Conversion to String: "S-<bRevision>-<bIdentifierAuthority>-<dwSubAuthority#>..."
typedef struct _SID {
	BYTE bRevision;
	BYTE bSubAuthorityCount;
	BYTE bIdentifierAuthority[6];
	//DWORD dwSubAuthority[bSubAuthorityCount];
} __attribute__((packed)) SID;

#define SECURITY_NULL_SID_AUTHORITY         {0,0,0,0,0,0}
#define SECURITY_WORLD_SID_AUTHORITY        {0,0,0,0,0,1}
#define SECURITY_LOCAL_SID_AUTHORITY        {0,0,0,0,0,2}
#define SECURITY_CREATOR_SID_AUTHORITY      {0,0,0,0,0,3}
#define SECURITY_NON_UNIQUE_AUTHORITY       {0,0,0,0,0,4}
#define SECURITY_NT_AUTHORITY               {0,0,0,0,0,5}
#define SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

#endif //_WINDOWSTYPES_H_
