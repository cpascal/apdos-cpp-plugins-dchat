#ifndef APDOS_KERNEL_KERNEL_H
#define APDOS_KERNEL_KERNEL_H

#include <boost/shared_ptr.hpp>

namespace apdos {
  namespace kernel {
    class Kernel {
      public:
        Kernel();
        virtual ~Kernel();

        template <class T>        
        boost::shared_ptr<T> new_object(std::string path) {
          boost::shared_ptr<T> result(new T(path));
          return result;
        }

      public:
        static boost::shared_ptr<Kernel> get_instance();
    };
  }
}

#endif //APDOS_KERNEL_KERNEL_H