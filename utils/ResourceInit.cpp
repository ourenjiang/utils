#include "ResourceInit.h"
#include "utils/CommandlineParams.h"
#include "utils/YamlWrapper.hpp"
#include "utils/LogWrapper.h"
#include "boost/assert.hpp"
#include <iostream>

using namespace std;
using namespace utils;

void utils::commandlineParamsInit(int argc, char **argv)
{
    CommandlineParams::init(argc, argv);
    auto& variablesMap = CommandlineParams::getVariablesMap();
    if(variablesMap.find("help") != variablesMap.end())
    {
        cout << CommandlineParams::getHelpInfo() << endl;
        quick_exit(0);
    }
}

void utils::configurationInit()
{
    auto& variablesMap = CommandlineParams::getVariablesMap();
    auto result = variablesMap.find("configure");
    BOOST_ASSERT(result != variablesMap.end());
    const string cfgPath = result->second.as<string>();
    yaml::Wrapper::load(cfgPath + "/config.yaml");
}

void utils::configurationInitFromEnv()
{
try
{
    const string envName{ "PACEIC_EMS_SERVER" };
    const char* envValue = std::getenv(envName.c_str());
    if(!envValue){
        throw std::runtime_error("env variables 'PACEIC_EMS_SERVER' not set");
    }
    string filename(envValue);
    filename += "/etc/config.yaml";
    yaml::Wrapper::load(filename);
}
catch(const std::exception& e){
    std::cerr << e.what() << '\n';
    std::quick_exit(-1);
}
}

void utils::logInit()
{
    auto& cfgRoot = yaml::Wrapper::getRoot();
    const auto& logCfg = cfgRoot["logger"];
    vector<LogAttr> logAttrs;
    std::transform(logCfg.begin(), logCfg.end(), back_inserter(logAttrs), 
        [](const YAML::Node& attr){
        return make_tuple(
            attr["name"].as<string>(),
            attr["priority"].as<string>()
        );
    });
    const string rootPath = cfgRoot["global"]["rootPath"].as<string>();
    const string logPath = cfgRoot["global"]["logPath"].as<string>();
    LogWrapper::init(logAttrs, rootPath + logPath);
}
