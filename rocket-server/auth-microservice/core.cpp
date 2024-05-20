#include <userver/utest/using_namespace_userver.hpp>

#include <userver/components/minimal_server_component_list.hpp>
#include <userver/utils/daemon_run.hpp>

#include "web_socket/web_socket.h"


int main( int const argc, const char* const argv[] )
{
	auto const component_list = components::MinimalServerComponentList( )
		.Append<fi::c_web_socket>( );
	
	return utils::DaemonMain( argc, argv, component_list );
}
