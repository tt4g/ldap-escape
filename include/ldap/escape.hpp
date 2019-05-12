#ifndef LDAP_ESCAPE_HPP_
#define LDAP_ESCAPE_HPP_

#include <string>
#include <string_view>

namespace tt4g
{
namespace ldap
{

/**
 * @brief Escape distinguished names.
 *
 * Escape distinguished names (RFC 4514), returns new std::string.
 * Escapes: '#' (0x23), ',' (0x2C), ';' (0x3B), '=' (0x3D), '+' (0x2B),
 * '<' (0x3C), '>' (0x3E), '"' (0x22), '\' (0x5C),
 * and control characters 0x00 ~ 0x19, [space] (0x20) at first or last position.
 *
 * @param name source.
 * @return std::string destination.
 */
std::string escapeName(std::string_view name);

/**
 * @brief Escape search filter.
 *
 * Escape search filter (RFC 4515), returns new std::string.
 * Escapes: '*' (0x2A), '(' (0x28), ')' (0x29), '\' (0x5C), [NUL] (0x00).
 *
 * @param name source.
 * @return std::string destination.
 */
std::string escapeFilter(std::string_view filter);

} // namespace ldap
} // namespace tt4g

#endif // LDAP_ESCAPE_HPP_
