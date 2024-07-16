#pragma once
#include <assert.h>
#include <unistd.h>

namespace utils
{
using namespace std;

// 强制ROOT权限
class AssertRootPriority
{
public:
    AssertRootPriority(){
        const uid_t rootUid{};// Root用法的UID总是为0
        assert(getuid() == rootUid);
    }
};

}//namespace utils
