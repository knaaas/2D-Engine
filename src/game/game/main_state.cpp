#include "main_state.h"

namespace Game
{
	
	
	const char *emenu_option[] = {
		"play",
		"help",
		"exit"
	};
	const size_t emenu_option_count = 3;
	
	CMainState::CMainState() 
	{
		p_run_state = new CRunState();
		assert( p_run_state );
	}
	
	CMainState::~CMainState()
	{
		delete p_run_state;
	}
	
	State::CState::SReturn CMainState::Run()
	{
		//Read selected menu option
		const EMenuState state( ReadMenuInput() );
		
		//Return the state of given menu option
		return State::CState::SReturn( ReturnSubState(state) );
	}
	
	const EMenuState CMainState::ReadMenuInput()
	{
		GUI::CMenu menu( emenu_option, emenu_option_count );
		const EMenuState state = static_cast<const EMenuState>(  menu.Result() );
		return state;
	}
	
	State::CState* CMainState::ReturnSubState( const EMenuState& state )
	{
		switch( state )
		{
			case menu_play:
				return ReturnRunState( ); 
			case menu_help:{
				std::cout << "cmain_state - help not implemented." << std::endl;
				return nullptr;
			}
			case menu_exit:
				return nullptr;
		}
		
		return nullptr;
	}
	
	State::CState* CMainState::ReturnRunState()
	{
		p_run_state->Initialize( );
		return p_run_state;
	}
}
