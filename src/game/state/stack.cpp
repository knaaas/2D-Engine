#include "stack.h"

namespace State
{
	void CStack::Run( CState& state ){
						
		CState *active = &state;
		LOG("state::cstack::run - begin" );
		
		//If there are any sub states
		while( active ){
		
			LOG("Running active: " << active );	
			//Run it and grab next sub state
			CState *sub_state = active->Run();
			
			//If any substate. Push the current state
			if( sub_state ){
				LOG( "Pushing active state.");
				m_state.push( active );
			}
			//Otherwise pop previous state
			else if( !m_state.empty() ){
				LOG( "Poping previous state");
				sub_state = m_state.top();
				m_state.pop();
			}
			
			//Make the new state active
			active = sub_state;
		}
		LOG("state::cstack::run - end");
	}
}
