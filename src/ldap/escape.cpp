#include "ldap/escape.hpp"

namespace tt4g
{
namespace ldap
{

std::string escapeName(std::string_view name)
{
    using sizeType = decltype(name)::size_type;

    if (name.empty()) {
        return "";
    }

    std::string dest;
    const sizeType nameSize = name.size();
    const sizeType last = nameSize - 1;
    dest.reserve(name.size() * 2);

    for (sizeType i = 0; i < nameSize; ++i) {

        char nameChar = name[i];

        if (nameChar == '\x20') {
            if (i == 0 || i == last) {
                // found space at first or last position.
                dest.append("\\\x20");

                continue;
            }
        }

        switch (nameChar) {
            // Control characters bellow 0x20.
            case '\x00': // NUL
                dest.append("\\00");
                break;
            case '\x01': // SOH
                dest.append("\\01");
                break;
            case '\x02': // STX
                dest.append("\\02");
                break;
            case '\x03': // ETX
                dest.append("\\03");
                break;
            case '\x04': // EOT
                dest.append("\\04");
                break;
            case '\x05': // ENQ
                dest.append("\\05");
                break;
            case '\x06': // ACK
                dest.append("\\06");
                break;
            case '\x07': // BEL
                dest.append("\\07");
                break;
            case '\x08': // BS
                dest.append("\\08");
                break;
            case '\x09': // HT
                dest.append("\\09");
                break;
            case '\x0A': // LF
                dest.append("\\0A");
                break;
            case '\x0B': // VT
                dest.append("\\0B");
                break;
            case '\x0C': // FF
                dest.append("\\0C");
                break;
            case '\x0D': // CR
                dest.append("\\0D");
                break;
            case '\x0E': // SO
                dest.append("\\0E");
                break;
            case '\x0F': // SI
                dest.append("\\0F");
                break;
            case '\x10': // DLE
                dest.append("\\10");
                break;
            case '\x11': // DC1
                dest.append("\\11");
                break;
            case '\x12': // DC2
                dest.append("\\12");
                break;
            case '\x13': // DC3
                dest.append("\\13");
                break;
            case '\x14': // DC4
                dest.append("\\14");
                break;
            case '\x15': // NAK
                dest.append("\\15");
                break;
            case '\x16': // SYN
                dest.append("\\16");
                break;
            case '\x17': // ETB
                dest.append("\\17");
                break;
            case '\x18': // CAN
                dest.append("\\18");
                break;
            case '\x19': // EM
                dest.append("\\19");
                break;
            case '\x1A': // SUB
                dest.append("\\1A");
                break;
            case '\x1B': // ESC
                dest.append("\\1B");
                break;
            case '\x1C': // FS
                dest.append("\\1C");
                break;
            case '\x1D': // GS
                dest.append("\\1D");
                break;
            case '\x1E': // RS
                dest.append("\\1E");
                break;
            case '\x1F': // US
                dest.append("\\1F");
                break;
            // Name special characters.
            case '\x23': // #
                dest.append("\\#");
                break;
            case '\x2C': // ,
                dest.append("\\,");
                break;
            case '\x3B': // ;
                dest.append("\\;");
                break;
            case '\x3D': // =
                dest.append("\\=");
                break;
            case '\x2B': // +
                dest.append("\\+");
                break;
            case '\x3C': // <
                dest.append("\\<");
                break;
            case '\x3E': // >
                dest.append("\\>");
                break;
            case '\x22': // "
                dest.append("\\\"");
                break;
            case '\x5C': // backslash "\"
                dest.append("\\\\");
                break;
            // no escape.
            default:
                dest.push_back(nameChar);
                break;
        }
    }

    return dest;
}

std::string escapeFilter(std::string_view filter)
{
    using sizeType = decltype(filter)::size_type;

    if (filter.empty()) {
        return "";
    }

    std::string dest;
    dest.reserve(filter.size() * 2);

    for (const auto& filterChar : filter) {
        switch (filterChar) {
            case '\x2A': // *
                dest.append("\\2A");
                break;
            case '\x28': // (
                dest.append("\\28");
                break;
            case '\x29': // )
                dest.append("\\29");
                break;
            case '\x5C': // backslash "\"
                dest.append("\\5C");
                break;
            case '\x00': // NUL
                dest.append("\\00");
                break;
            default:
                dest.push_back(filterChar);
                break;
        }
    }

    return dest;
}

} // namespace ldap
} // namespace tt4g
