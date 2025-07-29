#pragma once
#include "yaml-cpp/yaml.h"

class Yaml
{
 public:
 static void saveFile(YAML::Node& data, const std::string& filename);

};
