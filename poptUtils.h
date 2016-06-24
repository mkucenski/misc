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

#ifndef _POPTUTILS_H_
#define _POPTUTILS_H_

#include <popt.h>
#include <string>
#include <iostream>

using namespace std;

void usage(poptContext optCon, const char* error = NULL, const char* addl = NULL) {
	if (error) {
		cerr << error << (addl ? ": " : "") << (addl ? addl : "") << "\n";
	}
	poptPrintUsage(optCon, stderr, 0);
}	//void usage(poptContext optCon, int exitcode, const char *error, const char *addl) {

void version(string appname, string version) {
	cout << appname << " version: " << version << "\n";
}
 
#endif //_POPTUTILS_H_
