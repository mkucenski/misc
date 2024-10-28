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

#define _DEBUG_ 1

#include "../coded-message.h"
#include "../debugMsgs.h"

#include <iostream>


static coded_message_t table[] = {
	{ "test1", 0x1000 },
	{ "test2", 0x2000 },
	{ "test3", 0x3000 },
	{ "test4", 0x4000 }
};

int main(int argc, const char** argv) {

	DEBUG_INFO(getMessage(0x1000, table, sizeof(table)));
	DEBUG_INFO(getCode("test1", table, sizeof(table)));
	DEBUG_INFO(getMessage(0x2000, table, sizeof(table)));
	DEBUG_INFO(getCode("test2", table, sizeof(table)));
	DEBUG_INFO(getMessage(0x3000, table, sizeof(table)));
	DEBUG_INFO(getCode("test3", table, sizeof(table)));
	DEBUG_INFO(getMessage(0x4000, table, sizeof(table)));
	DEBUG_INFO(getCode("test4", table, sizeof(table)));

	dumpTable(table, sizeof(table));

}	//int main(int argc, const char** argv) {
