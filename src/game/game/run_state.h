#ifndef GAME_RUN_STATE_H
#define GAME_RUN_STATE_H

#include <vector>
#include <cassert>

#include "../state/state.h"

namespace Game
{
	class CRunState : public State::CState
	{
		public:
			CRunState();
			virtual ~CRunState();

			void Initialize( void );
			
			virtual State::CState::SReturn Run();
			
		private:
			
	};
}

#endif // GAME_RUN_STATE_H
