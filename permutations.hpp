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

#ifndef PERMUTATIONS_HPP_
#define PERMUTATIONS_HPP_

#include "misc/debugMsgs.h"

#include <vector>
using namespace std;

template <class T>
vector< vector<T> > permutations(vector<T> init) {
	vector<T> leaders;
	vector< vector<T> > perms;
	permutations_r(&init, &leaders, &perms);
	
	return perms;
}

template <class T>
void permutations_r(vector<T>* pInit, vector<T>* pLeaders, vector< vector<T> >* pDest) {
	if (pInit && pLeaders && pDest) {	
		vector<T> rest, perm;
		for (typename vector<T>::iterator it = pInit->begin(); it != pInit->end(); it++) {
			//Save this item as a permutation leader for use further down the recursion chain
			pLeaders->push_back(*it);

			//Build a vector of all other items that are not *it;
			rest.clear();
			for (typename vector<T>::iterator restIt = pInit->begin(); restIt != it; restIt++) {
				rest.push_back(*restIt);
			}
			for (typename vector<T>::iterator restIt = it+1; restIt != pInit->end(); restIt++) {
				rest.push_back(*restIt);
			}
			
			if (!rest.empty()) {			//Recurse through 'rest' to find all of its permutations
				permutations_r(&rest, pLeaders, pDest);	
			} else {							//Add the accumulated permutation leaders to this permutation and add it to the destination
				perm.clear();
				for (typename vector<T>::iterator leader = pLeaders->begin(); leader != pLeaders->end(); leader++) {
					perm.push_back(*leader);
				}
				pDest->push_back(perm);
			}
			
			//Remove this item from the permutation leader list
			pLeaders->pop_back();
		}
	} else {	//if (pInit && pLeaders && pDest) {
		DEBUG_ERROR("permutations_r() - Invalid pointer.");
	}
}

#endif /*PERMUTATIONS_HPP_*/
