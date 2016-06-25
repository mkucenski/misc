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
typedef u_int64_t QWORD;

typedef struct _FILETIME {
	DWORD dwLowDateTime;
	DWORD dwHighDateTime;
} __attribute__((packed)) FILETIME;

#endif //_WINDOWSTYPES_H_
