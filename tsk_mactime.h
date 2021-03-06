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

#ifndef _TSK_MACTIME_H_
#define _TSK_MACTIME_H_

// TSK 3.0+: MD5|name|inode|mode_as_string|UID|GID|size|atime|mtime|ctime|crtime
//           1  |2   |3    |4             |5  |6  |7   |8    |9    |10   |11

// DATATIME
// |                    24| |      10| | 4| |        12| |     8| |     8| |        12| |...
// Wed Jun 10 2009 21:45:11    2359352 ma.b r/rrwxrwxrwx        0        0  69058-128-4 vol3/Windows/SysWOW64/oobe/background.bmp
//                             2359352 ma.b r/rrwxrwxrwx        0        0  69058-128-4 vol3/Windows/winsxs/x86_setup-uxwizard-clientimages_31bf3856ad364e35_6.1.7600.16385_none_48ada01d8ff36e68/background.bmp

#define TSK3_MACTIME_MD5 		0
#define TSK3_MACTIME_NAME 		1
#define TSK3_MACTIME_INODE 	2
#define TSK3_MACTIME_PERMS		3
#define TSK3_MACTIME_UID		4
#define TSK3_MACTIME_GID		5
#define TSK3_MACTIME_SIZE		6
#define TSK3_MACTIME_ATIME		7
#define TSK3_MACTIME_MTIME		8
#define TSK3_MACTIME_CTIME		9
#define TSK3_MACTIME_CRTIME	10

#define TSK3_MACTIME_AVAIL		11

#endif //_TSK_MACTIME_H

