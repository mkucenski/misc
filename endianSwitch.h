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

#ifndef ENDIANSWITCH_H_
#define ENDIANSWITCH_H_

#include <sys/types.h>

//Little-endian	->	PowerPC
//Big-endian	->	Intel x86

#define LITTLETOHOST16(var)	var = littleToHost16(var)
#define LITTLETOHOST32(var)	var = littleToHost32(var)
#define LITTLETOHOST64(var)	var = littleToHost64(var)

#define BIGTOHOST16(var)		var = bigToHost16(var)
#define BIGTOHOST32(var)		var = bigToHost32(var)
#define BIGTOHOST64(var)		var = bigToHost64(var)

inline u_int16_t endianSwitch16(u_int16_t twobytes) { return (twobytes << 8) | (twobytes >> 8); }
inline u_int32_t endianSwitch32(u_int32_t fourbytes) { return (u_int32_t)(endianSwitch16(fourbytes & 0xFFFF)) << 16 | endianSwitch16(fourbytes >> 16); }
inline u_int64_t endianSwitch64(u_int64_t eightbytes) { return (u_int64_t)(endianSwitch32(eightbytes & 0xFFFFFFFF)) << 32 | endianSwitch32(eightbytes >> 32); }

#ifdef _LITTLE_ENDIAN_
	inline u_int16_t littleToHost16(u_int16_t twobytes) { return twobytes; }
	inline u_int32_t littleToHost32(u_int32_t fourbytes) { return fourbytes; }
	inline u_int64_t littleToHost64(u_int64_t eightbytes) { return eightbytes; }

	inline u_int16_t bigToHost16(u_int16_t twobytes) { return endianSwitch16(twobytes); }
	inline u_int32_t bigToHost32(u_int32_t fourbytes) { return endianSwitch32(fourbytes); }
	inline u_int64_t bigToHost64(u_int64_t eightbytes) { return endianSwitch64(eightbytes); }
#else //_LITTLE_ENDIAN_
	inline u_int16_t littleToHost16(u_int16_t twobytes) { return endianSwitch16(twobytes); }
	inline u_int32_t littleToHost32(u_int32_t fourbytes) { return endianSwitch32(fourbytes); }
	inline u_int64_t littleToHost64(u_int64_t eightbytes) { return endianSwitch64(eightbytes); }

	inline u_int16_t bigToHost16(u_int16_t twobytes) { return twobytes; }
	inline u_int32_t bigToHost32(u_int32_t fourbytes) { return fourbytes; }
	inline u_int64_t bigToHost64(u_int64_t eightbytes) { return eightbytes; }
#endif //_LITTLE_ENDIAN_

#endif /*ENDIANSWITCH_H_*/
