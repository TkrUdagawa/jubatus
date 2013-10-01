// This file is auto-generated from cluster_analysis.idl
// *** DO NOT EDIT ***

#ifndef JUBATUS_SERVER_CLUSTER_ANALYSIS_CLIENT_HPP_
#define JUBATUS_SERVER_CLUSTER_ANALYSIS_CLIENT_HPP_

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <jubatus/msgpack/rpc/client.h>
#include "cluster_analysis_types.hpp"

namespace jubatus {
namespace client {

class cluster_analysis {
 public:
  cluster_analysis(const std::string& host, uint64_t port, double timeout_sec)
      : c_(host, port) {
    c_.set_timeout(timeout_sec);
  }
  
  std::string get_config(std::string name) {
    msgpack::rpc::future f = c_.call("get_config", name);
    return f.get<std::string>();
  }
  
  bool add_snapshot(std::string name, std::string clustering_name) {
    msgpack::rpc::future f = c_.call("add_snapshot", name, clustering_name);
    return f.get<bool>();
  }
  
  std::vector<change_graph> get_history(std::string name) {
    msgpack::rpc::future f = c_.call("get_history", name);
    return f.get<std::vector<change_graph> >();
  }
  
  std::vector<clustering_snapshot> get_snapshots(std::string name) {
    msgpack::rpc::future f = c_.call("get_snapshots", name);
    return f.get<std::vector<clustering_snapshot> >();
  }

  msgpack::rpc::client& get_client() {
    return c_;
  }

 private:
  msgpack::rpc::client c_;
};

}  // namespace client
}  // namespace jubatus

#endif  // JUBATUS_SERVER_CLUSTER_ANALYSIS_CLIENT_HPP_
