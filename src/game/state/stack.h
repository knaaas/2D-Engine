#ifndef STATE_STACK_H
#define STATE_STACK_H

#include <stack>
#include <iostream>
#include <cassert>

#include "state.h"

namespace State{
	class CStack{
		public:
			virtual void Run( CState& state );
		private:
			std::stack<CState*> m_state;
	};
}

#endif // STATE_STACK_H
