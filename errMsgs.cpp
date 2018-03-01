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

#include "errMsgs.h"

#include <fstream>
using namespace std;

ostream* p_ostream = &cerr;

bool logOpen(string strFilename) {
	bool rv = false;

	if (p_ostream == &cerr || p_ostream == NULL) {
		ofstream* p_ofstream = new ofstream;
		p_ofstream->open(strFilename, ofstream::out | ofstream::app);
		if (p_ofstream->good()) {
			rv = true;
			p_ostream = p_ofstream;
		} else {
			delete p_ofstream;
		}
	} else {
		ERROR("errMsgs::logOpen() Already open log file.");
	}

	return rv;
}

bool logClose() {
	bool rv = false;

	if (p_ostream != &cerr && p_ostream != NULL) {
		ofstream* p_ofstream = (ofstream*)p_ostream;
		p_ofstream->close();
		rv = !p_ofstream->fail();
		delete p_ofstream;
		p_ofstream = NULL;
		p_ostream = &cerr;
	} else {
		WARNING("errMsgs::logClose() No open log file.");
	}

	return rv;
}

