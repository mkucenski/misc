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

#ifndef _DEBUGMSGS_H_
#define _DEBUGMSGS_H_

#ifdef _DEBUG_

#include <iostream>
using namespace std;

extern ostream* p_ostream;

#include <iostream>
#define DEBUG(msg)										(*p_ostream << "DEBUG(" << PACKAGE << "): " << msg << endl)
#define DEBUG_HEX_DUMP(p_rgData, count, width)	fprintf(stderr, "DEBUG:     "); u_int8_t* p_rgCastData = (u_int8_t*)p_rgData; for (int i=0; i<count; i++) { fprintf(stderr, "%s%02x", (i % width == 0 ? "\n\t" : " "), p_rgCastData[i]); } fprintf(stderr, "\n");

#else

#define DEBUG(msg)
#define DEBUG_HEX_DUMP(p_rgData, count, width)

#endif

#endif //_DEBUGMSGS_H_
