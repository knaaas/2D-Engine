#ifndef GAME_MAIN_STATE_H
#define GAME_MAIN_STATE_H

#include <iostream>

#include "run_state.h"

#include "../state/state.h"
#include "../gui/menu.h"

namespace Game
{
	enum EMenuState : size_t
	{
		menu_play,
		menu_help,
		menu_exit
	};
	
	class CMainState : public State::CState
	{
	public:
		CMainState();
		virtual ~CMainState();
		
		/*
			Called by state engine. 
			Returns next state.
		*/
		virtual State::CState::SReturn Run();
	
	private:
		CRunState *p_run_state;
		
		const EMenuState ReadMenuInput();
		State::CState*  ReturnSubState( const EMenuState& state );
		State::CState*  ReturnRunState();
	};
}
#endif // GAME_MAIN_STATE_H
