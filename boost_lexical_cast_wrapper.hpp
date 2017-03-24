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

#ifndef _BOOST_LEXICAL_CAST_WRAPPER_HPP_
#define _BOOST_LEXICAL_CAST_WRAPPER_HPP_

#include <boost/lexical_cast.hpp>
#include "debugMsgs.h"

template <typename TargetType, typename SourceType>
int boost_lexical_cast_wrapper(const SourceType& src, TargetType* ptarget) {
	int rv = -1;
	
	try {
		*ptarget = boost::lexical_cast<TargetType>(src);
		rv = 0;
	} catch(boost::bad_lexical_cast&) {
		DEBUG_ERROR("boost_lexical_cast_wrapper() Caught exception on conversion.");
	}
	
	return rv;
}

template <typename TargetType, typename SourceType>
TargetType boost_lexical_cast_wrapper(const SourceType& src) {
	TargetType target;
	boost_lexical_cast_wrapper<TargetType>(src, &target);
	return target;
}

#endif //_BOOST_LEXICAL_CAST_WRAPPER_HPP_
