#include "status_code.h"

#include <unordered_map>

const std::map<fi::web::e_status_code, std::string>& fi::web::get_status_code_string( )
{
	static const std::map<e_status_code, std::string> status_code_strings = {
		{e_status_code::_unknown, "[ 0 ]: Unknown status"},
		{e_status_code::_information_continue, "[ 100 ]: Continue"},
		{e_status_code::_information_switching_protocols, "[ 101 ]: Switching Protocols"},
		{e_status_code::_information_processing, "[ 102 ]: Processing"},
		{e_status_code::_success_ok, "[ 200 ]: OK"},
		{e_status_code::_success_created, "[ 201 ]: Created"},
		{e_status_code::_success_accepted, "[ 202 ]: Accepted"},
		{e_status_code::_success_non_authoritative_information, "[ 203 ]: Non-Authoritative Information"},
		{e_status_code::_success_no_content, "[ 204 ]: No Content"},
		{e_status_code::_success_reset_content, "[ 205 ]: Reset Content"},
		{e_status_code::_success_partial_content, "[ 206 ]: Partial Content"},
		{e_status_code::_success_multi_status, "[ 207 ]: Multi-Status"},
		{e_status_code::_success_already_reported, "[ 208 ]: Already Reported"},
		{e_status_code::_success_im_used, "[ 226 ]: IM Used"},
		{e_status_code::_redirection_multiple_choices, "[ 300 ]: Multiple Choices"},
		{e_status_code::_redirection_moved_permanently, "[ 301 ]: Moved Permanently"},
		{e_status_code::_redirection_found, "[ 302 ]: Found"},
		{e_status_code::_redirection_see_other, "[ 303 ]: See Other"},
		{e_status_code::_redirection_not_modified, "[ 304 ]: Not Modified"},
		{e_status_code::_redirection_use_proxy, "[ 305 ]: Use Proxy"},
		{e_status_code::_redirection_switch_proxy, "[ 306 ]: Switch Proxy"},
		{e_status_code::_redirection_temporary_redirect, "[ 307 ]: Temporary Redirect"},
		{e_status_code::_redirection_permanent_redirect, "[ 308 ]: Permanent Redirect"},
		{e_status_code::_client_error_bad_request, "[ 400 ]: Bad Request"},
		{e_status_code::_client_error_unauthorized, "[ 401 ]: Unauthorized"},
		{e_status_code::_client_error_payment_required, "[ 402 ]: Payment Required"},
		{e_status_code::_client_error_forbidden, "[ 403 ]: Forbidden"},
		{e_status_code::_client_error_not_found, "[ 404 ]: Not Found"},
		{e_status_code::_client_error_method_not_allowed, "[ 405 ]: Method Not Allowed"},
		{e_status_code::_client_error_not_acceptable, "[ 406 ]: Not Acceptable"},
		{e_status_code::_client_error_proxy_authentication_required, "[ 407 ]: Proxy Authentication Required"},
		{e_status_code::_client_error_request_timeout, "[ 408 ]: Request Timeout"},
		{e_status_code::_client_error_conflict, "[ 409 ]: Conflict"},
		{e_status_code::_client_error_gone, "[ 410 ]: Gone"},
		{e_status_code::_client_error_length_required, "[ 411 ]: Length Required"},
		{e_status_code::_client_error_precondition_failed, "[ 412 ]: Precondition Failed"},
		{e_status_code::_client_error_payload_too_large, "[ 413 ]: Payload Too Large"},
		{e_status_code::_client_error_uri_too_long, "[ 414 ]: URI Too Long"},
		{e_status_code::_client_error_unsupported_media_type, "[ 415 ]: Unsupported Media Type"},
		{e_status_code::_client_error_range_not_satisfiable, "[ 416 ]: Range Not Satisfiable"},
		{e_status_code::_client_error_expectation_failed, "[ 417 ]: Expectation Failed"},
		{e_status_code::_client_error_im_a_teapot, "[ 418 ]: I'm a teapot"},
		{e_status_code::_client_error_misdirection_required, "[ 421 ]: Misdirected Request"},
		{e_status_code::_client_error_unprocessable_entity, "[ 422 ]: Unprocessable Entity"},
		{e_status_code::_client_error_locked, "[ 423 ]: Locked"},
		{e_status_code::_client_error_failed_dependency, "[ 424 ]: Failed Dependency"},
		{e_status_code::_client_error_upgrade_required, "[ 426 ]: Upgrade Required"},
		{e_status_code::_client_error_precondition_required, "[ 428 ]: Precondition Required"},
		{e_status_code::_client_error_too_many_requests, "[ 429 ]: Too Many Requests"},
		{e_status_code::_client_error_request_header_fields_too_large, "[ 431 ]: Request Header Fields Too Large"},
		{e_status_code::_client_error_unavailable_for_legal_reasons, "[ 451 ]: Unavailable For Legal Reasons"},
		{e_status_code::_server_error_internal_server_error, "[ 500 ]: Internal Server Error"},
		{e_status_code::_server_error_not_implemented, "[ 501 ]: Not Implemented"},
		{e_status_code::_server_error_bad_gateway, "[ 502 ]: Bad Gateway"},
		{e_status_code::_server_error_service_unavailable, "[ 503 ]: Service Unavailable"},
		{e_status_code::_server_error_gateway_timeout, "[ 504 ]: Gateway Timeout"},
		{e_status_code::_server_error_http_version_not_supported, "[ 505 ]: HTTP Version Not Supported"},
		{e_status_code::_server_error_variant_also_negotiates, "[ 506 ]: Variant Also Negotiates"},
		{e_status_code::_server_error_insufficient_storage, "[ 507 ]: Insufficient Storage"},
		{e_status_code::_server_error_loop_detected, "[ 508 ]: Loop Detected"},
		{e_status_code::_server_error_not_extended, "[ 510 ]: Not Extended"},
		{e_status_code::_server_error_network_authentication_required, "[ 511 ]: Network Authentication Required"} };
	return status_code_strings;
}

class c_string_to_status_code : public std::unordered_map<std::string, fi::web::e_status_code>
{
public:
	c_string_to_status_code( )
	{
		for ( auto const& [status_code, string] : fi::web::get_status_code_string( ) )
			emplace( string.substr( 0, 3 ), status_code );
	}
};

fi::web::e_status_code fi::web::get_status_code( std::string const& status_code_string ) noexcept
{
	if ( status_code_string.size( ) < 3 )
		return e_status_code::_unknown;

	auto const number = status_code_string.substr( 0, 3 );
	if ( number[ 0 ] < '0' || number[ 0 ] > '9' || number[ 1 ] < '0' || number[ 1 ] > '9' || number[ 2 ] < '0' || number[ 2 ] > '9' )
		return e_status_code::_unknown;

	static c_string_to_status_code string_to_status_code;

	auto const pos = string_to_status_code.find( number );
	if ( pos == string_to_status_code.end( ) )
		return static_cast< e_status_code >( atoi( number.c_str( ) ) );

	return pos->second;
}

const std::string& fi::web::get_status_code( e_status_code const status_code_enum ) noexcept
{
	auto const pos = get_status_code_string( ).find( status_code_enum );
	if ( pos == get_status_code_string( ).end( ) )
	{
		static std::string empty_string;
		return empty_string;
	}

	return pos->second;
}
