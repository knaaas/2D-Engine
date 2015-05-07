#pragma once
#ifndef STATE_FLOW_H
#define STATE_FLOW_H

#include "state.h"

namespace state
{
	class cflow : public cengine
	{
		public:
			virtual void run( cstate& state );
		private:
	};
}

#endif //STATE_FLOW_H