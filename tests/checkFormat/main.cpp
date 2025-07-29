#include "utils/Yaml.h"
#include <fstream>

int main(int argc, char **argv)
{
    const std::string srcFile(argv[1]);
    const std::string dstFile(argv[2]);

    YAML::Node srcNode = YAML::LoadFile(srcFile);

    // 设置缩进
    YAML::Emitter emitter;
    emitter.SetIndent(2); // 设置为 2 空格缩进
    emitter.SetMapFormat(YAML::Block);
    emitter << srcNode;   // 输出节点

    // Yaml::saveFile(srcNode, dstFile);
    // 写入文件
    std::ofstream fout(dstFile);
    fout << emitter.c_str();
}
