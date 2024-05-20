#pragma once
#include <userver/server/websocket/websocket_handler.hpp>

namespace fi
{
	class c_web_socket final : public server::websocket::WebsocketHandlerBase
	{
	public:
		using WebsocketHandlerBase::WebsocketHandlerBase;

		void Handle( server::websocket::WebSocketConnection& client, server::request::RequestContext& ) const override
		{
			server::websocket::Message message;
			while ( !engine::current_task::ShouldCancel( ) )
			{

			}
			if ( message.close_status )
				client.Close( *message.close_status );
		}
	};
}