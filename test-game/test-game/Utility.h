#pragma once

#include <vector>
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>

namespace util {
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;
    namespace phoenix = boost::phoenix;

    template <typename It>
    bool parse_CSV(It first, It last, std::vector<int>& v) {
        using qi::int_;
        using qi::phrase_parse;
        using qi::_1;
        using ascii::space;
        using phoenix::push_back;

        bool r = phrase_parse(first, last,
            (
                int_ % ','
            ),
            space, v);

		// fail if we did not get a full match
        if (first != last)
            return false;
        return r;
    }
}