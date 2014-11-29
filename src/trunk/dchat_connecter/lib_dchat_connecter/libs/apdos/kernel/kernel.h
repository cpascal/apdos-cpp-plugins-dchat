#ifndef APDOS_KERNEL_KERNEL_H
#define APDOS_KERNEL_KERNEL_H

#include <boost/shared_ptr.hpp>
#include <map>
#include <libs/apdos/kernel/node.h>
#include <libs/apdos/kernel/null_node.h>

namespace apdos {
  namespace kernel {
    class Kernel {
    public:
      Kernel();
      virtual ~Kernel();

      template <class T>        
      boost::shared_ptr<T> new_object(std::string path) {
        boost::shared_ptr<T> result(new T(path));
        nodes[path] = result;
        return result;
      }

      /* 
      template <class T>
      boost::shared_ptr<T> lookup(std::string path) {
        //boost::shared_ptr<T> result = dynamic_cast<boost::shared_ptr<T>>(this->nodes[path]);
        std::map<std::string, boost::shared_ptr<apdos::kernel::Node>>::iterator element = this->nodes.find(path);
        if (element == nodes.end()) {
          boost::shared_ptr<apdos::kernel::Null_Node> null_node = boost::shared_ptr<apdos::kernel::Null_Node>(new apdos::kernel::Null_Node());
          return boost::static_pointer_cast<T>(null_node);
        }
        return boost::static_pointer_cast<T>(element->second);
      }
      */

      boost::shared_ptr<apdos::kernel::Node> lookup(std::string path) {
        std::map<std::string, boost::shared_ptr<apdos::kernel::Node>>::iterator element = this->nodes.find(path);
        if (element == nodes.end()) {
          return boost::shared_ptr<apdos::kernel::Null_Node>(new apdos::kernel::Null_Node());
        }
        return element->second;
      }

    private:
      std::map<std::string, boost::shared_ptr<apdos::kernel::Node>> nodes;

    public:
      static boost::shared_ptr<Kernel> get_instance();
    };
  }
}

#endif//APDOS_KERNEL_KERNEL_H