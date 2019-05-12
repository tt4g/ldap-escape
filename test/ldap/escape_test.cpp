#include "ldap/escape.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace tt4g
{
namespace ldap
{

GTEST_TEST(LdapEscapeTest, EscapeName)
{
    std::string fixture = " #<foo>=\"\\\",;+";
    fixture.push_back('\00'); // NUL
    fixture.push_back(' '); // last space

    std::string expected = R"EOS(\ \#\<foo\>\=\"\\\"\,\;\+\00\ )EOS";

    std::string actual = escapeName(fixture);

    EXPECT_THAT(actual, testing::StrEq(expected));
}

GTEST_TEST(LdapEscapeTest, EscapeFilter)
{
    std::string fixture = "(\\foo*)";
    fixture.push_back('\00'); // NUL
    fixture.append("bar");
    std::string expected = R"EOS(\28\5Cfoo\2A\29\00bar)EOS";

    std::string actual = escapeFilter(fixture);

    EXPECT_THAT(actual, testing::StrEq(expected));
}

} // namespace ldap
} // namespace tt4g
