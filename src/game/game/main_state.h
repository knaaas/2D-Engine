#pragma once
#ifndef GAME_MAIN_STATE_H
#define GAME_MAIN_STATE_H

#include <iostream>

#include "run_state.h"

#include "../state/state.h"
#include "../gui/menu.h"

namespace game
{
	enum emenu_state : size_t
	{
		menu_play,
		menu_help,
		menu_exit
	};
	
	class cmain_state : public state::cstate
	{
	public:
		cmain_state();
		virtual ~cmain_state();
		
		/*
			Called by state engine. 
			Returns next state.
		*/
		virtual state::cstate* run();
	
	private:
		
		crun_state *p_run_state;
		
		const emenu_state _read_menu_input();
		state::cstate*  _return_sub_state( const emenu_state& state );
		state::cstate*  _return_run_state();
	};
}
#endif //GAME_MAIN_STATE_H