<% render(instance) %>
<%= includes(0..x) %>

#include <boost/hana/foldable.hpp>


template <int> struct x { };

int main() {
    auto go = boost::hana::length(
        <%= list(
            (0..x).map { |i| "x<#{i}>" },
            (0..x).map { |i| "x<#{i}>{}" }
        ) %>
    );
}
