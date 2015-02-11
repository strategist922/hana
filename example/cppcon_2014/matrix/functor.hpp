/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_EXAMPLE_CPPCON_2014_MATRIX_FUNCTOR_HPP
#define BOOST_HANA_EXAMPLE_CPPCON_2014_MATRIX_FUNCTOR_HPP

#include "matrix.hpp"

#include <boost/hana/core/models.hpp>
#include <boost/hana/detail/std/integral_constant.hpp>
#include <boost/hana/functional/flip.hpp>
#include <boost/hana/functional/partial.hpp>
#include <boost/hana/functor.hpp>

#include <utility>


namespace boost { namespace hana {
    template <unsigned Rows, unsigned Columns>
    struct models<Functor(cppcon::Matrix<Rows, Columns>)>
        : detail::std::true_type
    { };

    template <unsigned Rows, unsigned Columns>
    struct transform_impl<cppcon::Matrix<Rows, Columns>> {
        template <typename M, typename F>
        static constexpr decltype(auto) apply(M&& m, F&& f) {
            return unpack(
                transform(
                    cppcon::rows(std::forward<M>(m)),
                    partial(flip(transform), std::forward<F>(f))
                ),
                cppcon::matrix
            );
        }
    };
}}

#endif // !BOOST_HANA_EXAMPLE_CPPCON_2014_MATRIX_FUNCTOR_HPP
