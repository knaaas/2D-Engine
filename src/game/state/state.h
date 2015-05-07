#pragma once
#ifndef STATE_H
#define STATE_H

#include "debug.h"

namespace state
{
	class cstate{
		public:
			virtual ~cstate(){}
			virtual cstate* run() = 0;
	};
	
	class cengine{
		public:
			virtual void run( cstate& state ) = 0;
	};
}

#endif //STATE_H
