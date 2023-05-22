#include "activation_function.h"
#include "predefined.h"

#include <stdexcept>

namespace model {
ActivationFunction AFFabric(AFType type) {
    switch (type) {
        case AFType::Sigmoid:
            return Sigmoid();
        case AFType::ReLU:
            return ReLU();
        case AFType::Lineral:
            return Lineral();
        case AFType::SoftMax:
            return SoftMax();
        default:
            throw std::runtime_error("AFFabric: incorrect AFType");
    }
}
}  // namespace model