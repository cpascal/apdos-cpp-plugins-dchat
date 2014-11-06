#include "kernel.h"

using namespace apdos::kernel;

Kernel::Kernel() {
}

Kernel::~Kernel() {
}

boost::shared_ptr<Kernel> Kernel::get_instance() {
  static boost::shared_ptr<Kernel> instance = boost::shared_ptr<Kernel>(new Kernel());
  return instance;
}
