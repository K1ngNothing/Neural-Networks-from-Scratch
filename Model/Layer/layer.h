#pragma once

#include <ActivationFunction/activation_function.h>
#include <definitions.h>

namespace model {

class Layer {
public:
    Layer(size_t input_size, size_t output_size, const ActivationFunction& sigma);

public:
    Vector PushVector(const Vector& x);
    Vector PushVector(const Vector& x) const;
    RowVector PushGradient(const RowVector& u) const;
    void UpdateDelta(const RowVector& u, double modifier);
    void ApplyChanges();

private:
    Matrix A_;  // Lineral paramethers of Layer
    Vector b_;
    ActivationFunction sigma_ = Sigmoid();  // Non-lineral paramether of Layer

    Vector last_input_;

    Matrix delta_A_;
    Vector delta_b_;
};

}  // namespace model