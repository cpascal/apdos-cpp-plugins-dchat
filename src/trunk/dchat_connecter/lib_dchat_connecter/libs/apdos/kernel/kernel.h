#ifndef APDOS_KERNEL_KERNEL_H
#define APDOS_KERNEL_KERNEL_H

#include <boost/shared_ptr.hpp>
#include <map>
#include <libs/apdos/kernel/node.h>
#include <libs/apdos/kernel/null_node.h>

namespace apdos {
  namespace kernel {
    typedef boost::shared_ptr<apdos::kernel::Node> Node_Shared_Ptr;
    typedef boost::shared_ptr<apdos::kernel::Null_Node> Null_Node_Shared_Ptr;

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

      void delete_object(std::string path) {
        std::map<std::string, Node_Shared_Ptr>::iterator element = this->nodes.find(path);
        if (element != nodes.end()) {
          nodes.erase(element);
        }
      }

      /* 
      template <class T>
      boost::shared_ptr<T> lookup(std::string path) {
        //boost::shared_ptr<T> result = dynamic_cast<boost::shared_ptr<T>>(this->nodes[path]);
        std::map<std::string, Node_Shared_Ptr>::iterator element = this->nodes.find(path);
        if (element == nodes.end()) {
          Null_Node_Shared_Ptr null_node = Null_Node_Shared_Ptr(new apdos::kernel::Null_Node());
          return boost::static_pointer_cast<T>(null_node);
        }
        return boost::static_pointer_cast<T>(element->second);
      }
      */

      Node_Shared_Ptr lookup(std::string path) {
        std::map<std::string, Node_Shared_Ptr>::iterator element = this->nodes.find(path);
        if (element == nodes.end()) {
          return Null_Node_Shared_Ptr(new apdos::kernel::Null_Node());
        }
        return element->second;
      }

    private:
      std::map<std::string, Node_Shared_Ptr> nodes;

    public:
      static boost::shared_ptr<Kernel> get_instance();
    };
  }
}

#endif//APDOS_KERNEL_KERNEL_H