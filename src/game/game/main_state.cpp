#include "main_state.h"

namespace game
{
	const char *emenu_option[] = {
		"play",
		"help",
		"exit"
	};
	
	cmain_state::cmain_state() 
	{
		p_run_state = new crun_state();
		assert( p_run_state );
	}
	
	cmain_state::~cmain_state()
	{
		delete p_run_state;
	}
	
	state::cstate* cmain_state::run()
	{
		
		//Read selected menu option
		const emenu_state state( _read_menu_input() );
		
		//Return the state of given menu option
		return _return_sub_state( state );
	}
	
	const emenu_state cmain_state::_read_menu_input()
	{
		gui::cmenu menu( emenu_option, 3 );
		const emenu_state state = static_cast<const emenu_state>(  menu.result() );
		return state;
	}
	
	state::cstate* cmain_state::_return_sub_state( const emenu_state& state )
	{
		
		switch( state )
		{
			case menu_play:
				return _return_run_state( ); 
			case menu_help:{
				std::cout << "cmain_state - help not implemented." << std::endl;
				return nullptr;
			}
			case menu_exit:
				return nullptr;
		}
		
		return nullptr;
	}
	
	state::cstate* cmain_state::_return_run_state()
	{
		p_run_state->initialize( );
		return p_run_state;
	}
	
}