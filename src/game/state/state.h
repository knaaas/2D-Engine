#ifndef STATE_H
#define STATE_H

#include "debug.h"

namespace State
{
	class CState
	{
		public:
			/*
				Wrapper for preventing CState from returning 
				bad pointer. 
			*/
			struct SReturn
			{
				CState *ret;
				SReturn( CState *state = nullptr ) : ret( state ){}
			};
			
			virtual ~CState(){}
			virtual SReturn Run() = 0;
	};
	
	class CEngine{
		public:
			virtual void Run( CState& state ) = 0;
	};
}

#endif // STATE_H
