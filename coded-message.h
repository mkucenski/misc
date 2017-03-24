// Copyright 2017 Matthew A. Kucenski
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

#ifndef CODED_MESSAGE_H_
#define CODED_MESSAGE_H_

//#define _DEBUG_ 1

#include <sys/types.h>
#include <iostream>
using namespace std;

// The goal of this code is to simplify the process matching flagged bits and their associated message and details.
// Given a multi-bit value and defined table such as the following, you can find which bits are set and return the 
// details. 
//
//	static coded_message_t USNJRNL_SOURCES[] = {
//		{"USN_SOURCE_AUXILIARY_DATA"						0x00000002,	"The operation adds a private data..."},
//		{"USN_SOURCE_DATA_MANAGEMENT"						0x00000001,	"The operation provides information..."},
//		{"USN_SOURCE_REPLICATION_MANAGEMENT"			0x00000004,	"The operation is modifying a file..."},
//		{"USN_SOURCE_CLIENT_REPLICATION_MANAGEMENT"	0x00000008,	"The operation is modifying a file..."}
//	};
//
// Typically this would be accomplished by various '#define's and the following:
// 		'if (flags & single_flag > 0) { cout << single_flag_msg }'. 
//
// Instead, this can be accomplished by:
// 		'getMessage(single_flag, USNJRNL_SOURCES, sizeof(USNJRNL_SOURCES));' 
//
// Alternatively, you can request a comma-separated list of all messages values for a given set of codes as follows: 
// 		'getMessages(flags, USNJRNL_SOURCES, sizeof(USNJRNL_SOURCES));'

typedef struct {
	string strMessage;
	u_int32_t idCode;
	string strDetails;
	string strShort;
} coded_message_t; 

// Given a code value, find the corresponding message.
inline string getMessage(u_int32_t idCode, coded_message_t* table, u_int32_t size) { for (int i=0; i<size/sizeof(table[0]); i++) { if (table[i].idCode == idCode) { return table[i].strMessage; } } return ""; }

// Given a code value, find the corresponding short message.
inline string getShort(u_int32_t idCode, coded_message_t* table, u_int32_t size) { for (int i=0; i<size/sizeof(table[0]); i++) { if (table[i].idCode == idCode) { return table[i].strShort; } } return ""; }

// Given multiples code values, return a comma-separated list of messages.
inline string getMessages(u_int32_t codes, coded_message_t* table, u_int32_t size) { string rv; bool first=true; for (int i=0; i<size/sizeof(table[0]); i++) { if ((table[i].idCode & codes) > 0) { rv += (first ? "" : ", ") + table[i].strMessage; first=false; } } return rv; }

// Given multiples code values, return a comma-separated list of short messages.
inline string getShorts(u_int32_t codes, coded_message_t* table, u_int32_t size) { string rv; bool first=true; for (int i=0; i<size/sizeof(table[0]); i++) { if ((table[i].idCode & codes) > 0) { rv += (first ? "" : ", ") + table[i].strShort; first=false; } } return rv; }

// Given a message string, return the code value.
inline u_int32_t getCode(string strMessage, coded_message_t* table, u_int32_t size) { for (int i=0; i<size/sizeof(table[0]); i++) { if (table[i].strMessage == strMessage) { return table[i].idCode; } } return 0; }

// Given a message string, return the details string.
inline string getDetails(string strMessage, coded_message_t* table, u_int32_t size) { for (int i=0; i<size/sizeof(table[0]); i++) { if (table[i].strMessage == strMessage) { return table[i].strDetails; } } return ""; }

// Given a code value, return the details string.
inline string getDetails(u_int32_t idCode, coded_message_t* table, u_int32_t size) { for (int i=0; i<size/sizeof(table[0]); i++) { if (table[i].idCode == idCode) { return table[i].strDetails; } } return ""; }

// For a given set of codes, XOR out the known codes and return what's left. Assuming we know about all valid codes, the return value should be zero.
inline u_int32_t findUnknownCodes(u_int32_t codes, coded_message_t* table, u_int32_t size) { for (int i=0; i<size/sizeof(table[0]); i++) { codes ^= table[i].idCode; } return codes; }

#endif /*CODED_MESSAGE_H_*/

