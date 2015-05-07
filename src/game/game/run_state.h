#pragma once
#ifndef GAME_RUN_STATE_H
#define GAME_RUN_STATE_H

#include <vector>
#include <cassert>


#include "../state/state.h"

namespace game
{
	class crun_state : public state::cstate
	{
		public:
			crun_state();
			virtual ~crun_state();

			void initialize( void );
			
			virtual state::cstate* run();
			
		private:
			
	};
}

#endif //GAME_RUN_STATE_H