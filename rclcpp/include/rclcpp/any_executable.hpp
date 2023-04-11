// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RCLCPP__ANY_EXECUTABLE_HPP_
#define RCLCPP__ANY_EXECUTABLE_HPP_

#include <memory>

#include "rclcpp/callback_group.hpp"
#include "rclcpp/client.hpp"
#include "rclcpp/macros.hpp"
#include "rclcpp/node_interfaces/node_base_interface.hpp"
#include "rclcpp/service.hpp"
#include "rclcpp/subscription.hpp"
#include "rclcpp/timer.hpp"
#include "rclcpp/visibility_control.hpp"
#include "rclcpp/waitable.hpp"

namespace rclcpp
{

struct AnyExecutable
{
  RCLCPP_PUBLIC
  AnyExecutable();

  RCLCPP_PUBLIC
  AnyExecutable(
      const rclcpp::SubscriptionBase::SharedPtr & subscription,
      const rclcpp::CallbackGroup::SharedPtr & callback_group);

  RCLCPP_PUBLIC
  AnyExecutable(
      const rclcpp::TimerBase::SharedPtr & timer,
      const rclcpp::CallbackGroup::SharedPtr & callback_group);

  RCLCPP_PUBLIC
  AnyExecutable(
      const rclcpp::ServiceBase::SharedPtr & service,
      const rclcpp::CallbackGroup::SharedPtr & callback_group);

  RCLCPP_PUBLIC
  AnyExecutable(
      const rclcpp::ClientBase::SharedPtr & client,
      const rclcpp::CallbackGroup::SharedPtr & callback_group);

  RCLCPP_PUBLIC
  AnyExecutable(
      const rclcpp::Waitable::SharedPtr & waitable,
      const rclcpp::CallbackGroup::SharedPtr & callback_group,
      const std::shared_ptr<void> & data);


  RCLCPP_PUBLIC
  virtual ~AnyExecutable();

  // Only one of the following pointers will be set.
  rclcpp::SubscriptionBase::SharedPtr subscription = nullptr;
  rclcpp::TimerBase::SharedPtr timer = nullptr;
  rclcpp::ServiceBase::SharedPtr service = nullptr;
  rclcpp::ClientBase::SharedPtr client = nullptr;
  rclcpp::Waitable::SharedPtr waitable = nullptr;
  // These are used to keep the scope on the containing items
  rclcpp::CallbackGroup::SharedPtr callback_group = nullptr;
  rclcpp::node_interfaces::NodeBaseInterface::SharedPtr node_base = nullptr;
  std::shared_ptr<void> data = nullptr;
};

}  // namespace rclcpp

#endif  // RCLCPP__ANY_EXECUTABLE_HPP_
