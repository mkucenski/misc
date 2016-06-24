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

#ifndef _DEBUGMSGS_H_
#define _DEBUGMSGS_H_

#ifdef _DEBUG_
#include <iostream>
#define DEBUG_ERROR(msg)	(std::cerr << "DEBUG ERROR: " << msg << std::endl)
#define DEBUG_WARNING(msg)	(std::cerr << "DEBUG WARNING: " << msg << std::endl)
#define DEBUG_INFO(msg)		(std::cerr << "DEBUG INFO: " << msg << std::endl)
#else
#define DEBUG_ERROR(msg)
#define DEBUG_WARNING(msg)
#define DEBUG_INFO(msg)
#endif

#endif //_DEBUGMSGS_H_
