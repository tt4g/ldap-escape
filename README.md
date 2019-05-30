# ldap-escape

Escape ldap special characters.

## Requirements

CMake, conan

## Build and Test

```bash
$ mkdir build
$ cd build
$ cmake ../
$ cmake --build .
$ ctest --output-on-failure
```

## Usage

```cpp
#include <ldap/escape.hpp>

#include <string>

int main(int argc, args** argv)
{
    using namespace tt4g;

    // Escape distinguished names (RFC 4514).
    std::string dn = "dc=" + ldap::escapeName(" <Hello!> "); 

    // Escape search filter (RFC 4515).
    std::string filter = 
        "(&(uid=" + ldap::escapeFilter("*)(|(objectClass=*)")
        + ")(userPassword=" + ldap::escapeFilter("*") + "))";

    return 0;
}
```
