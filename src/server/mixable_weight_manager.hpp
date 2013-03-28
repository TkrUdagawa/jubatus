// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2011,2012 Preferred Infrastructure and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License version 2.1 as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef JUBATUS_SERVER_MIXABLE_WEIGHT_MANAGER_HPP_
#define JUBATUS_SERVER_MIXABLE_WEIGHT_MANAGER_HPP_

#include "../common/exception.hpp"
#include "../framework/mixable.hpp"
#include "../fv_converter/weight_manager.hpp"

namespace jubatus {
namespace server {

class mixable_weight_manager
    : public framework::mixable<fv_converter::weight_manager,
                                fv_converter::keyword_weights> {
 public:
  fv_converter::keyword_weights get_diff_impl() const;
  void put_diff_impl(const fv_converter::keyword_weights& diff);
  void mix_impl(const fv_converter::keyword_weights& lhs,
                const fv_converter::keyword_weights& rhs,
                fv_converter::keyword_weights& mixed) const;

  std::string get_pull_argument_impl() const;
  fv_converter::keyword_weights pull_impl(const std::string&) const;
  void push_impl(const fv_converter::keyword_weights& v);
  
  void clear();
};

}
}

#endif  // JUBATUS_SERVER_MIXABLE_WEIGHT_MANAGER_HPP_
