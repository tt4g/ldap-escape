#include "ldap/escape.hpp"

namespace tt4g
{
namespace ldap
{

std::string escape(std::string_view source)
{
    // TODO: implements escape ldap filter strings, and other search pattern.
    return std::string(source);
}

} // namespace ldap
} // namespace tt4g
