#include "cf.h"

template <typename T>
estimators::complimentary_filter::CF<T>::CF()
{
}

template <typename T>
estimators::complimentary_filter::CF<T>::~CF()
{
}

template <typename T>
void estimators::complimentary_filter::CF<T>::init(T fc_, T dt_)
{
    set_param(fc_, dt_);
}

template <typename T>
void estimators::complimentary_filter::CF<T>::set_param(T fc_, T dt_)
{
    fc = fc_;
    dt = dt_;
    tau = 1.0 / (6.28318530717958647692528676655900576 * fc);
    alpha = dt / (dt + tau);
}

template <typename T>
T estimators::complimentary_filter::CF<T>::update(T x1_i, T x2_i)
{
    return alpha * x1_i + (1.0 - alpha) * x2_i;
}

template <typename T>
void estimators::complimentary_filter::CF<T>::reset()
{
}

template <typename T>
void estimators::complimentary_filter::CF<T>::set_fc(T fc_)
{
    set_param(fc_, dt);
}

template <typename T>
void estimators::complimentary_filter::CF<T>::set_tau(T tau_)
{
    tau = tau_;
    fc = 1.0 / (6.28318530717958647692528676655900576 * tau);
    alpha = dt / (dt + tau);
}

template <typename T>
void estimators::complimentary_filter::CF<T>::set_dt(T dt_)
{
    set_param(fc, dt_);
}

template <typename T>
void estimators::complimentary_filter::CF<T>::set_alpha(T alpha_)
{
    alpha = alpha_;
    tau = ((1.0 - alpha) * dt) / alpha;
    fc = 1.0 / (6.28318530717958647692528676655900576 * tau);
}

template <typename T>
T estimators::complimentary_filter::CF<T>::get_fc()
{
    return fc;
}

template <typename T>
T estimators::complimentary_filter::CF<T>::get_tau()
{
    return tau;
}

template <typename T>
T estimators::complimentary_filter::CF<T>::get_dt()
{
    return dt;
}

template <typename T>
T estimators::complimentary_filter::CF<T>::get_alpha()
{
    return alpha;
}
