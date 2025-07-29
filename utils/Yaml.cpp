#include "utils/Yaml.h"
#include <fstream>

void Yaml::saveFile(YAML::Node &data, const std::string &filename)
{
    // out put file, and make sure write immediately.
    std::ofstream fout(filename);
    fout << data << '\n';
    fout << '\n'; /* must have one empty line */
    fout.flush();
    fout.close();
}
