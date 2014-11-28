#ifndef APDOS_KERNEL_KERNEL_H
#define APDOS_KERNEL_KERNEL_H

#include <boost/shared_ptr.hpp>
#include <map>
#include <libs/apdos/kernel/actor/actor.h>

namespace apdos {
  namespace kernel {
    class Kernel {
    public:
      Kernel();
      virtual ~Kernel();

      template <class T>        
      boost::shared_ptr<T> new_object(std::string path) {
        boost::shared_ptr<T> result(new T(path));
        actors[path] = result;
        return result;
      }

      boost::shared_ptr<apdos::kernel::actor::Actor> lookup(std::string path);

    private:
      std::map<std::string, boost::shared_ptr<apdos::kernel::actor::Actor>> actors;

    public:
      static boost::shared_ptr<Kernel> get_instance();
    };
  }
}

#endif//APDOS_KERNEL_KERNEL_H