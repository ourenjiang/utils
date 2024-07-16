#pragma once
#include "cpphttplib_splitout/httplib.h"
#include "json/json.h"

namespace http_wrapper
{
using namespace std;
using namespace httplib;

httplib::Server& getServerSingleton();
void respond(Response &res, const Json::Value data);

}//namespace http_wrapper
