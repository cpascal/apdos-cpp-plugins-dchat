#ifndef APDOS_KERNEL_KERNEL_H
#define APDOS_KERNEL_KERNEL_H

#include <boost/shared_ptr.hpp>

namespace apdos {
  namespace kernel {
    class Kernel {
      public:
        Kernel();
        virtual ~Kernel();

      public:
        static boost::shared_ptr<Kernel> get_instance();
    };
  }
}

#endif //APDOS_KERNEL_KERNEL_H