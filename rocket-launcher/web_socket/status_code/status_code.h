#pragma once
#include <map>
#include <string>

namespace fi::web
{
	enum class e_status_code
	{
		_unknown = 0,
		_information_continue = 100,
		_information_switching_protocols,
		_information_processing,
		_success_ok = 200,
		_success_created,
		_success_accepted,
		_success_non_authoritative_information,
		_success_no_content,
		_success_reset_content,
		_success_partial_content,
		_success_multi_status,
		_success_already_reported,
		_success_im_used = 226,
		_redirection_multiple_choices = 300,
		_redirection_moved_permanently,
		_redirection_found,
		_redirection_see_other,
		_redirection_not_modified,
		_redirection_use_proxy,
		_redirection_switch_proxy,
		_redirection_temporary_redirect,
		_redirection_permanent_redirect,
		_client_error_bad_request = 400,
		_client_error_unauthorized,
		_client_error_payment_required,
		_client_error_forbidden,
		_client_error_not_found,
		_client_error_method_not_allowed,
		_client_error_not_acceptable,
		_client_error_proxy_authentication_required,
		_client_error_request_timeout,
		_client_error_conflict,
		_client_error_gone,
		_client_error_length_required,
		_client_error_precondition_failed,
		_client_error_payload_too_large,
		_client_error_uri_too_long,
		_client_error_unsupported_media_type,
		_client_error_range_not_satisfiable,
		_client_error_expectation_failed,
		_client_error_im_a_teapot,
		_client_error_misdirection_required = 421,
		_client_error_unprocessable_entity,
		_client_error_locked,
		_client_error_failed_dependency,
		_client_error_upgrade_required = 426,
		_client_error_precondition_required = 428,
		_client_error_too_many_requests,
		_client_error_request_header_fields_too_large = 431,
		_client_error_unavailable_for_legal_reasons = 451,
		_server_error_internal_server_error = 500,
		_server_error_not_implemented,
		_server_error_bad_gateway,
		_server_error_service_unavailable,
		_server_error_gateway_timeout,
		_server_error_http_version_not_supported,
		_server_error_variant_also_negotiates,
		_server_error_insufficient_storage,
		_server_error_loop_detected,
		_server_error_not_extended = 510,
		_server_error_network_authentication_required
	};

	[[nodiscard]] const std::map<e_status_code, std::string>& get_status_code_string( );

	[[nodiscard]] e_status_code get_status_code( std::string const& status_code_string ) noexcept;

	[[nodiscard]] const std::string& get_status_code( e_status_code status_code_enum ) noexcept;
}
