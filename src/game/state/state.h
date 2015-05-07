#ifndef STATE_H
#define STATE_H

#include "debug.h"

namespace State
{
	class CState{
		public:
			virtual ~CState(){}
			virtual CState* Run() = 0;
	};
	
	class CEngine{
		public:
			virtual void Run( CState& state ) = 0;
	};
}

#endif // STATE_H
