#pragma once
#include "yaml-cpp/yaml.h"

namespace yaml_wrapper
{
using namespace std;

class YamlWrapper
{
public:

    /**
     * @brief 加载yaml文件
     * @return void
     * @exception YAML::BadConversion
    */
    static void load(const string& filename){
        try{
            root_ = YAML::LoadFile(filename);
        }
        catch(YAML::BadConversion& e){
            throw e;// 不处理,继续向外抛出
        }
    }

    /**
     * @brief 获取已加载的yaml根对象
     * @return YAML::Node引用
     * @exception NoThrow
    */
    static YAML::Node& getRoot(){ return root_; }
private:
    inline static YAML::Node root_;
};

}//namespace yaml_wrapper
