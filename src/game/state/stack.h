#pragma once
#ifndef STATE_STACK_H
#define STATE_STACK_H

#include <stack>
#include <iostream>
#include <cassert>

#include "state.h"

namespace state{
	class cstack{
		public:
			virtual void run( cstate& state );
		private:
			std::stack<cstate*> m_state;
	};
}

#endif //STATE_STACK_H