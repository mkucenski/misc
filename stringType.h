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

#ifndef _STRINGSWAP_H_
#define _STRINGSWAP_H_

#include <string>

#ifdef _NO_WIDE_STRING_SUPPORT_

#define STR(str)	str
#define STROUT		cout
typedef std::string string_t;

#else

#define STR(str)	L##str
#define STROUT		wcout
typedef std::wstring string_t;

#endif //_NO_WIDE_STRING_SUPPORT_

#endif //_STRINGSWAP_H_
