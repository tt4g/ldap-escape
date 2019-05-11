#ifndef LDAP_ESCAPE_HPP_
#define LDAP_ESCAPE_HPP_

#include <string>
#include <string_view>

namespace tt4g
{
namespace ldap
{

std::string escape(std::string_view soruce);

} // namespace ldap
} // namespace tt4g

#endif // LDAP_ESCAPE_HPP_
