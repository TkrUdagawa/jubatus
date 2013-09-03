// This file is auto-generated from recommender.idl
// *** DO NOT EDIT ***

#ifndef JUBATUS_CLIENT_RECOMMENDER_CLIENT_HPP_
#define JUBATUS_CLIENT_RECOMMENDER_CLIENT_HPP_

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <jubatus/msgpack/rpc/client.h>
#include "datum.hpp"
#include "recommender_types.hpp"

namespace jubatus {
namespace recommender {
namespace client {

class recommender {
 public:
  recommender(const std::string& host, uint64_t port, double timeout_sec)
      : c_(host, port) {
    c_.set_timeout(timeout_sec);
  }

  std::string get_config(const std::string& name) {
    msgpack::rpc::future f = c_.call("get_config", name);
    return f.get<std::string>();
  }

  bool clear_row(const std::string& name, const std::string& id) {
    msgpack::rpc::future f = c_.call("clear_row", name, id);
    return f.get<bool>();
  }

  bool update_row(const std::string& name, const std::string& id,
       jubatus::common::datum row) {
    msgpack::rpc::future f = c_.call("update_row", name, id, row);
    return f.get<bool>();
  }

  bool clear(const std::string& name) {
    msgpack::rpc::future f = c_.call("clear", name);
    return f.get<bool>();
  }

  jubatus::common::datum complete_row_from_id(const std::string& name,
       const std::string& id) {
    msgpack::rpc::future f = c_.call("complete_row_from_id", name, id);
    return f.get<jubatus::common::datum>();
  }

  jubatus::common::datum complete_row_from_datum(const std::string& name,
       jubatus::common::datum row) {
    msgpack::rpc::future f = c_.call("complete_row_from_datum", name, row);
    return f.get<jubatus::common::datum>();
  }

  similar_result similar_row_from_id(const std::string& name,
       const std::string& id, uint32_t size) {
    msgpack::rpc::future f = c_.call("similar_row_from_id", name, id, size);
    return f.get<similar_result>();
  }

  similar_result similar_row_from_datum(const std::string& name,
       jubatus::common::datum row, uint32_t size) {
    msgpack::rpc::future f = c_.call("similar_row_from_datum", name, row, size);
    return f.get<similar_result>();
  }

  jubatus::common::datum decode_row(const std::string& name,
       const std::string& id) {
    msgpack::rpc::future f = c_.call("decode_row", name, id);
    return f.get<jubatus::common::datum>();
  }

  std::vector<std::string> get_all_rows(const std::string& name) {
    msgpack::rpc::future f = c_.call("get_all_rows", name);
    return f.get<std::vector<std::string> >();
  }

  float calc_similarity(const std::string& name, jubatus::common::datum lhs,
       jubatus::common::datum rhs) {
    msgpack::rpc::future f = c_.call("calc_similarity", name, lhs, rhs);
    return f.get<float>();
  }

  float calc_l2norm(const std::string& name, jubatus::common::datum row) {
    msgpack::rpc::future f = c_.call("calc_l2norm", name, row);
    return f.get<float>();
  }

  bool save(const std::string& name, const std::string& id) {
    msgpack::rpc::future f = c_.call("save", name, id);
    return f.get<bool>();
  }

  bool load(const std::string& name, const std::string& id) {
    msgpack::rpc::future f = c_.call("load", name, id);
    return f.get<bool>();
  }

  std::map<std::string, std::map<std::string, std::string> > get_status(
      const std::string& name) {
    msgpack::rpc::future f = c_.call("get_status", name);
    return f.get<std::map<std::string, std::map<std::string, std::string> > >();
  }

  msgpack::rpc::client& get_client() {
    return c_;
  }

 private:
  msgpack::rpc::client c_;
};

}  // namespace client
}  // namespace recommender
}  // namespace jubatus

#endif  // JUBATUS_CLIENT_RECOMMENDER_CLIENT_HPP_
