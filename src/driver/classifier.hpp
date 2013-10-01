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

#ifndef JUBATUS_DRIVER_CLASSIFIER_HPP_
#define JUBATUS_DRIVER_CLASSIFIER_HPP_

#include <string>
#include <utility>
#include <vector>
#include <pficommon/lang/shared_ptr.h>
#include "../classifier/classifier_base.hpp"
#include "../common/shared_ptr.hpp"
#include "../framework/mixable.hpp"
#include "../framework/mixer/mixer.hpp"
#include "../framework/server_base.hpp"
#include "diffv.hpp"
#include "linear_function_mixer.hpp"
#include "mixable_weight_manager.hpp"

namespace jubatus {
namespace driver {

class classifier {
 public:
  // TODO(suma): where is the owner of model, mixer, and converter?
  classifier(
     storage::storage_base* model_storage,
     jubatus::classifier::classifier_base* classifier_method,
     pfi::lang::shared_ptr<framework::mixer::mixer> mixer,
     pfi::lang::shared_ptr<fv_converter::datum_to_fv_converter> converter);
  virtual ~classifier();

  // TODO(suma): where is the owner of mixer and holder
  framework::mixer::mixer* get_mixer() const {
    return mixer_.get();
  }

  pfi::lang::shared_ptr<framework::mixable_holder> get_mixable_holder() const {
    return mixable_holder_;
  }

  storage::storage_base* get_model() const {
    return mixable_classifier_model_.get_model().get();
  }

  void train(const std::pair<std::string, fv_converter::datum>& data);
  classify_result classify(const fv_converter::datum& data) const;

 private:
  pfi::lang::shared_ptr<framework::mixer::mixer> mixer_;
  pfi::lang::shared_ptr<framework::mixable_holder> mixable_holder_;

  pfi::lang::shared_ptr<fv_converter::datum_to_fv_converter> converter_;
  pfi::lang::shared_ptr<jubatus::classifier::classifier_base> classifier_;
  linear_function_mixer mixable_classifier_model_;
  mixable_weight_manager wm_;
};

}  // namespace driver
}  // namespace jubatus

#endif  // JUBATUS_DRIVER_CLASSIFIER_HPP_
