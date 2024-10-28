// Copyright 2018 Matthew A. Kucenski
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

#ifndef _ERRMSGS_H_
#define _ERRMSGS_H_

// This functionality lets you output error/warning messages to either
// cerr or a text file. By default, everything goes to cerr. If you call
// logOpen(<filename>) that output will instead append to the specified
// file. Don't forget logClose() in order to properly cleanup!

#include <meson.h>

#include <iostream>
using namespace std;

extern ostream* p_ostream;

#define INFO(msg)		(*p_ostream << "INFO(" << PACKAGE << "): " << msg << endl)
#define ERROR(msg)	(*p_ostream << "ERROR(" << PACKAGE << "): " << msg << endl)
#define WARNING(msg)	(*p_ostream << "WARNING(" << PACKAGE << "): " << msg << endl)

bool logOpen(string strFilename); 
bool logClose();

#endif //_ERRMSGS_H_
