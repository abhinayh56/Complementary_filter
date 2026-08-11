/**
 * @file cf.h
 * @author Abhinay Kumar
 * @brief Declaration of the complementary filter class.
 *
 * @details
 * This file defines the @ref estimators::cf::CF class, which implements
 * a complementary filter for sensor fusion.
 *
 * A complementary filter combines measurements from different sensors
 * by exploiting their complementary frequency characteristics. For
 * example, a low-frequency measurement from one sensor can be combined
 * with a high-frequency measurement from another sensor to obtain a
 * more stable estimate.
 *
 * The filter parameters are defined by the cutoff frequency, time step,
 * time constant, and filter coefficient.
 *
 * @version 1.0
 * @date 2026-08-11
 *
 * @copyright
 * Copyright (c) 2026 Abhinay Kumar
 */

#ifndef ESTIMATORS_COMPLIMENTARY_FILTER
#define ESTIMATORS_COMPLIMENTARY_FILTER

namespace estimators
{
    /**
     * @namespace estimators
     * @brief Contains estimation and sensor-fusion algorithms.
     */

    namespace cf
    {
        /**
         * @namespace cf
         * @brief Contains the complementary filter implementation.
         */

        /**
         * @class CF
         * @brief Generic complementary filter for sensor fusion.
         *
         * @details
         * The CF class implements a first-order complementary filter that
         * combines two input measurements into a single filtered output.
         *
         * The filter can be configured using either the cutoff frequency
         * and sampling time or directly using the filter parameters.
         *
         * The class is templated so that the filter can operate on different
         * numeric types such as @c float or @c double.
         *
         * @tparam T Numeric data type used for the filter calculations.
         *
         * @par Typical usage
         * @code{.cpp}
         * estimators::cf::CF<double> filter;
         *
         * filter.init(2.5, 0.006);
         *
         * double output = filter.update(x1, x2);
         * @endcode
         */
        template <typename T>
        class CF
        {
        public:
            /**
             * @brief Constructs a complementary filter.
             *
             * @details
             * The filter parameters are initialized to zero. Use
             * @ref init() or the individual setter functions to configure
             * the filter before using @ref update().
             */
            CF();

            /**
             * @brief Destroys the complementary filter.
             */
            ~CF();

            /**
             * @brief Initializes the complementary filter.
             *
             * @param[in] fc_ Cutoff frequency of the filter.
             * @param[in] dt_ Sampling time or control-loop period.
             *
             * @details
             * This function initializes the filter parameters using the
             * specified cutoff frequency and sampling time.
             */
            void init(T fc_, T dt_);

            /**
             * @brief Sets the filter parameters.
             *
             * @param[in] fc_ Cutoff frequency of the filter.
             * @param[in] dt_ Sampling time or control-loop period.
             *
             * @details
             * This function configures the cutoff frequency and sampling
             * time of the complementary filter.
             */
            void set_param(T fc_, T dt_);

            /**
             * @brief Updates the complementary filter with new measurements.
             *
             * @param[in] x1_i First sensor measurement.
             * @param[in] x2_i Second sensor measurement.
             *
             * @return Filtered or fused output.
             *
             * @details
             * Combines the two input measurements according to the
             * complementary filter equation and updates the internal
             * filter state.
             */
            T update(T x1_i, T x2_i);

            /**
             * @brief Resets the filter state.
             *
             * @details
             * Resets the internal state of the filter to its initial
             * condition.
             */
            void reset();

            /**
             * @brief Sets the cutoff frequency.
             *
             * @param[in] fc_ Cutoff frequency of the filter.
             */
            void set_fc(T fc_);

            /**
             * @brief Sets the filter time constant.
             *
             * @param[in] tau_ Time constant of the filter.
             */
            void set_tau(T tau_);

            /**
             * @brief Sets the sampling time.
             *
             * @param[in] dt_ Sampling time or control-loop period.
             */
            void set_dt(T dt_);

            /**
             * @brief Sets the complementary filter coefficient.
             *
             * @param[in] alpha_ Complementary filter coefficient.
             */
            void set_alpha(T alpha_);

            /**
             * @brief Gets the cutoff frequency.
             *
             * @return Current cutoff frequency.
             */
            T get_fc();

            /**
             * @brief Gets the filter time constant.
             *
             * @return Current filter time constant.
             */
            T get_tau();

            /**
             * @brief Gets the sampling time.
             *
             * @return Current sampling time or control-loop period.
             */
            T get_dt();

            /**
             * @brief Gets the complementary filter coefficient.
             *
             * @return Current complementary filter coefficient.
             */
            T get_alpha();

        private:
            /**
             * @brief Cutoff frequency of the filter.
             */
            T fc = 0.0;

            /**
             * @brief Time constant of the filter.
             */
            T tau = 0.0;

            /**
             * @brief Sampling time or control-loop period.
             */
            T dt = 0.0;

            /**
             * @brief Complementary filter coefficient.
             */
            T alpha = 0.0;
        };

#include "CF.tpp"

    } // namespace cf

} // namespace estimators

#endif // ESTIMATORS_COMPLIMENTARY_FILTER