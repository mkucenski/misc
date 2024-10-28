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

#include "../endianSwitch.h"
#include "../debugMsgs.h"

#include <iostream>

int main(int argc, const char** argv) {
	DEBUG_INFO("Big Endian? " << (isBigEndian() ? "true" : "false"));
	DEBUG_INFO("Little Endian? " << (isLittleEndian() ? "true" : "false"));

	u_int16_t i = 16;
	DEBUG_INFO("0x" << std::hex << i << " / 0x" << endianSwitch16(i) << " (0x" << endianSwitch16(endianSwitch16(i)) << ")");
	DEBUG_INFO("0x" << std::hex << littleToHost16(i) << " / 0x" << bigToHost16(i));
	u_int32_t j = 16;
	DEBUG_INFO("0x" << std::hex << j << " / 0x" << endianSwitch32(j) << " (0x" << endianSwitch32(endianSwitch32(j)) << ")");
	DEBUG_INFO("0x" << std::hex << littleToHost32(j) << " / 0x" << bigToHost32(j));
	u_int64_t k = 16;
	DEBUG_INFO("0x" << std::hex << k << " / 0x" << endianSwitch64(k) << " (0x" << endianSwitch64(endianSwitch64(k)) << ")");
	DEBUG_INFO("0x" << std::hex << littleToHost64(k) << " / 0x" << bigToHost64(k));
		
}	//int main(int argc, const char** argv) {
